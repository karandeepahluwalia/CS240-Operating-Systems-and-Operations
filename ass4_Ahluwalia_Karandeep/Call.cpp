#include "Call.h"
#include"time.h"
#include <string>
#include <iostream>
using namespace std;


Call::Call(){
	this->timer = 0;
	this->priority=0;
	this->calltime = 0;
}
Call::Call(int timeTaken){
	this->timer = timeTaken;
	int temp = (rand()+timer) %10;
	if(temp ==0){
		this->priority = 1;
	}else if(temp <4){
		this->priority = 2;
	}else{
		this->priority = 3;
	}
	this->calltime = (rand()+timer)%6+3;
}
int Call::getPriority(){
	return priority;
}
int Call::getTime(){
	return timer;
}
int Call::getCallTime(){
	return calltime;
}
bool Call::DecreaseQuantity(){
//	cout<<"This was calltime"<<calltime<<endl;
	calltime--;
//	cout<<"This is the calltime: "<<calltime<<endl;
	return (calltime<1);
}
bool operator<(Call &call1,Call &call2){
	 return(call1.priority <call2.priority);
}
bool operator>(Call &call1,Call &call2){
	 return(call1.priority > call2.priority);
}
bool operator==(Call &call1,Call &call2){
	 return(call1.priority == call2.priority);
}
bool operator!=(Call &call1,Call &call2){
	 return(call1.priority != call2.priority);
}
bool operator<=(Call &call1,Call &call2){
	 return(call1.priority <=call2.priority);
}
bool operator>=(Call &call1,Call &call2){
	 return(call1.priority >=call2.priority);
}
Call::Call(const Call & called){
	timer = called.timer;
	priority = called.priority;
	calltime = called.calltime;
	//cout<<"Copy called"<<endl;
}


//ostream & operator<<(ostream& out,const ItemToPurchase & f){
//	double price = f.price;
//	int quantity = f.quantity;
//	double total = price*quantity;
//	string info = f.name +" " +to_string(quantity)+ " $" + to_string(price) + " = $"+to_string(total);
//	out<<info;
//	return out;
//}
