#include <iostream>
using namespace std;

int main() {
 int  i =0, j=0, k=1;
 //initialize row and column place holders to index at 0

int Nums[15][15];
//create a two dimensional array with 15 rows and 15 columns

for(i=0;i<15;i++){
//the outer for loop goes through each row one at a time
  
  k = i + 1;
  //the value counter needs to start at 1 higher than the row index, because we start counting at 1 instead of 0
   
   for(j=0;j<15;j++){
     //the inner for loop goes through each column index of each row one at a time
     
      Nums[i][j]=k;
      k+= 15;
      
      //the initial value at the beginning of each row is just one over the index, k, but the value adds 15 at each column increment
      
      cout << Nums[i][j] << " ";
      //print out each value in the array one at a time
   }
   cout << endl;
   //skip to a new line at the end of each row
}


}
