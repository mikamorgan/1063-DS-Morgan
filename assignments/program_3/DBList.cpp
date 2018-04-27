#include <iostream>
#include <string>
#include "DBList.h"

using namespace std;


DBList::DBList(){
  Head = NULL;
  Tail = NULL;
  Current = NULL;
}

/**
 * getMultiplier - 
 *     Prompts the user for an integer 1-13. Checks for validity, and returns the multiplier.
 * Params:
 *     None
 * Returns:
 *     An int 1-13, inclusive, to be used as the multiplier
 */
int DBList::getMultiplier(){
  int num;
   //prompt the user for a multiplier
  cout << "Please enter an integer [1-13] to use as the multiplier: " << endl;
  cin >> num;
  
  //check input for validity
  while(!(num >= 1 && num <= 13)){
      cout << "That is not a valid number. Please enter an integer [1-13] to use as the multiplier: " << endl;
      cin >> num;
    }
  return num;
}

/**
 * Insert - 
 *     Inserts a value at the front of the list by calling actual insert with a node.
 * Params:
 *     string : data element to be inserted
 * Returns:
 *     void
 */
void DBList::Insert(string Data){
  Node* Temp = new Node(Data);
  Insert(Temp);

}

/**
 * Insert - 
 *     Inserts a value at the front of the list
 * Params:
 *     Node*& : node to be appended to front
 * Returns:
 *     void
 */
void DBList::Insert(Node* &Temp){
  if(!Head){
    Head = Temp;
    Tail = Temp;
    Tail->Next = Head;
    Current = Temp;
    Head->Prev = Tail;
    
  }else{
    Temp->Next = Head;
    Temp->Prev = Tail;
    Head->Prev = Temp;
    Tail->Next = Temp;
    Head = Temp;
    Current = Head;
  }
}

/**
 * Traverse - 
 *     Starts at the current node and traverses the list, moving the length of the animal name times the multiplier.
 *     Traverses right if the value is even, and left otherwise. Returns the animal name at the current node.
 * Params:
 *     string: the animal name read in from the input file
 *     int: the user given multiplier
 * Returns:
 *     string: the animal name in the current node after traversal
 */
string DBList::Traverse(string a, int m){
  int count = 0;
  int value = a.length() * m;
  
  //traverse right if the value is even
  if(value % 2 == 0){
    while(count < value){
      Current = Current->Next;
      count++;
    }
  }
  //traverse left otherwise
  else{
    while(count < value){
    Current = Current->Prev;
    count++;
    }
  }
  
  return Current->Data;
}

/**
 * Delete - 
 *     Starts at the beginning of the list and searches for the animal in the current node after the traversal.
 *     Deletes that node, and relinks the rest of the list.
 * Params:
 *     string: the animal name to be deleted from the list
 * Returns:
 *     bool: whether or not the animal name was successfully found and deleted
 */
bool DBList::Delete(string x){
  //One node 
  if(Head == Tail && Head->Data==x){
    delete Head;
    Head = NULL;
    Tail = NULL;
    return true;
  //Beginning of list
  }else if(Head->Data == x){
    Head = Head->Next;
    delete Head->Prev;
    Head->Prev = NULL;
    return true;
  //End of list
  }else if(Tail->Data == x){
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = NULL;
    return true;
  //Middle of list
  }else{
    Node* Location = DBList::_Find(x);
    if(Location){
      Location->Prev->Next = Location->Next;
      Location->Next->Prev = Location->Prev;
      delete Location;
      return true;
    }
  }
  return false; 
}

//Part of Delete method, used to find the key value
bool DBList::Find(string x){
  return false;
}

//Part of Delete method, used to find the key value
Node* DBList::_Find(string key){
  Node* Temp = Head;
  
  while(Temp){
    if (Temp->Data == key){
      return Temp;
    }
    Temp = Temp->Next;
  }
  return NULL;
}

/**
 * Winner - 
 *     Returns the last animal name remaining in the list after looping
 * Params:
 *     None
 * Returns:
 *     string: the animal name in the head (last remaining node)
 */
string DBList::Winner(){
  cout << Head->Data;
}


