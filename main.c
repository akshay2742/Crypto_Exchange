#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool email_validate(char email[]){
    int At = -1, Dot = -1;
    int string_length(char email[])
    {
        int i, count=0;
        for (i = 0; email[i]!='\0'; i++)
        {
            count++;
        }
        return count;
    }
    bool isChar(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
    bool isDigit(const char c)
    {
        return (c >= '0' && c <= '9');
    }
    if (!isChar(email[0])) {
        return 0;
    }
    
  
    for (int i = 0;i<string_length(email);i++) {
        if (email[i] == '@') {
  
            At = i;
        }
        else if (email[i] == '.') {
  
            Dot = i;
        }
    }
  
    if (At == -1 || Dot == -1)
        return 0;
  
    if (At > Dot)
        return 0;
  
    return !(Dot >= (string_length(email) - 1));
}


int main(){
    char LS_choice, email_login[50], password_login[50];
    int temp1=0;

    printf("Welcome to the CRYPTO EXCHANGE\n\n");
    printf("If you have a account already press Y for Login otherwise N for SignUp: ");
    fflush(stdin);
    scanf("%c",&LS_choice);
    system("cls");
    switch (LS_choice)
    {
    case 'Y':
        printf("\nWelcome to Login Page of CRYPTO EXCHANGE\n");
        printf("Enter the Email Address: ");
        fflush(stdin);
        
        scanf("%s",email_login);
        while (!email_validate(email_login))
        {
            printf("\nError ! Enter a valid Email Address again.\n");
            fflush(stdin);
            printf("Enter the Email Address: ");
            scanf("%s",email_login);
        }
        printf("\nEnter the Password: ");
        scanf("%s",password_login);
        system("cls");
        printf("\n\nWelcome to the Dashboard of the Crypto Exchange");
        break;
    
    case 'N':

        break;

    default:
        printf("Error ! You entered wrong choice please enter a correct value");
        //temp1=0
        break;
    }
}