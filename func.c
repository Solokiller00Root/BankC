

#include "func.h"


int isUsernameTaken(char *username,BankAccount* accounts, int numAccounts ){
    for(int i = 0; i < numAccounts; i++){
        if(strcmp(accounts[i].username, username) == 0){
            return 1;
        }
    }
    return 0;
}

int ValidationAcc(char* username, char* password, BankAccount* account){
    int username_length = strlen(username);
    int password_lenth = strlen(password);
    if(username_length < USERNAME_MIN){
        printf("\n%sYour username must be at least 6 characters! ", RED);
        return 0;
    }
    else if(password_lenth < PASSWORD_MIN){
        printf("\n%sYour password must be at least 6 characters! ", RED);
        return 0;
    }
    else if (username_length > USERNAME_MAX){
        printf("\n%sYour username cant be more than 20 characters! ", RED);
        return 0;
    }
    else if (password_lenth > PASSWORD_MAX){
        printf("\n%sYour password cant be more than 20 characters! ", RED );
        return 0;
    }
    return 1;
}

BankAccount createAccount(){
    BankAccount newAccount;

    printf("Username: %s", RESET);
    scanf("%s", newAccount.username);
    while(getchar() != '\n');
    printf("Password: %s", RESET);
    scanf("%s", newAccount.password);
    while(getchar() != '\n');
    newAccount.balance = 2.0;
    newAccount.num_transactions= 0;

    return newAccount;
}
int login(BankAccount* accounts, int numAccounts, char* username, char* password){
    for(int i = 0; i < numAccounts; i++){
        if(strcmp(accounts[i].username, username) == 0 &&
                strcmp(accounts[i].password, password) == 0){
            return i;
        }
    }

    return -1;
}


void balance(BankAccount* account){

    printf("Your balance is: %.2f\n", account->balance);
}


void transfer(BankAccount* sender,BankAccount* receiver, double amount) {
    if(strcmp(sender->username, receiver->username) == 0){
        printf("You cant send money to yourself!");
    }
    else if (amount <= sender->balance) {
        sender->balance -= amount;
        rec_transaction(sender,amount);
        receiver->balance += amount;
        printf("Transferred %.2f to %s. Your new balance is: %.2f\n", amount,
                receiver->username, sender->balance);
        printf("%s's new balance is: %.2f\n", receiver->username,
                receiver->balance);
    }
    else {
        printf("Insufficient funds!\n");
    }
}

void work(BankAccount* account){
    srand(time(NULL));
    double work = (double)(rand() % 101);
    account->balance += work;
    rec_transaction(account,work);
    printf("You got %.2f from working. Your new balance is: %.2f\n",
            work, account->balance);
}

void rec_transaction(BankAccount* account, double amount){
    if (account->num_transactions < 100){
        account->transactions[account->num_transactions++] = amount;
    }
    else{
        printf("The history is full");
    }
}

void display_records(BankAccount* account) {
    printf("You have %d transactions in total: \n", account->num_transactions);
    for (int i = 0; i < account->num_transactions; i++) {
        printf("Transaction %d: %.2f\n", i + 1, account->transactions[i]);
    }
}

void online_users(BankAccount* accounts, int numAccounts) {
    printf("The accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("\n");
        printf("%s\n", accounts[i].username);
        printf("\n");
    }
}

