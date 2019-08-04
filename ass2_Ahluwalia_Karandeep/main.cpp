#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "ShoppingCart.h"
using namespace std;

ifstream getFileInput();
//input: user input
//output: ifstream of file

void runFileCommands(ifstream& fileInput,ShoppingCart& cart);
//input: stream fileInput, Linked List class
//output: none
//side effects: responsible for managing updating cart as per requests
void insert(ItemToPurchase item, ShoppingCart& cart, int pos);
//input: item from file, cart, position
//output: none
//side effects: adds to the cart
void display(ShoppingCart& cart,int pos);
//input: none
//output: String of user’s input
//side effects: displays the cart
void displayCost(ShoppingCart& cart, int pos);
//input: none
//output: none
//side effects: displays cost of the cart/csrt item
void displayNumber(ShoppingCart& cart);
//input:none
//output: none
//side effects: displays number of items in the cart
void remove(ShoppingCart& cart,int pos);
//input: none
//output: none
//side effects: removes an item from the cart
int main(){
    ShoppingCart myCart;
    ifstream myfile(getFileInput());
    runFileCommands(myfile,myCart);
    return 0;
}






ifstream getFileInput(){
    cout<<"Enter file name: "<<endl;
    string test;
    getline(cin,test);
    ifstream myfile(test);
    return myfile;
}
void runFileCommands(ifstream& myfile,ShoppingCart& cart){
    string line;
    if(myfile.is_open()){
        while(getline(myfile,line)){
            istringstream iss(line);
                string subs;
                iss >> subs;
            if(subs == "A"){
                string description;
                int quant;
                double price;
                int pos=0;
//                cout<<"Reached here"<<endl;
                iss >> description>>quant>>price>>pos;
                ItemToPurchase item(description,price,quant);
                if (pos>100){
                    pos =0;
                }
                insert(item,cart, pos);
            }else if(subs == "D"){
                int pos;
                iss >>pos;
                display(cart,pos);
            }else if(subs == "DA"){
                int pos = 0;
                display(cart,pos);
            }else if(subs == "R"){
                int pos;
                iss >>pos;
                remove(cart,pos);
            }else if(subs == "DC"){
                int pos;
                if (iss.str()=="DC"){
                    pos = 0;
                }else{
                    //cout<<iss.str()<<endl;
                    iss >> pos;
                }
            //    cout<<endl;
                displayCost(cart,pos);
            }else if(subs == "DN"){
                displayNumber(cart);
            }else{
                cout<<"Invalid command. Moving on"<<endl;
            }
                    
            }
        cout<<endl<<"Exiting program"<<endl;
    }
}


void insert(ItemToPurchase item, ShoppingCart& cart, int pos){
    if (pos==0){
//        cout<<"Also got here"<<endl;
        cart.add(item);
    }else{
        cart.add(item,pos);
    }
}

void display(ShoppingCart& cart,int pos){
    if(pos ==0){
        cart.display();
    }else{
        if (cart.IsValid(pos)){
            cout<<"At position "<<pos<<" "<<cart.getItem(pos)<<endl;
        }
    }
}


void displayCost(ShoppingCart& cart, int pos){
    
    if(pos ==0){
//        cout<<"got here"<<endl;
        cout<<"This is the total cost: $"<<cart.totalCost()<<endl;
    }else{
        if (cart.IsValid(pos)){
            cout<<"At position "<<pos<<" Item costs "<<cart.ItemCost(pos)<<endl;
        }
    }
}

void displayNumber(ShoppingCart& cart){
    cout<<"The number of items in your cart is "<<cart.getLength()<<endl;
}

void remove(ShoppingCart& cart,int pos){
    cart.remove(pos);
}


