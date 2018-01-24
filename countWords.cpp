
#include <iostream>
#include <fstream>
using namespace std;

  //create a struct that will correlate words with their counts
struct wordNode{
  string word;
  int count;
};

int main() {
  ifstream myFile("words.txt");
  wordNode wordArray[100]; 
  string word = "";
  int wordCount = 0;
  bool found = false;
  
    //initialize wordArray
  for(int i=0;i<100;i++){
    wordArray[i].word = "";
    wordArray[i].count = 0;   
    }
  
  while(myFile.is_open() && !myFile.eof()){
    //read in one word at a time
    myFile >> word;
    
    //set first word in file to index 0 of array
    if(wordCount == 0){
      wordArray[0].word = word;
      wordArray[0].count = 1;
      wordCount++;
    }
    
    //check each subsequent word in file against all words currently in array
    //if a match is found, increment the counter for that word
    else{
      for(int i = 0; i < wordCount; i++)
      {
        if(word == wordArray[i].word)
         {
           wordArray[i].count++;
           found = true;
         }
      }
    //if no match is found, add the word as a new element in the array
      if(!found){
        wordArray[wordCount].word = word;
        wordArray[wordCount].count = 1;
        wordCount++;
      }
    }
  }
  
  //print out each word in the array followed by its count. Separate words with a blank line
  for(int i = 0; i < wordCount; i++){
    cout << "Word: " << wordArray[i].word << "\nCount: " << wordArray[i].count << endl << endl;
  }
}
