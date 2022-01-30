#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct Login
{
      int random1;
      char email_login[50];
      char password_login[50];
      

}Login;

typedef struct Signup
{
    char name[20];
    char email[50];
    long int contact_no;
    char Gender;
    int day,month,year;
    char create_password[50];
    int random;

}Signup;

void create(struct Signup temp)
{
  FILE *fp;
  fp=fopen("filedata.txt","a");
  fwrite(&temp,sizeof(Signup),1,fp);
  fclose(fp);
}


void noofrecords (){
    struct Signup s;
    FILE *fptr;
    fptr=fopen("filedata,txt","r");
    fseek(fptr,0,SEEK_END);
    int n=ftell(fptr)/sizeof(Signup);
    printf("\nNo. of records= %d",n);
    fclose(fptr);
}


void display(){
  struct Signup s;
  FILE *fp;
  fp=fopen("filedata.txt","r");
  while(fread(&s,sizeof(Signup),1,fp))
  {
    printf("\n%d\t%s\t%s\t%ld\t%c\t%d/%d/%d\t%s\n",s.random,s.name,s.email,s.contact_no,s.Gender,s.day,s.month,s.year,s.create_password);
  }
  fclose(fp);
  
}

int search(struct Login temp)
{
  struct Signup s;
  FILE *fp;
  int found=0;
  fp=fopen("filedata.txt","r");
  
  while(fread(&s,sizeof(Signup),1,fp))
  {
    int email_check = strcmp(s.email,temp.email_login);
    int pass_check = strcmp(s.create_password,temp.password_login);

    if(email_check==0 && pass_check==0)
    {
      printf("\nLogin Successful\n");
      found=1;
      
      break;
    }
    else
    {
      found=0;
      continue;
    }
  }
  if(found==0)
  {
    printf("\nError! You entered wrong credentials.\n\n");
  }
  fclose(fp);
  return found;
}