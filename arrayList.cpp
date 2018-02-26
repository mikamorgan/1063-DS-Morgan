/**
* @ProgramName: Array List Extra Credit
* @Author: Mika Morgan
* @Description: 
*     This program reads in animal names from a text file and enters them in a linked list using a stack
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 25 02 2018
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node{
  string word;
  Node* next;
  Node(){
    word = "";
    next = NULL;
  }
  Node(string w){
    word = w;
    next = NULL;
  }
};

class List{
private:
  Node* Top;
  int listSize;
  
public:
  List(){
    Top = NULL;
    listSize = 0;
  }
  
  void Push(string word){
    Node* temp = new Node(word);
    
    if(Top==NULL){
      //empty list easy fix
      Top = temp;
    }else{
      //list is not empty so link it in
      temp->next = Top;
      Top = temp;
    }
    
  }
  
  void Print(){
    Node* temp = Top;
    while(Top != NULL){
      cout<<Top->word<<" ";
      Top = Top->next;
    }
  }
  
  string Pop(){
    string word;
    
    return word;
  }
  
};

int main() {
  List L;
  string word;
  
  ifstream fin;
  
  fin.open("animals.txt");
  
  while(!fin.eof()){
    fin>>word;
    //cout<<word<<" ";
    L.Push(word);
  }
  
  L.Print();
  
}
