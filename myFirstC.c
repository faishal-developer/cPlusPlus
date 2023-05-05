#include<stdio.h>
#include<math.h>
#include <stdlib.h>


int main()
{
   float meal, tax,tip;
   printf("meal cost =\n");
   scanf("%f",&meal);
   printf("tax rate =\n");
   scanf("%f",&tax);
   printf("tip rate =\n");
   scanf("%f",&tip);
   float taxCost =  meal*tax/100;
   float tipCost =  tip*meal/100;
   float totalCost =  meal+ taxCost + tipCost;

   printf("total cost=%f\n",totalCost);
   
   return 0;
}

// int main(){
//    int n;
//    scanf("%d",&n);
//    int prev = 0;
//    int next = 1;
//    for (int i = 0; i < n; i++)
//    {
//       for (int j = 0; j <=i ; j++)
//       {
//          printf("%d ",next);
//          int temp = prev;
//          prev = next;
//          next = temp + next;
//       }
//       printf("\n");
      
//    }
   
//    return 0;
// }

