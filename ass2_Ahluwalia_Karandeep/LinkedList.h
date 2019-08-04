#ifndef linked_List_
#define linked_List_

#include "ListInterface.h"

class LinkedList : public ListInterface { 
                 
public:
   LinkedList();
   // interface methods
   bool isEmpty() const;   
   int getLength() const;  
   bool insert(int newPos, const ItemType & newEntry);
   bool remove(int pos);  
   ItemType retrieve(int position) const;
   bool append(const ItemType & newEntry);

private:
	class node{
		public:	
			node *next;
			ItemType data;
	};
	int length;
	node *head;
	node * tail;
	
};

#endif
