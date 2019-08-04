#include "CallCenter.h"
#include "Call.h"
#include "PriorityQueue.h"
#import <string>
#import <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>
using namespace std;

void getUserInput(int& timeLimit,double& prob);
//input: user input
//output: none
//side effect: validates user input and updates correct variables with it
//Precondition: User input must be correct or code will abort
Call generateCall(const int& timer);
//input: int timer
//output: Call object holding the time
void runCallCenter(int& timeLimit,double& prob,CallCenter& center);
//input:int timeLimit, double prob, Callcenter object
//output: none
//side effects: decrements timeLimit,uses probability to generate Calls,
//              updates Callcenter every minute
void display(CallCenter& center);
//input: CallCenter object
//output:none
//side effects: displays the end results of the simulation
int main(){
  int timeLimit = -1;
  double prob = -1;
  srand(time(0));
  CallCenter center;
  getUserInput(timeLimit,prob);
  runCallCenter(timeLimit,prob,center);
  return 0;
}
void getUserInput(int& timeLimit,double& prob){
  cout<<"What is the number of minutes CallCenter accepts calls?(Mu";
  cout<<"st be a positive number): ";
  cin>>timeLimit;
  assert(timeLimit>0);
  cout<<endl<<"What is the probability of a phone call arriving?: ";
  cin>>prob;
  assert(prob>=0.1&&prob<=1);
}
Call generateCall(const int& timer){
  Call newcall(timer);
  return newcall;
}
void runCallCenter(int& timeLimit,double& prob,CallCenter& center){
//  cout<<"This is point a"<<endl;
  int checker = timeLimit%5;
  int timer = 0;
  while(timeLimit>0){
    timer++;
    double temp = ((double) rand() / (RAND_MAX));
    if (temp<=prob){
//      cout<<"This is point b"<<endl;
      Call tempcall = generateCall(timer);
  //    cout<<"This is point f"<<endl;
      center.updateCenter(tempcall);
    //  cout<<"This is point g"<<endl;
    }
  //  cout<<"This is point c"<<endl;
    center.updateCenter();
    timeLimit--;
    if(timeLimit%5==checker){
  //    cout<<"This is point d"<<endl;
      center.displayStatus();
    }
  }
  cout<<"No longer accepting new calls"<<endl;
  int timecheck = 5-checker;
  while (center.updateCenter()){
//    cout<<"This is point e"<<endl;
    timecheck++;
    if (timecheck%5==0){
      center.displayStatus();
    }
  }
  display(center);
}

void display(CallCenter& center){
  center.display();
}
