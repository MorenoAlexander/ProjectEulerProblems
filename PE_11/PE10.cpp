/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;

//class definition for grid


class Grid {
    
    private:
        int HorizontalSize;
        int VerticalSize;
        int MaximumProduct; //maximum product size from any valid direction
        
        
        int** grid;

        
        char filename[50];
        ifstream file;
        
        void calcHorizontalProducts(){
            int result=0;
            int startingPos = 0;
            if(HorizontalSize % 4 == 0){
                //iterate through all rows
                for(int i = 0;i<VerticalSize;i++){
                    
                    for(int block=0; block < HorizontalSize-3; block++)
                        result = grid[i][startingPos]
                        * grid[i][startingPos+1]
                        * grid[i][startingPos+2]
                        * grid[i][startingPos+3];
                        if(result > MaximumProduct){
                          MaximumProduct = result;
                        }
                    
                }
            }
            //Run assuming that there will be 1 or more numbers  out
            else{
                
            }
        }
        
        
        void calcVerticalProducts(){
            //do for 20x20
            int result=0;
            int startingPos=0;
            for(int j = 0; j< HorizontalSize;j++){
                for(int block=0;block<VerticalSize-3;block++){
                        result = grid[startingPos][j]
                        * grid[startingPos+1][j]
                        * grid[startingPos+2][j]
                        * grid[startingPos+3][j];
                        
                        if(result > MaximumProduct){
                            MaximumProduct = result;
                        }
                }
            }
            
        }
        
        
        void calcDiagonalProduct(){
            int result =0;
            int startingPosX = 0;
            //diagonal (left->right)
            for(int j = 0;j<VerticalSize-3;j++){
                for(int i = 0;i<HorizontalSize-3;i++){
                    result = grid[j][i] * grid[j+1][i+1] * grid[j+2][i+2] * grid[j+3][i+3];
                    
                    if(result > MaximumProduct){
                        MaximumProduct = result;
                    }
                }
            }
            
            //diagonal (left to right)
            /*
            prod = M[r][c]*M[r+1][c-1]*M[r+2][c-2]*M[r+3][c-3];
            */
            for(int i=3;i<HorizontalSize;i++){
                for(int k=0;k<VerticalSize-3;k++){
                    result = grid[k][i] * grid[k+1][i-1] * grid[k+2][i-2] * grid[k+3][i-3];
                    
                    if(result > MaximumProduct){
                        MaximumProduct = result;
                    }
                }
                
            }
        }
        
        
        
        
    
    public:
        //Constructor
        Grid(){
            HorizontalSize=0;
            VerticalSize=0;
        }
        
        
        Grid(char * fileString){
            //Default Constructor (20x20 grid)
            
            
            HorizontalSize = 20;
            VerticalSize = 20;
            MaximumProduct = 0;
            file.open(fileString);
            
            
            grid = new int* [VerticalSize];
            for(int i=0; i < VerticalSize;i++){
                grid[i] = new int[HorizontalSize];
            }
            
            stringstream Ss;
            string line;
            string tempString;
            
            int numFound;
            int j;
            
            for(int i=0;i<VerticalSize;i++){
                j=0;
                if(getline(file,line)){
                    Ss.clear();
                    Ss.str(line);
                    //cout<<line<<"\n";
                    while (!Ss.eof()){
                        Ss >> tempString;
                        
                        if (stringstream(tempString) >> numFound){
                            grid[i][j++] = numFound; 
                        }
                        tempString = "";
                    }
                    
                    
                }
            }
            
            for(int i=0;i < VerticalSize;i++){
                for(int j = 0; j < HorizontalSize;j++){
                    cout<<setw(2)<<grid[i][j]<<" ";
                }
                cout<<"\n";
            }
            

            
        }
        
        
        
        int calcLargestProduct(){
            calcHorizontalProducts();
            calcVerticalProducts();
            calcDiagonalProduct();
            
            return MaximumProduct;
        }
        
        
        
        
        
};





int main(int argc, char ** argv)
{
    FILE filename;
    
    Grid newg = Grid(argv[1]);
    
    cout<<newg.calcLargestProduct()<<"\n";

    return 0;
}
