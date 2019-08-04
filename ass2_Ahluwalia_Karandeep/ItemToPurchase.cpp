#include "ItemToPurchase.h"
#include <string>
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase(){
	this->name = "";
	this->price = 0;
	this->quantity = 0;
}
ItemToPurchase::ItemToPurchase(string name,double price,int quantity){
	this->name=name;
	this->price = price;
	this->quantity = quantity;
}
void ItemToPurchase::SetName(string name){
	this->name= name;
	return;
}
void ItemToPurchase::SetPrice(double price){
	this->price = price;
	return;
}
void ItemToPurchase::SetQuantity(int quantity){
	this->quantity = quantity;
	return;
}
string ItemToPurchase::GetName(){
	return name;
}
int ItemToPurchase::GetQuantity(){
	return quantity;
}
double ItemToPurchase::GetPrice(){
	return price;
}
double ItemToPurchase::GetTotal(){
    return price*quantity;
}
string ItemToPurchase::GetItemInfo(){
	double total = price*quantity;	
	return name +" " +to_string(quantity)+ " $" + to_string(price) + " = $"+to_string(total);
}
ostream & operator<<(ostream& out,const ItemToPurchase & f){
	double price = f.price;
	int quantity = f.quantity;	
	double total = price*quantity;	
	string info = f.name +" " +to_string(quantity)+ " $" + to_string(price) + " = $"+to_string(total);		
	out<<info;
	return out;
}

