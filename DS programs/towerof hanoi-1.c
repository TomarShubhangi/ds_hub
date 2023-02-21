#include<stdio.h>
void TOH(int n,char J,char L,char K) 
{
   if(n>0) 
   {
      TOH(n-1,J,K,L);
      printf("\n Move disk %d from tower %c to tower %c", n,J,L);
      TOH(n-1,K,L,J);
   }
}
int main() 
{
   int n=1;
   TOH(n,'J','L','K');
}


