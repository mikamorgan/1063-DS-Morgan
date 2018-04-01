/*
 * @ProgramName: Program Two: Priority Queue
 * @Author: Mika Morgan
 * @Description: 
 *     This program reads in push and pop commands from an input file and adds animal names to a list based queue
 *     in order from shortest word to longest word. Words of equal length are added alphabetically. The program prints
 *     out all popped animal names in order, followed by all remaining items in the queue according to priority.
 * @Course: 1063 Data Structures
 * @Semester: Spring 2018
 * @Date: 30 03 2018
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    string val;
    int len;
    Node *next;
    
    //default node constructor
    Node()
    {
        val = " ";
        len = 0;
        next = NULL;
    }
    
    //constructor with animal name passed in as a parameter
    Node(string v)
    {
        val = v;
        len = v.length();
        next = NULL;
    }
};

/*
 * class Queue
 *     This is a list based priority queue that will hold animal names. Animal names will be ordered from shortest
 *     to longest; words of equal length will be ordered alphabetically.
 * Methods:
 *  - Queue()               : constructor
 *  - string pop()          : will return the animal name currently at the front of the list
 *  - void push(string)     : will add the animal name (passed in as a param) in the appropriate place in the list
 *  - void frontSert(string): adds the animal name (passed in as a param) to the front of the list
 *  - void endSert(string)  : adds the animal name (passed in as a param) to the rear of the list
 *  - bool empty()          : returns whether or not the list is empty
 *  - void print()          : prints the current list; used only for debugging
 */

class Queue
{
  private:
    Node *Front;
    Node *Rear;

  public:
  /*
   * Queue constructor
   * params:
   *     - none
   */
    Queue()
    {
        Front = Rear = NULL;
    }

 /*
  * Function: pop()
  * Description:
  *    Returns the animal name currently at the front of a non-empty list. Prints error message otherwise.
  * Params:
  *    None
  * Returns:
  *    A string, the animal name removed from the list
  */
    string pop()
    {
        if (!empty())
        {
            Node *temp = Front;   // temp pointer so we can delete node
            string v = temp->val; // grab value out of node
            Front = Front->next;  // move pointer to next node
            delete temp;          // give mem back to system
            return v;
        }
        else
        {
            cout << "error: cannot pop off empty queue." << endl;
            return " ";
        }
    }

 /*
  * Function: frontSert(string)
  * Description:
  *    Adds an animal name (passed as a param) to the front of the list. Creates a new node and does a front sert.
  * Params:
  *    A string, the animal name to be added
  * Returns:
  *    Void
  */
    
    void frontSert(string v){
      Node *n = new Node(v);
        n->next = Front;
        Front = n;
    }
 
 /*
  * Function: endSert(string)
  * Description:
  *    Adds an animal name (passed as a param) to the rear of the list. Creates a new node and does a rear sert.
  * Params:
  *    A string, the animal name to be added
  * Returns:
  *    Void
  */
  
    void endSert(string v){
      Node *n = new Node(v);
        Rear->next = n;
        Rear = n;
    }

 /*
  * Function: push(string)
  * Description:
  *    
  * Params:
  *    A string, the animal name to be added
  * Returns:
  *    Void
  */
  
    void push(string v)
    {
        Node *n = new Node(v);

      // handle the empty case
      if (empty())
        {
            Front = n;
            Rear = n;
        }
        
      else
        {
          //if word is shorter than all other words in the queue, perform a front sert
         if(n->len < Front->len){
            frontSert(v);
            }
          
          //if word is equal length to the shortest word, loop through words that length and compare words alphabetically
         else if(n->len == Front->len){
            
            //if new word comes before Front alphabetically, do a front sert 
            if(n->val < Front->val){
               frontSert(v);
            }
            
            //check to see if list is only one word (otherwise it will error when you try to traverse the list)
            else if(n->val > Rear->val){
               endSert(v);
            }
            
            //else, loop through list and find where the new word is no longer the least, alphabetically
            else{
            Node *temp = Front;
              while (n->len == temp->next->len && (n->val > temp->next->val))
                {
                  temp = temp->next;
                }
                
              //once the loop finds the correct location, perform an insertion in the middle of the list
              n->next = temp->next;
              temp->next = n;
             }
           }
          
          //if word is longer than all other words in the queue, perform an end sert
        else if(n->len > Rear->len){
            endSert(v); 
            }
          
          //if word is equal length to the longest word, loop through list and compare words alphabetically
        else if(n->len == Rear->len){
            
            //if new word comes after Rear alphabetically, do an end sert 
            if(n->val > Rear->val){
               endSert(v);
            }
            
            //else, loop through list and find where the new word is no longer the least, alphabetically
            else{
             Node *temp = Front;
              while (n->len >= temp->next->len && (n->val > temp->next->val))
                {
                  temp = temp->next;
                }
                
              //once the loop finds the correct location, perform an insertion in the middle of the list  
              n->next = temp->next;
              temp->next = n;
           }
          }
          
        //the word is not less than or equal to the front, or greater than or equal to the rear
        //start at the front and loop until you find the correct placement for the word length
        else{
          Node *temp = Front;
           while (n->len <= temp->next->len && (n->val > temp->next->val))
               {
                 temp = temp->next;
               }
              
             //once the loop finds the correct location, perform an insertion in the middle of the list
             n->next = temp->next;
             temp->next = n;
          } 
        }
    }

 /*
  * Function: empty()
  * Description:
  *    Returns true if the list is empty and false otherwise
  * Params:
  *    None
  * Returns:
  *    A boolean
  */
  
    bool empty()
    {
        return (Front == NULL);
    }

 /*
  * Function: print()
  * Description:
  *    Prints the current list based queue. Only used during debugging.
  * Params:
  *    None
  * Returns:
  *    Void
  */

    void print()
    {
        Node *temp = Front;
        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue Q;
    string command, animal;
    
    ifstream iFile;
    iFile.open("input_data.txt");


    while (iFile.is_open() && !iFile.eof())
    {
        iFile >> command;
        if(command == "push"){
          iFile >> animal;
          Q.push(animal);
        }
        else{
          Q.pop();
        }
        //cin >> animal;
        //cout << animal << endl;
      Q.print();
      cout << endl;
    }
}