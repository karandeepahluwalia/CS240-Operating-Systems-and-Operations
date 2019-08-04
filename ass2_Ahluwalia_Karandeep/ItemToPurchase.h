#ifndef ITEMTOPURCHASE
#define ITEMTOPURCHASE
#include <iostream>
#include <string>
using namespace std;
class ItemToPurchase{
	public:
		ItemToPurchase(string name,double price,int quantity);
		ItemToPurchase();
		void SetPrice(double price);
		void SetName(string name);
		void SetQuantity(int quantity);
		string GetName();
		double GetPrice();
        double GetTotal();
		int GetQuantity();
		string GetItemInfo();
		friend ostream& operator<<(ostream & out, const ItemToPurchase & f);
	private:
		string name;
		double price;
		int quantity;
};

#endif
