#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
	head = nullptr;
	tail = nullptr;
	length =0;
}
bool LinkedList::isEmpty() const{
	return (head==nullptr) ;
}
int LinkedList::getLength() const{
	return length;
}
bool LinkedList::append(const ItemType & newEntry){
  //  cout<<"append is used"<<endl;
    node* p = new node;
	p->data = newEntry;
	if (head == nullptr){
		p->next = nullptr;
        head = p;
		tail = p;
	}else{
		tail->next = p;
		tail = p;
		p->next = nullptr;
	}
	length++;
	return true;
}
bool LinkedList::insert(int newPos,const ItemType & newEntry){
	if (newPos >length||newPos <1){
		return false;
	}
	if (newPos == length+1){
		return append(newEntry);
    }else if(newPos ==1){
        node* a = new node;
        a->data = newEntry;
        a->next = head;
        head = a;
        length++;
    }else {
        node* copy = head;
//        cout<<"how i want it to work"<<endl;
        node* a = new node;
        a->data = newEntry;
        for(int i=2;i<newPos;i++){
            copy = copy->next;
        }
        a->next =copy->next;
        copy->next = a;
        length++;
    }
	return true;
}

bool LinkedList::remove(int newPos){
    //cout<<"Remove function"<<endl;
	if(newPos>length||newPos <1){
		return false;
    }else if(newPos ==1){
        if(tail ==head){
            tail = nullptr;
        }
            node* a = head;
            head = head->next;
            delete a;
            length--;
        }else{
            node* a = head;
            for(int i=2;i<newPos;i++){
                a = a->next;
            }
            if(newPos == length){
                tail = a;
            }
            node* b = a->next;
            a->next = b->next;
            delete b;
            length--;
        }
        return true;
}
ItemType LinkedList::retrieve(int newPos) const{
  //  cout<<"retrieve"<<endl;
    node* a = head;
	if(newPos>length||newPos <1){
        ItemType car;
        return car;
	}
	for(int i =1;i<newPos;i++){
		a = a->next;
	}
	return a->data;
}







	

