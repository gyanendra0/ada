#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void BinarySearch(int arr[],int num,int first,int last){
      int mid;
   if(first > last){
       
        printf("Number is not found");
        
   } else {      
    
      mid = (first + last)/2;      

      if(arr[mid]==num){
          
            printf("Element is found at index %d ",mid);
                        
        }else if(arr[mid] > num){
            
            BinarySearch(arr, num, first, mid-1);
        
        }else{
            
            BinarySearch(arr, num, mid+1, last);
        }   
    }  
}

void main(){

   int arr[100],number[100],times[100],beg,mid,end,i,n,num;
   clock_t begin,ending;
   double time_spent = 0.0;
   int j=0,a=1; 

   printf("Enter the size of an array ");
   scanf("%d",&n);

   printf("Enter the values in sorted sequence \n");

   for(i=0;i<n;i++){   
       scanf("%d",&arr[i]);
   }   

   beg=0;
   end=n-1;
   while(a!=0)
   {
   begin=clock();
   
   printf("Enter a value to be search: ");
   scanf("%d",&num);
   number[j]=num;
   
   BinarySearch(arr,num,beg,end);
   ending=clock();
   time_spent = (double)(ending - begin) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", time_spent);
    times[j]=time_spent;
    j++;
    printf("\n Do you want to continue? ");
    scanf("%d",&a);
   }
}
