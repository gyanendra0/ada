#include<stdio.h>
 
int board[20],count;
int absa (int a, int b){
    if (a>b)
    return a-b;
    else
    return b-a;
}
 
int main()
{
 int n,i,j;
 void queen(int row,int n);
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 queen(1,n);
 return 0;
}
 
void printboard(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 

 
 for(i=1;i<=n;++i)
 {
  printf("\n\n");
  for(j=1;j<=n;++j)
  {
   if(board[i]==j)
    printf("\tQ%d",i);
   else
    printf("\t-");
  }
 }
}
 

int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  if(board[i]==column)
   return 0;
  else
   if(absa(board[i],column)==absa(i,row))
    return 0;
 }
 
 return 1;
}
 

void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column;
   if(row==n)
    printboard(n); 
   else 
    queen(row+1,n);
  }
 }
}