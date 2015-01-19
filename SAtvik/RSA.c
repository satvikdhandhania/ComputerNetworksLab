#include<stdio.h>
#include<conio.h>
int phi,M,n,e,d,C,flag;
void check()
{
 int i;
 for(i=3;e%i==0&&phi%i==0&&i<phi;i+2)
 {
   flag=1;
 }
 flag=0;
}
void encrypt()
{
 int i;
 C=1;    
  for(i=0;i<e;i++)
  {
   C=C*M;
   C=C%n;
  }   
  C=C%n;
  printf("\nEncrypted Keyword : %d",C);
}
void decrypt()
{
 int i;
 M=1;    
  for(i=0;i<d;i++)
  {
   M=C*M;
   M=M%n;
  }   
  M=M%n;
  printf("\nDecrypted Keyword : %d",M);
}
main()
{
  int p,q,s;
  printf("\nEnter Two Relatively Prime Nos. :");
  scanf("%d%d",&p,&q);
  n=p*q;
  phi=(p-1)*(q-1);
  do
  {
  printf("\n\nEnter e which is prime number and less than phi %d:",phi);
  scanf("%d",&e);
  check();
  }while(flag==1);
  d=1;
  do
  {
   s=(d*e)%phi;
   d++;
  }while(s!=1);
  d=d-1;
  printf("\nPublic Key \t:{%d,%d}",e,n);
  printf("\nPrivate Key \t:{%d,%d}",d,n);
  printf("\nEnter Plain Text :");
  scanf("%d",&M);
  encrypt();
  printf("\nEnter Cipher Text :");
  scanf("%d",&C);
  decrypt();
  getch();
}
