/******************************************************************************

215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*******************************************************************************/
#include <stdio.h>
 using namespace std;
 



int main()
{
    
    short d[400];


//Set all to 0
for(int i=0;i<399;i++)
   d[i]=0;


//set first digit to 1
d[0]=1;

short c=0; //carry
short tmp=0;//


for(int j=0;j<1000;j++)
{
   c=0;
   tmp=0;
   
   //run through each position in array and calculate new value
   
   for(int i=0;i<400;i++)
   {
      tmp=d[i]*2+c;  // 1*2,etc....
      d[i]= tmp%10;
      c = tmp/10;
   }
   
}

    //The array now contains the number in reverse order
    //We can now add the numbers to get the answer to Project Euler 16
    int sum = 0;
    for(int i=0;i<400;i++){
        
    
        sum+= d[i];
    }
    
    
    printf("%d",sum);
    
    

    return 0;
}


