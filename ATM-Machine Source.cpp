//ATM Software
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//Declared Variables
char userInput;                 //Users Input in the Main Loop
char tranxType[4][25];           //Array to Capture the Type of Transaction

float tranxAmount[4];           //Array to Capture the Transaction Amount
float userBalance = 150.00f;    //The current users money balance amount
float new;
int i;                          //For Loop Statement
int pin;                        //Users PIN
int userTransactions = 0;       //Transaction Amount to keep user from going over 5 Transactions

bool isPinCorrect = false;
bool isUserInputCorrect = false;
bool exitSoftware = false;

int main(){
   
    //Declared Functions
    void CheckBalance(void);
    void Deposit(void);
    void Withdraw(void);
    void TransHistory(void);
    void Exit(void);
   
    //*********PIN_LOOP***************
    do{
        //Start of Software
        printf("Please input your 4-Digit Numerical Pin: "); //Outputs Info
        scanf("%d", &pin); //User Inputs Pin Data
       
        //Pin Check Switch Statement
        switch(pin){
            case 1234:
            printf("Welcome to BDZ Banking!\n");
            isPinCorrect = true;
            break;
           
            default:
            printf("Your pin is Incorrect\n");
            break;
        }
    }while(!isPinCorrect);
   
   
    //*********MAIN_LOOP**********
    while (!exitSoftware) {
        printf("\nPlease Choose an Option! \n");
        printf( "A. Check Current Balance\nB. Deposit Amount\nC. Withdraw Amount\nD. Transaction History\nE. Exit\n");

        scanf("%s", &userInput);
        switch (userInput)
        {
            case 'A':
            CheckBalance();
                break;
           
            case 'B':
            Deposit();
                break;
           
            case 'C':
            Withdraw();
                break;
           
            case 'D':
            TransHistory();
                break;
               
            case 'E':
            Exit();
                break;
           
            default:
            printf("Incorrect Option try again!\n\n");
                break;
        }
    }

    return 0;
}

void CheckBalance(void){
    printf("Your current balance is %.2f \n", userBalance);
}

void Deposit(void){
    if(userTransactions <= 4){
        printf("How much would you like to deposit?: ");
        scanf("%f", &new);
       
        userBalance += new;
       
        strcpy(tranxType[userTransactions],"Deposited");     //Captures the type of Transaction
        tranxAmount[userTransactions] = new;                //Captures the Transaction on the Array
       
        userTransactions++;
    }
    else
    {
        printf("You've reached your daily Transaction Limit!");
    }
}

void Withdraw(void){
    if(userBalance >= 20 && userTransactions <= 4){
        printf("You have withdrawn 20$\n");
       
        userBalance -= 20.00f;               //Removes the Withdrawn amount from the userbalance
        strcpy(tranxType[userTransactions],"Withdrew");
        tranxAmount[userTransactions] = 20;  //Captures the Transaction amount on the Array
       
        userTransactions++;
    }
    else if(userBalance < 20 && userTransactions <= 4)
    {
        printf("Insufficent Funds\n");
    }
    else
    {
        printf("You've reached your daily Transaction Limit!\n");
    }
   
}

void TransHistory(void){
    printf("**Transaction History**\n");
    for (i = userTransactions-1; i >= 0; i--) { //Checks against the current userTransactions
         printf("%s %.2f$ \n", tranxType[i], tranxAmount[i]);
    }
}

void Exit(void){
    printf("Thank you for Banking with BDZ, Goodbye!\n");
    exitSoftware = true;
}