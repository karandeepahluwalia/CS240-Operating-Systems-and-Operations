#include "PriorityQueue.h"
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

PriorityQueue::PriorityQueue(){
  head = nullptr;
  length = 0;
}
bool PriorityQueue::isEmpty() const{
  return (length == 0);
}
int PriorityQueue::getLength() const{
  return length;
}
bool PriorityQueue::Enqueue(const ItemType & newEntry){
  node* newNode = new node;
	newNode->data = newEntry;
  if (length==0){
    newNode->next = head;
    head = newNode;
  }else{
  node* p = head;
//  cout<<"This is point j"<<endl;
  while((p->next != nullptr)&&(p->next->data<newNode->data)){
    p = p->next;
  }
//  cout<<"This is point k"<<endl;
  newNode->next = p->next;
//  cout<<"This is point l"<<endl;
  p->next = newNode;
}
//  cout<<"This is point m"<<endl;
	length++;
	return true;
}

ItemType PriorityQueue::Dequeue(){
  assert(length!=0);
  node*b = head;
  node*c = head->next;
  ItemType str = head->data;
  head=c;
  delete b;
  length--;
//  cout<<"Stack popped worked"<<endl;
  return str;
}

ItemType PriorityQueue::Peek() const{
  assert(length!=0);
  return head->data;
}
PriorityQueue::~PriorityQueue(){
  node* a = head;
  while(a!=nullptr){
    node *b = a->next;
    delete a;
    a = b;
  }
}
