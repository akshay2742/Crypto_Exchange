#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"email_validate.h"

struct Login
{
      char email_login[50];
      char password_login[50];
};

struct Signup
{
    char name[20];
    char email[50];
    int contact_no;
    char Gender;
    char DOB[15];
    char create_password[50];

};

int check_contact_no(int number)
{
    int count=0;
    while(number!=0)
    {
        number/=10;
        count++;
    }

    return count+1;
}


int main()
{
      int temp1=0; //used for checking 1);
      char LS_choice;
      struct Login L1;
      struct Signup S1;
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
                printf("\nWelcome to the DashBoard\n");
                temp1=1;
                break;

              case 'N':

                printf("\nWelcome to SignUp Page of CRYPTO EXCHANGE\n");
                printf("Enter your name: ");
                fflush(stdin);
                scanf("%s",S1.name);
                printf("\nEnter your Email: ");
                fflush(stdin);
                scanf("%s",S1.email);
                while (!email_validate(S1.email))
                {
                  printf("\nError ! Enter a valid Email Address again.\n");
                  fflush(stdin);
                  printf("Enter the Email Address: ");
                  scanf("%s",S1.email);
                }
                printf("\nEnter your Contact No: ");
                scanf("%d",&S1.contact_no);
                while(check_contact_no(S1.contact_no)<10)
                {
                    printf("\nError! Please enter a 10 digit number.\n\n");
                    printf("\nEnter your Contact No: ");
                    scanf("%d",&S1.contact_no);
                }
                printf("\nEnter your gender (MALE: M or FEMALE: F): ");
                fflush(stdin);
                S1.Gender=getchar();
                scanf("%c",&S1.Gender);
                while(!(S1.Gender=='M' || S1.Gender=='F' || S1.Gender=='m' || S1.Gender=='f'))
                {
                  printf("\nError! You entered a wrong value\n\n");
                  printf("\nEnter your gender (MALE: M or FEMALE: F): ");
                  fflush(stdin);
                  S1.Gender=getchar();
                  scanf("%c",&S1.Gender);
                }
                printf("\nEnter your DOB: ");
                fflush(stdin);
                scanf("%s",S1.DOB);
                printf("\nEnter the Password you want to create: ");
                fflush(stdin);
                scanf("%s",S1.create_password);
                system("clear");
                printf("\nWelcome to the DashBoard %s\n",S1.name);
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
