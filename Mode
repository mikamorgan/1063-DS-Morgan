#include <iostream>
using namespace std;

/*Function: printArray
 *Description: Populate an array of size 100 with random numbers 0-99
 *             and print out the array
 *Params: integer array
 *Returns: void
 */
void printArray(int A[]){
   for(int i = 0; i < 100; i++){
      A[i] = rand() % 100;
      cout << A[i] << " ";}
  }

/*Function: mode
 *Description: Counts the number of occurences of each value within a given array
 *             Saves the highest count from each iteration with corresponding value
 *Params: integer array
 *Returns: integer value with highest count in the array (most occuring number)
 */
int mode(int A[]){
    int value = 0, count = 0, highCount = 0;
    for(int i = 0; i < 100; i++){
        count = 0;
        for(int j = 0; j < 100; j++){
            if(A[j] == A[i])
              count++;}
        if(count > highCount){
            value = A[i];
            highCount = count;}}
            
    return value;
  
  }

/*Function: count
 *Description: Counts the number of occurences of each value within a given array
 *             Saves the highest count from each iteration with corresponding value
 *Params: integer array
 *Returns: the highest count (number of occurences of the mode)
 */
int count(int A[]){
    int value = 0, count = 0, highCount = 0;
    for(int i = 0; i < 100; i++){
        count = 0;
        for(int j = 0; j < 100; j++){
            if(A[j] == A[i])
              count++;}
        if(count > highCount){
            value = A[i];
            highCount = count;}}
            
    return highCount;
  
  }

int main() {
  //Create an array of 100 ints and initialize to zeros
  int A[100] = {0};
  
  //Populate array with random numbers 0-99 and print out the array 
  printArray(A);
  
  //Skip a few lines and print the mode and highest count of the array
  cout << endl << endl << "Mode: " << mode(A) << endl << "Count: " << count(A);
 
}
