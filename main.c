#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"email_validate.h"

struct Login
{
      char email_login[50];
      char password_login[50];
};

int main()
{
      int temp1=0; //used for checking 1);
      char LS_choice;
      struct Login L1;
      printf("Welcome to the CRYPTO EXCHANGE\n\n");
      printf("If you have a account already press Y for Login otherwise N for SignUp: "); //1)
      fflush(stdin);
      scanf("%c",&LS_choice);
      while(temp1==0)
      {
        switch (LS_choice)
        {
              case 'Y':
                printf("\nWelcome to Login Page of CRYPTO EXCHANGE\n");
                printf("Enter the Email Address: ");
                fflush(stdin);
                scanf("%s",L1.email_login);
                while (!email_validate(L1.email_login))
                {
                  printf("\nError ! Enter a valid Email Address again.\n");
                  fflush(stdin);
                  printf("Enter the Email Address: ");
                  scanf("%s",L1.email_login);
                }
                printf("\nEnter the Password: ");
                fflush(stdin);
                scanf("%s",L1.password_login);
                system("clear");
                printf("\n\nWelcome to the Dashboard of the Crypto Exchange");
                temp1=1;
                break;

              case 'N':
                temp1=1;
                break;

              default:
                printf("Error ! You entered wrong choice please enter a correct value\n\n");
                printf("If you have a account already press Y for Login otherwise N for SignUp: ");
                fflush(stdin);
                LS_choice=getchar();
                scanf("%c",&LS_choice);
                temp1=0;
                break;
        }
      }
}
