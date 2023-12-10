
#include "func.h"

#define SIZE 50


int main(){
    BankAccount accounts[SIZE];
    int numAccounts = 0;
    char input[100];
    int choice;
    int choiceGame;
    char username[SIZE];
    char password[SIZE];
    int loggedIn = -1; // If the user is currently logged #includ
    bool logOut = false;

    while(logOut == false){
        printf("\n%s1. Create Account\n2. Login%s\n3. Exit%s\n", RESET,RESET,RESET);
        printf("Enter your choice: %s", RESET);

        fgets(input, sizeof(input), stdin);

        if (input[0] == '\n' || (input[0] == '\0' && input[1] == '\n')) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            continue; // Restart the loop
        }
        else if (sscanf(input, "%d", &choice) != 1 || choice <= 0  || choice > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue; // Restart the loop
        }

        switch(choice){
            case 1:
                BankAccount newAccount = createAccount();
                if (!isUsernameTaken(newAccount.username, accounts, numAccounts)) {
                    if(ValidationAcc(newAccount.username, newAccount.password, accounts)){
                        if (numAccounts < SIZE) {
                            accounts[numAccounts] = newAccount;
                            numAccounts++;
                            printf("Account created successfully!\n");
                        } else {
                            printf("Maximum number of accounts reached!\n");
                        }
                    }
                } else {
                    printf("The username has already been taken.\n");
                }

                break;
            case 2:
                printf("Username: ");
                scanf("%s", username);
                while(getchar() != '\n');
                printf("Password: ");
                scanf("%s", password);
                while(getchar() != '\n');
                loggedIn = login(accounts, numAccounts, username, password);
                if(loggedIn != -1){
                    printf("Login successful!\n");
                    logOut = true;
                }
                else{
                    printf("Login failed. Please check your username and password.\n");
                }
                break;
            case 3:
                printf("Exit\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if(loggedIn != -1){
            while(logOut == true){
                printf("\n1. Balance\n2. Transfer\n3. Work\n4. History\n5. Online\n6. Log out\n");
                printf("Pick one: ");
                fgets(input, sizeof(input), stdin);

                if (input[0] == '\n' || (input[0] == '\0' && input[1] == '\n')) {
                    printf("Invalid choice. Please enter 1, 2, 4, 5 or 6.\n");
                    continue; // Restart the loop
                }
                else if (sscanf(input, "%d", &choiceGame) != 1 || choiceGame <= 0  || choiceGame > 6) {
                    printf("Invalid choice. Please enter 1, 2, 3, 4, 5, or 6\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    continue; // Restart the loop
                }
                switch (choiceGame) {
                    case 1:
                        balance(&accounts[loggedIn]);
                        break;
                    case 2:
                        char receiverUsername[SIZE];
                        printf("Enter recipient's username: ");
                        scanf("%s", receiverUsername);

                        int receiverIndex = -1;

                        for(int i = 0; i<numAccounts;i++){
                            if(strcmp(accounts[i].username, receiverUsername) == 0){
                                receiverIndex = i;
                            }}
                        if(receiverIndex != -1){
                            double amount;
                            printf("Enter amount to transfer: ");
                            scanf("%lf", &amount);
                            while(getchar() != '\n');
                            transfer(&accounts[loggedIn], &accounts[receiverIndex], amount);
                        }

                        else{
                            printf("Recipient not found!\n");
                        }
                        break;
                    case 3:
                        work(&accounts[loggedIn]);
                        break;
                    case 4:
                        display_records(&accounts[loggedIn]);
                        break;
                    case 5:
                        online_users(accounts,numAccounts);
                        break;
                    case 6:
                        printf("You have logged out");
                        logOut = false;
                        break;
                    default:
                        printf("Invalid choice.Please try again.");
                        break;
                }
            }
        }
    }
}


