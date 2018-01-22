
#include <iostream>
#include <fstream>
using namespace std;

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
    //read in word
    myFile >> word;
    
    //set first word in file to index 0 of array
    if(wordCount == 0){
      wordArray[0].word = word;
      wordArray[0].count = 1;
      wordCount++;
    }
    else{
      for(int i = 0; i < wordCount; i++)
      {
        if(word == wordArray[i].word)
         {
           wordArray[i].count++;
           found = true;
         }
      }
      if(!found){
        wordArray[wordCount].word = word;
        wordArray[wordCount].count = 1;
        wordCount++;
      }
    }
  }
  for(int i = 0; i < wordCount; i++){
    cout << "Word: " << wordArray[i].word << "\nCount: " << wordArray[i].count << endl << endl;
  }
}
