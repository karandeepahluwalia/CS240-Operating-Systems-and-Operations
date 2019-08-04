#ifndef shopping_cart_
#define shopping_cart_
#include "ItemToPurchase.h"
#include "LinkedList.h"
#include <string>
using namespace std;

class ShoppingCart {

public:
	ShoppingCart();
	bool add(ItemToPurchase newitem);
	bool add(ItemToPurchase newitem,int  position);
	bool remove(int position) ;
	ItemToPurchase getItem(int position);
	void display();
	double ItemCost(int position);
    double totalCost();
	int getLength();
    bool IsValid(int pos);
private:
	LinkedList newList;
};
#endif 
