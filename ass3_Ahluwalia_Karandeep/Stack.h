#ifndef Stack_
#define Stack_
#include <string>
using namespace std;

class Stack {
  public:
    Stack();
    //Constructor
    ~Stack();
    //Destructor
    bool isEmpty() const;
    //returns true if stack is empty, otherwise returns false
    int getLength() const;
    //returns length of the Stack
    bool Push(const string & newEntry);
    //Adds a node wtih string data type to the Stack
    string Pop();
    //Precondition: Must have atleast one node in the Stack
    //Returns the top of the stack
    string Peek() const;
    //Precondition: Must have atleast one node in the stack
  private:
    class node{
      public:
        node *next;
        string data;
    };
    int length;
    node *head;
};

#endif
