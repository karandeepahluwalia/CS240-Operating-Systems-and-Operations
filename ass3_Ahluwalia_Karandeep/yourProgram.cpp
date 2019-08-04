#include "Stack.h"
#import <string>
#import <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>
using namespace std;


ifstream getFileInput();
//input: user input
//output: ifstream of file
void runFileCommands(ifstream& fileInput,vector<string>& sarray,vector<string>& darray);
//input: stream fileInput, vector holding input string lines, vector holding answer
//output: none
//side effects: responsible for updating the output file based the input file it was given
void updateVector(string& line,vector<string> & sarray,vector<string>& darray);
//input: line from input file, array holding all lines from input,
//line holding the answer
//output: none
//side effects:breaks down each line of the file into the 2 arrays
void outputfile(vector<string> & sarray,vector<string>& darray);
//input: two  string vectors holding each line of input file and the answer to each lines
//output:none
//side effects: Creates an output file with the output desired
string evaluate(string line);
//input:string line
//output: String answer to the line of input given
//side effects: Responsible for computing the numbers in the correct way
int main(){
  vector<string> stringArr;
  vector<string> doubleArr;
//  cout<<"Main started"<<endl;
  ifstream myfile(getFileInput());
//  cout<<"My file opened correctly"<<endl;
  runFileCommands(myfile,stringArr,doubleArr);
  return 0;
}
ifstream getFileInput(){
    cout<<"Enter file name: "<<endl;
    string test;
    getline(cin,test);
    ifstream myfile(test);
    return myfile;
}
void runFileCommands(ifstream& fileInput,vector<string>& sarray,vector<string>& darray){
//  cout<<"Run file commands started"<<endl;
  string line;
  if(fileInput.is_open()){
    while(getline(fileInput,line)){
      updateVector(line,sarray,darray);
    }
    outputfile(sarray,darray);
  }else{
    cout<<"Failed to open file"<<endl;
  }

}
void updateVector(string& line,vector<string> & sarray,vector<string>& darray){
//cout<<"updateVector started"<<endl;
  sarray.push_back(line);
//  cout<<"This is evaluate line"<<endl;
  string tester = evaluate(line);
//  cout<<tester<<endl;
  darray.push_back(tester);
}

void outputfile(vector<string> & sarray,vector<string>& darray){
//cout<<"Output file "<<endl;
ofstream out;
out.open("output.txt");
for(int i =0;i<sarray.size();i++){
    string words;
    istringstream iss(sarray.at(i));
    while(iss>>words){
      out<<words<<" ";
    }
    out<<"is "<<darray.at(i)<<endl;
  }
  out.close();
  cout<<"Output file created"<<endl;
}

string evaluate(string line){
//  cout<<"evaluate started"<<endl;
  Stack numbers;
  string subs;
  istringstream iss(line);
  while(iss>>subs){
    if(isdigit(subs.at(0))){
      numbers.Push(subs);
    }else{
//        cout<<"Operand:    "<<subs<<endl;
        string operand = subs;
        double top = -1000.0;
        double second = -1000.0;
        istringstream streams(numbers.Pop());
        streams>>top;
        istringstream streamer(numbers.Pop());
        streamer>>second;
//        cout<<second<<"      "<<top<<endl;
        if(operand=="*"){
          ostringstream streamed;
          streamed<<(top*second);
//          cout<<"     *   "<<endl;
          numbers.Push(streamed.str());
        }else if(operand=="-"){
          ostringstream streamed;
          streamed<<(second-top);
//          cout<<"     -   "<<endl;
          numbers.Push(streamed.str());
        }else if(operand=="+"){
          ostringstream streamed;
          streamed<<(top+second);
//          cout<<"     +   "<<endl;
          numbers.Push(streamed.str());
        }else if(operand =="/"){
          ostringstream streamed;
          streamed<<(second/top);
//          cout<<"     /   "<<endl;
          numbers.Push(streamed.str());
        }
      }
    }
    return numbers.Pop();
  }
