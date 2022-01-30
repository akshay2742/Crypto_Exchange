#include"wallet.h"

typedef struct crypto_record
{
  int unique_id;
  double Bitcoin;
  double Ethereum;
  double Polygon;
  double Dogecoin;
  double Litecoin;
}crypto_record;

void add_crypto_record(struct crypto_record temp)
{
  FILE *fp;
  fp=fopen("crypto_record.txt","a");
  fwrite(&temp,sizeof(crypto_record),1,fp);
  fclose(fp);
}
void portfolio()
{
  struct crypto_record temp;
  FILE *fp;
  fp=fopen("crypto_record.txt","r");
  printf("\nId\t Bitcoin\tEthereum\t  Polygon\t  Dogecoin\t Litecoin");
  while(fread(&temp,sizeof(crypto_record),1,fp))
  {
    printf("\n%d\t%lf\t%lf\t%lf\t%lf\t%lf\n",temp.unique_id,temp.Bitcoin,temp.Ethereum,temp.Polygon,temp.Dogecoin,temp.Litecoin);
  }
  fclose(fp);
  
}

// void update_crypto_record(struct crypto_record temp)
// {
//   FILE *fptr1,*fptr2;
//   int found=0;
//   fptr
// }
void buy_crypto(double rate, struct wallet temp, double buy_coin )
{ 
  int unique_id;
  struct wallet wal;
  printf("\nEnter your Unique ID: ");
  scanf("%d", &unique_id);
  FILE *fp;
  fp=fopen("walletrecord.txt","r");
  while(fread(&wal,sizeof(wallet),1,fp))
  {
    if(wal.random==unique_id)
    {
      if(wal.current_balance>=(rate*buy_coin))
      {
        FILE *fptr1,*fptr2;
        
        float temp1=0;
        int found=0;
        fptr1=fopen("walletrecord.txt","r");
        fptr2=fopen("temp3.txt","w");
        
        while(fread(&wal,sizeof(wallet),1,fptr1))
        {
          if(wal.random==unique_id)
          {
            found=1;
            wal.current_balance=wal.current_balance-(buy_coin * rate);
          }
          fwrite(&wal,sizeof(wallet),1,fptr2);
        }
        fclose(fptr1);
        fclose(fptr2);
        if(found==1)
        {
            fptr2=fopen("temp3.txt","r");
            fptr1=fopen("walletrecord.txt","w");

            while(fread(&wal,sizeof(wallet),1,fptr2))
            {
             fwrite(&wal,sizeof(wallet),1,fptr1);
            }

           fclose(fptr2);
           fclose(fptr1);
        }
      FILE *fp;
      fp=fopen("walletrecord.txt","r");
       while(fread(&wal,sizeof(wal),1,fp))
       {
         if(wal.random==unique_id)
         {
          printf("\n\tRs %f\t\n",wal.current_balance);
          break;
         }
       }
  
       printf("\n");
       fclose(fp);

      }
      else{
        
        printf("\nYou have Insufficient wallet balance !!\n");
      }
    }
  }
}
  

void sell_crypto(double rate, struct wallet temp, double buy_coin )
{ 
  int unique_id;
  struct wallet wal;
  printf("\nEnter your Unique ID: ");
  scanf("%d", &unique_id);
  FILE *fp;
  fp=fopen("walletrecord.txt","r");
  while(fread(&wal,sizeof(wallet),1,fp))
  {
    if(wal.random==unique_id)
    {
      if(wal.current_balance>=(rate*buy_coin))
      {
        FILE *fptr1,*fptr2;
        
        float temp1=0;
        int found=0;
        fptr1=fopen("walletrecord.txt","r");
        fptr2=fopen("temp3.txt","w");
        
        while(fread(&wal,sizeof(wallet),1,fptr1))
        {
          if(wal.random==unique_id)
          {
            found=1;
            wal.current_balance=wal.current_balance+(buy_coin * rate);
          }
          fwrite(&wal,sizeof(wallet),1,fptr2);
        }
        fclose(fptr1);
        fclose(fptr2);
        if(found==1)
        {
            fptr2=fopen("temp3.txt","r");
            fptr1=fopen("walletrecord.txt","w");

            while(fread(&wal,sizeof(wallet),1,fptr2))
            {
             fwrite(&wal,sizeof(wallet),1,fptr1);
            }

           fclose(fptr2);
           fclose(fptr1);
        }
      FILE *fp;
      fp=fopen("walletrecord.txt","r");
       while(fread(&wal,sizeof(wal),1,fp))
       {
         if(wal.random==unique_id)
         {
          printf("\n\tRs %f\t\n",wal.current_balance);
          break;
         }
       }
  
       printf("\n");
       fclose(fp);

      }
    }
  }
}      
  
 
