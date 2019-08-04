#ifndef CallCenter__
#define CallCenter__
#include <iostream>
#include <string>
#include "Call.h"
#include "PriorityQueue.h"
using namespace std;
class CallCenter{
	public:
		CallCenter();
		//Constructor
		bool updateCenter(Call &call);
		//Adds a new Call to PriorityQueue
		void display();
		//displays the end result of the program
		void displayStatus();
		//displays the update for the program
		bool updateCenter();
		//decrements the top of the queue's calltime and if empty, pops the next in
		//its place


//		friend ostream& operator<<(ostream & out, const ItemToPurchase & f);
	private:
		PriorityQueue waitlist;
		Call top;
		double timer;
		double callnumber;
		double avgPOne;
		double avgPtwo;
		double avgPthree;
		double numberone;
		double numbertwo;
		double numberthree;

};

#endif
