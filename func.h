


#ifndef FUNC
#define FUNC
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define SIZE 50
#define USERNAME_MIN 6
#define USERNAME_MAX 20
#define PASSWORD_MIN 6
#define PASSWORD_MAX 20


typedef struct{
    char username[SIZE];
    char password[SIZE];
    double balance;
    double transactions[100];
    int num_transactions;
} BankAccount;


void red();
int isUsernameTaken(char *username,BankAccount* accounts, int numAccounts );
int ValidationAcc(char* username, char* password, BankAccount* account);
BankAccount createAccount();
int login(BankAccount* accounts, int numAccounts, char* username, char* password);
void balance(BankAccount* account);
void transfer(BankAccount* sender,BankAccount* receiver, double amount);
void work(BankAccount* account);
void rec_transaction(BankAccount* account, double amount);
void display_records(BankAccount* account);
void online_users(BankAccount* accounts, int numAccount);



#endif




