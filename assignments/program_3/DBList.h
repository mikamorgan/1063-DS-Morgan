#include <iostream>
#include <string>

using namespace std;

struct Node{
  string Data;

  Node *Prev;
  Node *Next;
  Node(string x){
      Data = x;
      Prev = NULL;
      Next = NULL;
  }
};

class DBList{
private:
    Node *Head;
    Node *Tail;
    Node *Current;
    Node* _Find(string);
public:
    DBList();
    int getMultiplier();
    void Insert(string);
    void Insert(Node*&);
    string Traverse(string a, int m);
    bool Delete(string);    
    bool Find(string);
    string Winner();
};
