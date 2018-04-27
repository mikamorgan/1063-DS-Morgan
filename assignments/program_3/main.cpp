/*
 * @ProgramName: Program Three: Doubly Linked List
 * @Author: Mika Morgan
 * @Description: This program reads in a list of animal names from a file and counts the word length.
 * It then multiplies the animal name length by a user given multiplier and traverses the list that number of times.
 * The traversal moves right if the count is even and left otherwise.
 * The program deletes the node it lands on, and then repeats this process until only one animal remains.     
 * @Course: 1063 Data Structures
 * @Semester: Spring 2018
 * @Date: 26 04 2018
 */

#include <iostream>
#include <fstream>
#include <string>
#include "DBList.h"

using namespace std;

int main() {
  DBList List;
  string a;
  string temp;
  int multiply;
  int listCount = 0;
  ifstream fin("animals.txt");
  ofstream fout("eliminated.txt");
    
  //Step One: load a doubly-linked list with 
  //animal names from the list
    while(fin >> a){
      List.Insert(a);
      listCount++;
    }
    
  //Step Two: reset the file  
    fin.clear();
    fin.seekg(0, std::ios::beg);
    
  //Step Three: get the multiplier
    multiply = List.getMultiplier();
    
  //Steps Four-Eight: traverse the list and write out animal
    fout << "First: ";
    fin >> a;
    temp = List.Traverse(a, multiply);
    fout << "-" << temp << endl;
    
  //Step Nine: delete node
    List.Delete(a);
    listCount--;
    
  //Step Ten: repeat until only one animal remains
    for(listCount; listCount > 1; listCount--){
      fin >> a;
      temp = List.Traverse(a, multiply);
      fout << "-" << temp << endl;
      List.Delete(temp);
      }
  
  //Step Eleven: declare the winner
    fout << "Winner: ";
    fout << List.Winner();
}

