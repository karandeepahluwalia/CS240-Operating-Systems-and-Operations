#include "Stack.h"
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

Stack::Stack(){
  node* a= new node;
  head = nullptr;
  length = 0;
}
bool Stack::isEmpty() const{
  return (length == 0);
}
int Stack::getLength() const{
  return length;
}
bool Stack::Push(const string & newEntry){
  node* p = new node;
  p->data = newEntry;
  p->next = head;
  head = p;
  length++;
//  cout<<"Stack function worked"<<endl;
  return true;
}
string Stack::Pop(){
  assert(length!=0);
  node*b = head;
  node*c = head->next;
  string str = head->data;
  head=c;
  delete b;
  length--;
//  cout<<"Stack popped worked"<<endl;
  return str;
}

string Stack::Peek() const{
  assert(length!=0);
  return head->data;
}
Stack::~Stack(){
  node* a = head;
  while(a!=nullptr){
    node *b = a->next;
    delete a;
    a = b;
  }
//  cout<<"Stack deleted"<<endl;
}
