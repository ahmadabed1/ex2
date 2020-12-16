#include <stdio.h>
#include "myBank.h"
#define accountnumbe 50
#define range 901
float accounts [2][accountnumbe] ={0};

void openAccount(float mony)
{
    int flag = 0;
    int i = 0;
    for (int i = 0; i < accountnumbe; i++)
    {
        if (flag == 0 && accounts[0][i] == 0)
        {
            printAll("the account number is: ",i+range);
            accounts[1][i] = mony;
            flag = 1;
        }
    }
    if (flag == 0)
        printf("there is no free account");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void isopen(int account_number)
{
    int flag = 0;
    if (accounts[0][account_number] == 0|| account_number-range<0 || account_number>accountnumbe-1-range)
    {
        flag = 1;
        printf("this account is not exist");
    }
    if (flag == 0)
    {
        float mony = accounts[1][account_number - range];
        printf("the amount of cash in the account:", mony);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void addmony(int account_number, float mony)
{

    int flag = 0;
    if (accounts[0][account_number] == 0 || account_number - range<0 || account_number>accountnumbe - 1 - range)
    {
        flag = 1;
        printf("this account is not exist");
    }
    if (flag == 0)
    {
        accounts[1][account_number - range] =  accounts[1][account_number - range]+mony;
        float mony = accounts[1][account_number - range];
        printf("the new amount of cash in the account:", mony);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  pull(int account_number, float mony)
{
    int flag = 0;
    if (accounts[0][account_number] == 0 || account_number - range<0 || account_number>accountnumbe - 1 - range)
    {
        flag = 1;
        printf("this account is not exist");
    }
    if (flag == 0)
    {
        accounts[1][account_number - range] = accounts[1][account_number - range] -1 mony;
        float mony = accounts[1][account_number - range];
        printf("the new amount of cash in the account:", mony);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void closeAccount(int account_number){
    int flag=0;
    if (accounts[0][account_number] == 0 || account_number - range<0 || account_number>accountnumbe - 1 - range)
    {
        flag = 1;
        printf("this account is not exist");
    }
    if (flag==0){
      accounts[1][account_number-range] = 0;
      accounts[0][account_number-range] = 0;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void addcommission(float x)
{
    int i = 0;
    for (i = 0; i < accountnumbe; i++)
    {
        if (accounts[0][i] = 1)
            accounts[1][i] = (accounts[1][i] * x) + accounts[1][i];
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printAll(){
  int i=0;
  int flag = 0;
  for (i = 0;i<accountnumbe;i++)
  {
    int account_number = i+range;
    if (accounts[0][i]==1){
      flag =1;
      printf("Account number: %d , balance = %.2f\n", (i + range), accounts[1][i]);
    }
  }
  if(flag==0){
      printf("The bank is empty\n");
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void exiting(){
  int i;
  for (i = 0;i<accountnumbe;i++){
    if (accounts[1][i]==1){
      closeAccount(i + range);
    }
  }
}
