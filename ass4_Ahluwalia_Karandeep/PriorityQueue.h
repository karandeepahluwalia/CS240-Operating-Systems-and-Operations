#ifndef PriorityQueue_
#define PriorityQueue_
#import <string>
#include "Call.h"
using namespace std;

typedef Pair ItemType;
class PriorityQueue {
  public:
    PriorityQueue();
    //Constructor
    ~PriorityQueue();
    //Destructor
    bool isEmpty() const;
    //returns true if queue is empty, otherwise returns false
    int getLength() const;
    //returns length of the queue
    bool Enqueue(const ItemType & newEntry);
    //Adds a node wtih itemtype data type to the queue based on priority
    ItemType Dequeue();
    //Precondition: Must have atleast one node in the queue
    //Returns the top of the queue
    ItemType Peek() const;
    //Precondition: Must have atleast one node in the queue
  private:
    class node{
      public:
        node *next;
        ItemType data;
    };
    int length;
    node *head;
};

#endif
