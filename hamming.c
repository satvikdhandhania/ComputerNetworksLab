#include<stdio.h>
#include<string.h>
#include<sys/types.h>
main()
{
  int a[7];
  int b[4]={1,1,0,0};
  int r[3],i,j=0;
  for(i=1;i<8;i++)
  {
   if(i==1||i==2||i==4)
   a[i]=1000;
   else
    a[i]=b[j++];                  
  }
  for(i=1;i<8;i++)
   printf("\n%d",a[i]);
  printf("\nHamming Code :");
  r[0]=(a[3]^a[5])^a[7]; 
  r[1]=(a[3]^a[6])^a[7];
  r[2]=(a[5]^a[6])^a[7];
  printf("\n%d%d%d",r[0],r[1],r[2]);
  a[1]=r[0];
  a[2]=r[1];
  a[4]=r[2];
  printf("\nSent Data :");
  for(i=0;i<8;i++)
    printf("%d",a[i]);
  printf("\nChecking :");
  a[3]=0;
  r[0]=((a[3]^a[5])^a[7])^a[1];
  r[1]=((a[3]^a[6])^a[7])^a[2];
  r[2]=((a[6]^a[5])^a[7])^a[4];  
  printf("\nFinal Result :%d%d%d",r[2],r[1],r[0]);
  if(r[0]==0&&r[1]==0&&r[2]==0)
    printf("\nNo Error !!!");
  else
  {
   printf("\nRecieved Data : %d%d%d%d",a[3],a[5],a[6],a[7]);
   i=r[2]*4+r[1]*2+r[0];
   printf("\nError At Bit Position :%d",i+1); 
   printf("\nChanging Bit : %d",i);
   if(a[i]==0)
   a[i]=1;
   else if(a[i]==1)
   a[i]=0;
  }
  printf("\nFinal String :%d%d%d%d",a[3],a[5],a[6],a[7]);
  getch();
}
