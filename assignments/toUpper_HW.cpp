/**
* @ProgramName: toUpper Function Homework
* @Author: Mika Morgan
* @Description: 
*     This program returns a given string in all lowercase or all uppercase letters, using two functions
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 26 03 2018
*/

#include <iostream>
#include <string>
using namespace std;
 
  /**
  * Function: toLower()
  * Description:
  *     Returns a given string in all lowercase
  * Params:
  *    A string
  * Returns:
  *    A string
  */
string toLower(string w){
  for(int i=0;i<w.length();i++){
    
    //checks to see if a character is a capital letter
    if((int)w[i]>=65 && (int)w[i]<=90){
      
      //if the char is a capital letter, add 32 to the ASCII value
      //to make it a lowercase letter instead
      w[i] = w[i]+32;
      }
  }
  return w;
}

  /**
  * Function: toUpper()
  * Description:
  *     Returns a given string in all uppercase
  * Params:
  *    A string
  * Returns:
  *    A string
  */
string toUpper(string w){
  for(int i=0;i<w.length();i++){
    
    //checks to see if a character is a lowercase letter
    if((int)w[i]>=97){
      
      //if the char is a lowercase letter, subtract 32 from the 
      //ASCII value to make it a capital letter instead
      w[i] = w[i]-32;
    }
  }
  return w;
}

int main() {
  string word = "Made Up Stuff";
  cout << word << endl;
  cout << toLower(word) << endl;
  cout << toUpper(word) << endl;
  
}
