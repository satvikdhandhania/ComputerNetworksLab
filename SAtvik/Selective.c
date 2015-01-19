#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
void main()
{ 
  int f=1;
  int b[100],a[100],i,i1=0,j1,i2=0,j2,m,w,j,ack[10],f2;
  char ch;
  printf("\nEnter Size Of Data Chunks(m) :");
  scanf("%d",&m);
  w=pow(2,m)/2;
  printf("\nWindow Size :%d\n",w);
  j1=j2=w-1;
  for(i=0;i<100;i++)
  {
    a[i]=i%w;//printf("%d",a[i]);
    b[i]=-1;
  }
  i=0;
  while(j1<=100)
  {
      lb:
      f=0;f2=0; 
      for(j=0;j<w;j++)
      {
       ack[j]=0;
       printf("\nSending Frame %d",(i1+j)%w);          
       printf("\nDid You Receive The frame :");
       scanf("%c",&ch);
       if(ch=='y')
       {
         b[i1+j]=a[i1+j];             
         if(f==0)
         {
           i2++;j2++;i1++;j1++;
         } 
       }
       else if(ch=='n')
        {
               f=1;f2=1;
               ack[j]=1; 
        }
       while(f2==1)
       {
           goto lb;        
       } 
      } 
  }
 getch();     
}
