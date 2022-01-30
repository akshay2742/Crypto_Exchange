#include"file_handling.h"

typedef struct account{
    char bankname[30];
    char ifsc[20];
    long int acc_no;
    long int contact_no;
    char name[20];
    int random;
}account;


void add_account(struct account acc)
{
  FILE *fp;
  fp=fopen("bankrecord.txt","a");
  fwrite(&acc,sizeof(acc),1,fp);
  fclose(fp);
}

void display_account_rec()
{
  struct account acc;
  FILE *fp;
  fp=fopen("bankrecord.txt","r");
  while(fread(&acc,sizeof(account),1,fp))
  {
    printf("\n%d\t%s\t%s\t%s\t%ld\t%ld\n",acc.random,acc.name,acc.bankname,acc.ifsc,acc.acc_no,acc.contact_no);
  }
  fclose(fp);
}

void deleteaccount()
{
    struct account acc;
    FILE *fptr1,*fptr2;
    int found=0;
    long int bank_acc_no;
    fptr1=fopen("bankrecord.txt","r");
    fptr2=fopen("update_account.txt","w");
    printf("Enter your account number to delete: ");
    scanf("%ld", &bank_acc_no);
    while(fread(&acc,sizeof(account),1,fptr1)){
      if(acc.acc_no==bank_acc_no){
        found=1;
        
      }
      else{
          fwrite(&acc,sizeof(account),1,fptr2);
      }
    }
    fclose(fptr1);
    fclose(fptr2);
    if(found==1){
      fptr2=fopen("update_account.txt","r");
      fptr1=fopen("bankrecord.txt","w");
      while(fread(&acc,sizeof(account),1,fptr2)){
          fwrite(&acc,sizeof(account),1,fptr1);
        }
      fclose(fptr1);
      fclose(fptr2);
    }
    else{
      printf("\nRecord not found\n");
    }
}

void update_account(struct Login temp)
{
  struct account acc;
  FILE *fp1,*fp2;
  int found=0;
  char update_pass[50];
  int unique_id;
  fp1=fopen("bankrecord.txt","r");
  fp2=fopen("update_account.txt","w");
  
  while(found==0)
  {

    printf("\n\nEnter your unique_id to update the bank account: ");
  
    scanf("%d",&unique_id);

    while(fread(&acc,sizeof(account),1,fp1))
    {
      if(acc.random==unique_id)
      {
        found=1;
        fflush(stdin);
        printf("\nEnter the new bank owner name: ");
        scanf("%s",acc.name);
        printf("\nEnter the new bank name: ");
        scanf("%s",acc.bankname);
        printf("\nEnter the new account number: ");
        scanf("%ld",&acc.acc_no);
        printf("\nEnter the new IFSC code: ");
        scanf("%s",acc.ifsc);
        printf("\nEnter the new contact no.: ");
        scanf("%ld",&acc.contact_no);        
      }
      fwrite(&acc,sizeof(account),1,fp2);
    }
  }
  
  fclose(fp1);
  fclose(fp2);
  if(found==1)
  {
    fp2=fopen("update_account.txt","r");
    fp1=fopen("bankrecord.txt","w");

    while(fread(&acc,sizeof(account),1,fp2))
    {
      fwrite(&acc,sizeof(account),1,fp1);
    }

    fclose(fp2);
    fclose(fp1);
  }
  else
  {
    printf("\nRecord not found\n");
  }
}