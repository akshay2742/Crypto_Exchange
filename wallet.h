
typedef struct wallet{
  
    float current_balance;
    float money_amount;
    int random;
}wallet;

void show_current_balance(){
    int unique_id;
    struct wallet wal;
    printf("\nEnter your Unique ID: ");
  scanf("%d", &unique_id);
  FILE *fp;
  fp=fopen("walletrecord.txt","r");
  while(fread(&wal,sizeof(wallet),1,fp))
  {
    if(wal.random==unique_id){
          printf("\n%d\tRs %f\t\n",wal.random,wal.current_balance);
          break;
    }
  }
  
  printf("\n");
  fclose(fp);
}

void create_wallet(struct wallet temp)
{
  FILE *fptr;
  fptr=fopen("walletrecord.txt","a");
  fwrite(&temp,sizeof(wallet),1,fptr);
  fclose(fptr);
}
void deposit_amount(struct wallet temp){
  FILE *fptr1,*fptr2;
  int unique_id;
  printf("\nEnter your Unique ID: ");
  scanf("%d", &unique_id);
  float temp1=0;
  struct wallet wal;
  int found=0;
  
  fptr1=fopen("walletrecord.txt","r");
  fptr2=fopen("temp.txt","w");
 
    while(fread(&wal,sizeof(wallet),1,fptr1))
    {
       if(wal.random==unique_id)
        {
          found=1;
          temp1=wal.current_balance;
           
          wal.current_balance=temp1+temp.money_amount;
        }
        fwrite(&wal,sizeof(wallet),1,fptr2);
    }
    
    fclose(fptr1);
    fclose(fptr2);
    if(found==1)
    {
      fptr2=fopen("temp.txt","r");
      fptr1=fopen("walletrecord.txt","w");

      while(fread(&wal,sizeof(wallet),1,fptr2))
      {
        fwrite(&wal,sizeof(wallet),1,fptr1);
      }

      fclose(fptr2);
      fclose(fptr1);
      printf("\nAmount Rs %f successfully added.\n", temp.money_amount);
    }
    
    
  
  FILE *fp;
  fp=fopen("walletrecord.txt","r");
  while(fread(&wal,sizeof(wal),1,fp))
  {
    if(wal.random==unique_id){
        printf("\n\tRs %f\t\n",wal.current_balance);
        break;
    }
  }
  printf("\n");
  fclose(fp);

}

void withdraw_amount(struct wallet temp){
  FILE *fptr1,*fptr2;
  int unique_id;
  printf("\nEnter your Unique ID: ");
  scanf("%d", &unique_id);
  float temp1=0;
  struct wallet wal;
  int found=0;
  
  fptr1=fopen("walletrecord.txt","r");
  fptr2=fopen("temp2.txt","w");
 
    while(fread(&wal,sizeof(wallet),1,fptr1))
    {
       if(wal.random==unique_id)
        {
          found=1;
          temp1=wal.current_balance;
           
          wal.current_balance=temp1-temp.money_amount;
        }
        fwrite(&wal,sizeof(wallet),1,fptr2);
    }
    
    fclose(fptr1);
    fclose(fptr2);
    if(found==1)
    {
      fptr2=fopen("temp2.txt","r");
      fptr1=fopen("walletrecord.txt","w");

      while(fread(&wal,sizeof(wallet),1,fptr2))
      {
        fwrite(&wal,sizeof(wallet),1,fptr1);
      }

      fclose(fptr2);
      fclose(fptr1);
      printf("\nAmount Rs %f successfully Withdraw.\n", temp.money_amount);
    }
    
    
  
  FILE *fp;
  fp=fopen("walletrecord.txt","r");
  while(fread(&wal,sizeof(wal),1,fp))
  {
    if(wal.random==unique_id){
        printf("\n\tRs %f\t\n",wal.current_balance);
        break;
    }
  }
  printf("\n");
  fclose(fp);


}