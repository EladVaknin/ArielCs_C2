#include <stdio.h>
#include "myBank.h"
double bankAccount [50][2];
int count=1;
int open = 1, close = 0;

void O ()
{
    double money;
    if (count<=50)
        {
            bankAccount[count][0] = open;
            printf("Please enter amount for deposit: ");
            scanf("%lf", &money);
            bankAccount[count][1] = money;
            printf("New account number is: %d \n", count+900);
            count++;
        }
    else 
        {
        printf("there is no account available \n");
        }
        while(getchar()!='\n');
}

void B ()
{
    int account;
    printf("Please enter account number: ");
    scanf("%d", &account);
    if(bankAccount[account-900][0]==open)
    {
        printf("The balance of account number %d is: %.2f \n",account, bankAccount[account-900][1]);
    }
    else
    {
        printf("This account is closed\n");
    }
    while(getchar()!='\n');
}

void D ()
{
    int account;
    double money;
    printf("Please enter your number account \n");
    scanf("%d", &account);
   if (bankAccount[account-900][0]==open)
   {
       printf("Please enter amount for deposit:\n");
       scanf("%lf", &money);
       if (money<=0)
       {
           printf("Failed to read the amount");
       }
       bankAccount[account-900][1] += money; 
       printf("your sum is %.2f \n", bankAccount[account-900][1]);
   }
   else
   {
    printf("your number account doen't exist \n");
   }
   while(getchar()!='\n');
}

void W()
{
    int account;
    double money;
    printf("Please enter account number: ");
    scanf("%d", &account);
   if (bankAccount[account-900][0]==open)
   {
       printf("Please enter the amount to withdraw: ");
       scanf("%lf", &money);
       if (money<=0)
       {
           printf("Invalid amount");
       }
       if (bankAccount[account-900][1]-money>=0)
       {
       bankAccount[account-900][1] -= money; 
       printf("The new balance is: %.2f ", bankAccount[account-900][1]);
       }
       else
       {
           printf("Cannot withdraw more than the balance\n");
       }
   }
   else
   {
    printf("your number account doen't exist \n");
   }
   while(getchar()!='\n');
}

void C()
{
    int account;
    printf("Please enter account number: ");
    scanf("%d", &account);
    if (bankAccount[account-900][0]==open)
   {
       bankAccount[account-900][0] = close;
       printf("your account number %d was closed\n", account);
   }
   else
   {
       printf("This account is already closed \n");
   }
    while(getchar()!='\n'); 
}

void I()
{
    double interest;
    printf("Please enter interest rate: ");
    scanf("%lf",&interest);
    for(int i=1; i<=50; i++)
    {
        if (bankAccount[i][0]==open)
        {
            bankAccount[i][1] = bankAccount[i][1] + bankAccount[i][1] *(interest/100);
            //printf ("after the interest you have %d dollars in your account number %d \n",bankAccount[i][1],i+900 );
        }
    }
    while(getchar()!='\n');
}

void P ()
{
    for(int i=1; i<=50; i++)
    {
        if(bankAccount[i][0]==open)
        {
            double x = (double)bankAccount[i][1];
            printf("The balance of account number %d is %.2lf \n", i+900, x);
        }
    }
    while(getchar()!='\n');
}

void E()
{
    for(int i=1; i<=50; i++)
    {
        bankAccount[i][0]==close;
    }
    while(getchar()!='\n');
}