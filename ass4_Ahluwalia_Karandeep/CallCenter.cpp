#include "Call.h"
#include "PriorityQueue.h"
#include "CallCenter.h"
#include <string>
#include <iostream>
using namespace std;

CallCenter::CallCenter(){
  timer = 0;
  callnumber = 0;
  numberone =0;
  numbertwo =0;
  numberthree = 0;
  avgPOne = 0;
  avgPtwo = 0;
  avgPthree = 0;
}
bool CallCenter::updateCenter(Call &caller){
  callnumber++;
  int temp = caller.getPriority();
  if(temp==1){
    numberone++;
  }else if(temp==2){
    numbertwo++;
  }else{
    numberthree++;
  }
//  cout<<"This is point h"<<endl;
  waitlist.Enqueue(caller);
//  cout<<"This is point i"<<endl;
  return true;
}
bool CallCenter::updateCenter(){
  timer++;
    if (top.getCallTime() <1){
      if (waitlist.getLength()==0){
        return false;
      }else{
        top = waitlist.Dequeue();
        int temp = top.getPriority();
        if(temp==1){
          avgPOne =  timer - top.getTime();
        }else if(temp==2){
          avgPtwo =  timer - top.getTime();
        }else if(temp == 3){
          avgPthree =  timer - top.getTime();
      }
    }
  }
    top.DecreaseQuantity();
    return true;
  }

void CallCenter::display(){
  double tempWait = (avgPOne+ avgPtwo + avgPthree)/callnumber;
  cout<<"End of simulation"<<endl;
  cout<<"This is the total of calls entered and answered: "<<callnumber<<endl;
  cout<<"This is total time taken to answer all calls: "<<timer<<endl;
  cout<<"This is the average wait time for a call to be answered: ";
  if (callnumber!=0){
    cout<<tempWait<<endl;
  }else{
    cout<<"No calls"<<endl;
  }
  cout<<"This is the average wait time for a Priority one call to be answered: ";
  if (numberone!= 0){
    cout<<avgPOne/numberone<<endl;
  }else{
    cout<<"No Priority one calls"<<endl;
  }
  cout<<"This is the average wait time for a Priority two call to be answered: ";
  if (numbertwo!= 0){
    cout<<avgPtwo/numbertwo<<endl;
  }else{
    cout<<"No priority two calls"<<endl;
  }
  cout<<"This is the average wait time for a Priority three call to be answered: ";
  if (numberthree!= 0){
    cout<<avgPthree/numberthree<<endl;
  }else{
    cout<<"No priority three calls"<<endl;
  }
}
void CallCenter::displayStatus(){
  cout<<"Simulation Update:"<<endl;
  cout<<"Minutes into the simulation: "<<timer<<endl;
  cout<<"Calls in the Waiitng List: "<<waitlist.getLength()<<endl;
  cout<<"Calls that have been answered: "<<callnumber - waitlist.getLength()-1<<endl;
  cout<<endl<<endl;
}
