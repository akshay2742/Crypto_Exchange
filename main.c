#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include"email_validate.h"
#include"dateofbirth_validate.h"
#include"password_validate.h"
#include"banking.h"
#include"buy_sell.h"

int check_contact_no(long int number)
{
    int count=0;
    while(number>0)
    {
        number/=10;
        count++;
    }

    return count;
}

int main()
{
  double bitcoin = 3732701.48;
  double ethereum = 303085.83;
  double Polygon = 197.13;          //coin rates
  double Dogecoin = 13.59;
  double Litecoin = 11880.49;

  int n;
  char ch;
  double temp;
  float bal;
  double count;  //used for selecting coin
  int temp1=0; //used for checking 1);
  char temp2; //used for checking 2);
  int D_choice; //used for selecting Dashboard options;
  char LS_choice;
  int wal_choice; //used for selecting login or Signup;
  int day,month,year;
  struct Login L1;
  struct Signup S1;
  struct account acc;
  struct wallet wal={0.00,0.00,0};
  struct crypto_record record={0.0000,0,0.0000,0.0000,0.0000};
  long int delete_passcheck;

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
        while(!search(L1))
        {
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
        }
        struct Signup sign;
        FILE *fp=fopen("filedata.txt","r");

        while(fread(&sign,sizeof(Signup),1,fp))
      {
        int email_check = strcmp(sign.email,L1.email_login);
        int pass_check = strcmp(sign.create_password,L1.password_login);

      if(email_check==0 && pass_check==0)
        {
         
          
         L1.random1=sign.random;
          break;
        }
       else
       {
         
         continue;
       }
     }  
      record.unique_id=L1.random1;  
        printf("\nWelcome to the DashBoard\n\n");
          
        temp1=1;
        
        break;

      case 'N':

        printf("\nWelcome to SignUp Page of CRYPTO EXCHANGE\n");
        printf("\n\t**********************************************\t\n\n");
        printf("Enter your name: ");
        fflush(stdin);
        scanf("%s",S1.name);

        printf("\nEnter your Email Address: ");
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
        scanf("%ld",&S1.contact_no);
        while(check_contact_no(S1.contact_no)<10)
        {
          printf("\nError! Please enter a 10 digit number.\n\n");
          printf("\nEnter your Contact No: ");
          scanf("%ld",&S1.contact_no);
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

        printf("\nEnter your DOB in format (day/month/year): ");
        fflush(stdin);
        scanf("%d/%d/%d",&S1.day,&S1.month,&S1.year);
               
        while((datevalid(S1.day, S1.month, S1.year)!=1))
        {
          printf("\nInvalid Date, Enter again in format (day/month/year): ");
          fflush(stdin);
          scanf("%d/%d/%d",&S1.day,&S1.month,&S1.year);
        }
                 
        printf("\nEnter the Password you want to create: \n 1. password should contain atleast one capital letter\n 2. should have one digit from o-9\n 3. atleast one special charecter- $,*,#,& ,@ \n 4. length should be atleast 6\n");
        fflush(stdin);
        scanf("%s",S1.create_password);
        while(!(check(S1.create_password)))
        {
          printf("\nError ! Enter a valid Password again as per the format\n");
          fflush(stdin);
          scanf("%s",S1.create_password);
        }
        printf("\n\nEnter the unique id for your account: ");
        scanf("%d",&S1.random);
        
        create(S1);
            
        system("clear");
        display();
        printf("Welcome to the Dashboard %s\n",S1.name);   
        printf("\nYour Unique ID is: %d\n",S1.random);
        temp1=1;
        record.unique_id=S1.random;
        break;

        default:
          
          printf("\nError ! You entered wrong choice please enter a correct value\n\n");

          printf("If you have a account already press Y for Login otherwise N for SignUp: ");
          fflush(stdin);
          LS_choice=getchar();
          scanf("%c",&LS_choice);
          temp1=0;
          break;
        }
      }
  do
  {
    printf("\n\t**********************************************\t\n");
    printf("\n\n1. Add your bank details\n");
    printf("2. Delete your bank details\n");
    printf("3. Update your bank details\n");
    printf("4. Perform Wallet Operations \n");
    printf("5. Buy Coins \n");
    printf("6. Sell Coins \n");
    printf("7. Display Coin rates \n");
    printf("8. Visit your Portfolio \n\n");
        
    printf("Enter your choice for dashboard operation: ");
    scanf("%d",&D_choice);
    printf("\n\t**********************************************\t\n");
    switch(D_choice)
    {

      case 1:

        printf("\nEnter name of the bank owner: ");
        scanf("%s",acc.name);
        printf("\nEnter the bank name: ");
        scanf("%s",acc.bankname);
        printf("\nEnter the account number: ");
        scanf("%ld",&acc.acc_no);
        printf("\nEnter the IFSC code: ");
        scanf("%s",acc.ifsc);
        printf("\nEnter the contact no.: ");
        scanf("%ld",&acc.contact_no);
        acc.random=S1.random;
        add_account(acc);
        display_account_rec();  
        break;

      case 2:

        deleteaccount();
        display_account_rec();
        break;

      case 3:

        update_account(L1);  
        display_account_rec();
        break;

      case 4:
              
        printf("\n\t**********************************************\t\n");
        printf("\t\tWELCOME TO WALLET PAGE\n");
        printf("\n1. Check Current Balance");
        printf("\n2. Deposit Money to wallet");
        printf("\n3. Withdraw money\n");
        printf("\n Enter your choice: ");
        scanf("%d",&wal_choice);
        wal.random=S1.random;
        printf("\n\t**********************************************\t\n");
        switch(wal_choice)
        {
          case 1: 
            
            show_current_balance();
            break;

          case 2:
            printf("Enter the amount to add to wallet: ");
            scanf("%f",&wal.money_amount);
            create_wallet(wal);
            deposit_amount(wal);
            break;

          case 3:
            printf("Enter the amount to withdraw from wallet: ");
            scanf("%f",&wal.money_amount);
            withdraw_amount(wal);
            break;

          default:
            printf("\nINVALID INPUT !!");
            break;
        }
        break;

      case 5:
        do{  
        printf("\n1. BITCOIN\n");
        printf("\n2. ETHEREUM\n");
        printf("\n3. POLYGON\n");
        printf("\n4. DOGECOIN\n");
        printf("\n5. LITECOIN\n");
        scanf("%d",&n);
        
        
        switch(n)
        {
          case 1:
          printf("\n Enter number of Bitcoin you want to purchase: ");
          scanf("%lf",&count);
          record.Bitcoin+=count;
          temp=bitcoin;
          break;

          case 2:
          printf("\n Enter number of Ethereum you want to purchase: ");
          scanf("%lf",&count);
          record.Ethereum+=count;
          temp=ethereum;
          break;

          case 3:
          printf("\n Enter number of Polygon you want to purchase: ");
          scanf("%lf",&count);
          record.Polygon+=count;
          temp=Polygon;
          break;

          case 4:
          printf("\n Enter number of Dogecoin you want to purchase: ");
          scanf("%lf",&count);
          record.Dogecoin+=count;
          temp=Dogecoin;
          break;

          case 5:
          printf("\n Enter number of Litecoin you want to purchase: ");
          scanf("%lf",&count);
          record.Litecoin+=count;
          temp=Litecoin;
          break;

        }
          add_crypto_record(record);
          buy_crypto(temp,wal,count);
          printf("\n\nIf you want to purchase more coins press Y otherwise press N");
          ch=getchar();
          scanf("%c",&ch);
        }while(ch=='Y');
        break;

      case 6:
        
        do
        {
          printf("\n1. BITCOIN\n");
          printf("\n2. ETHEREUM\n");
          printf("\n3. POLYGON\n");
          printf("\n4. DOGECOIN\n");
          printf("\n5. LITECOIN\n");
          scanf("%d",&n);
          switch(n)
          {
            case 1:
            printf("\n Enter number of Bitcoin you want to sell: ");
            scanf("%lf",&count);
            record.Bitcoin-=count;
            temp=bitcoin;
            break;

            case 2:
            printf("\n Enter number of Ethereum you want to sell: ");
            scanf("%lf",&count);
            record.Ethereum-=count;
            temp=ethereum;
            break;

            case 3:
            printf("\n Enter number of Polygon you want to sell: ");
            scanf("%lf",&count);
            record.Polygon-=count;
            temp=Polygon;
            break;

            case 4:
            printf("\n Enter number of Dogecoin you want to sell: ");
            scanf("%lf",&count);
            record.Dogecoin-=count;
            temp=Dogecoin;
            break;

            case 5:
            printf("\n Enter number of Litecoin you want to sell: ");
            scanf("%lf",&count);
            record.Litecoin-=count;
            temp=Litecoin;
            break;

          }
        add_crypto_record(record);
        sell_crypto(temp,wal,count);
        printf("\n\nIf you want to purchase more coins press Y otherwise press N");
        ch=getchar();
        }while(ch=='Y');
        break;

      case 7:
        break;

      case 8:
        portfolio();
        break;

    }
    printf("\nIf you want to access the Dashboard again press 'Y' otherwise press 'N': ");
    temp2=getchar();
    scanf("%c",&temp2);
  }while(temp2=='Y');
}
