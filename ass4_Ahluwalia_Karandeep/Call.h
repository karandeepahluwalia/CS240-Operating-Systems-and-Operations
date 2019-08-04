#ifndef call
#define call
#include <iostream>
#include <string>
using namespace std;
class Call{
	public:
		Call(int time);
		//constructor with properly generated data members
		Call();
		//Constructor with 0 in all data members
		Call(const Call & called);
		//Copy constructor
		int getCallTime();
		//returns calltime
		int getPriority();
		//returns priority
		int getTime();
		//returns timer
		bool DecreaseQuantity();
		//decrements calltime
		friend bool operator<(Call &call1,Call &call2);
		//overrides < operator
		friend bool operator<=(Call &call1,Call &call2);
		//overrides <= operator
		friend bool operator>(Call &call1,Call &call2);
		//overrides > operator
		friend bool operator>=(Call &call1,Call &call2);
		//overrides >= operator
		friend bool operator==(Call &call1,Call &call2);
		//overrides == operator
		friend bool operator!=(Call &call1,Call &call2);
		//overrides != operator
//		friend ostream& operator<<(ostream & out, const ItemToPurchase & f);
	private:
		int timer;
		int priority;
		int calltime;
};

#endif
