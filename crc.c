#include<stdio.h>
#include<string.h>
//#include<sys/types.h>
main()
{
  char bin[16];
  int i,j,b[19],a[16],l,dv[4]={1,0,1,1};
  l1:
  printf("\nEnter Binary String :");
  gets(bin);
  fflush(stdin);
  l=strlen(bin);
  if(l!=16)
   goto l1;
  for(i=0;i<l;i++)
  {
    b[i]=(int)(bin[i]-48);              
    a[i]=b[i];
    //printf("%d",b[i]);
  } 
  for(;i<l+3;i++)
    b[i]=0;
  printf("\nAfter Adding 3 0 Bits :");
  for(i=0;i<l+3;i++)
  {
    printf("%d",b[i]);
  }
  printf("\nDivisor :");
  for(i=0;i<4;i++)
  {
    printf("%d",dv[i]);
  }
  j=3;i=0;
  while(j<l+3)
  {
    if(b[i]==0)
    {
       i++;
       j++;
       continue;           
    }           
    else if(b[i]==1)
    {    
         b[i+1]=b[i+1]^dv[1];  
         b[i+2]=b[i+2]^dv[2];  
         b[i+3]=b[i+3]^dv[3];
    }
    i++;
    j++;      
  }
  printf("\nCRC BITS %d%d%d",b[l],b[l+1],b[l+2]);
  printf("\nCHECKING !!\n");
  for(i=0;i<16;i++)
   b[i]=a[i];
  j=3;i=0;
  while(j<l+3)
  {
    if(b[i]==0)
    {
       i++;
       j++;
       continue;           
    }           
    else if(b[i]==1)
    {
         b[i+1]=b[i+1]^dv[1];  
         b[i+2]=b[i+2]^dv[2];  
         b[i+3]=b[i+3]^dv[3];
    }
    i++;
    j++;      
  }
  printf("\nCHECKED CRC BITS %d%d%d",b[l],b[l+1],b[l+2]);
  getch();
}
