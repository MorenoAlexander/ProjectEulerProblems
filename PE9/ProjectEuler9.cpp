/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int isPythagoreanTriple(int a,int b, int c){
    int aSquare,bSquare,cSquare;
    
    aSquare = a*a;
    bSquare = b*b;
    cSquare = c*c;
    
    if ( (aSquare+bSquare) == cSquare)
    {
        return 1;
    }
    return 0;
}



int findPythagoreanTripletofSum(int dSum)
{
    int tripletSum = 0;
    for (int c=0;c<dSum/2;c++){
        for(int b=0; b< (dSum/2)-1; b++){
            for (int a=0; a < (dSum/3) -1; a++)
            {
                tripletSum = a+b+c;
                if(tripletSum == dSum && isPythagoreanTriple(a,b,c) == 1)
                {
                    cout<<"\na: "<<a<<"\nb: "<<b<<"\nc: "<<c<<endl;
                    return a*b*c;
                }
            }
        }
    }
    
    
    return 0;
}




int main()
{
    int desiredSum = 760;
    int retValue = findPythagoreanTripletofSum(desiredSum);
    
    cout<<"The product of the pythagorean triplet where a+b+c ="
        <<desiredSum
        <<" is: "
        <<retValue<<"\n";

    return 0;
}
