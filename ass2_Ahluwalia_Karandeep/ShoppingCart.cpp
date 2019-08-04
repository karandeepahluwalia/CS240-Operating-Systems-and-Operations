#include <iostream>
#include "ItemToPurchase.h"
#include "LinkedList.h"
#include <string>
#include "ShoppingCart.h"
using namespace std;


ShoppingCart::ShoppingCart(){
}
bool ShoppingCart::add(ItemToPurchase newItem){
    newList.append(newItem);
    cout<<"Item add at the end"<<endl;
    return true;
}
bool ShoppingCart::add(ItemToPurchase newItem,int position){
	if(!newList.insert(position, newItem)){
//        cout<<"This means insert must have failed"<<endl;
        cout<<"Position out of range: must be between 1 and "<<newList.getLength()<<endl;
		return false;
	}else{
        cout<<"Item added at position: "<<position<<endl;
		return true;
	}
}
bool ShoppingCart::remove(int position){
	if(!newList.remove(position)){
 //       cout<<"This means you have to fix things"<<endl;
        cout<<"Position out of range: must be between 1 and "<<newList.getLength()<<endl;
        return false;
	}else{
		cout<<"Item removed at position "<<position<<endl;
        return true;
	}
}
void ShoppingCart::display(){
    for(int i =0;i<newList.getLength();i++){
        cout<<i+1<<". "<<newList.retrieve(i+1)<<endl;
    }
}
ItemToPurchase ShoppingCart::getItem(int position){
    ItemToPurchase tmp = newList.retrieve(position);
    return tmp;
}
double ShoppingCart::totalCost(){
    double temp = 0;
    for(int i =0;i<newList.getLength();i++){
        temp += newList.retrieve(i+1).GetTotal();
    }
    return temp;
}
double ShoppingCart::ItemCost(int position){
        return newList.retrieve(position).GetTotal();
    
}
int ShoppingCart::getLength(){
    return newList.getLength();
}
bool ShoppingCart::IsValid(int pos){
    if((pos>0)&&(pos<=newList.getLength())){
        return true;
    }else{
        cout<<"Position out of range: must be between 1 and "<<newList.getLength()<<endl;
        return false;
    }
}
        
