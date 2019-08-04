#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;




bool countBlank(int & blanks, string str);
// input: 1 integer value, 1 string value
// output: returns nothing but increments counter if line is blank

void countWords(double& words, double& lines,double& letters, string str);
// input: 1 string, 2 integer values
// output: returns nothing
//side effects: updates the number of words in lines, passes words to countLetters

void countLetters(double& num_1,string str);
// input: 2 integer values and a string value
// output: returns nothing but updates letters in word

void average(double num1,double num2, double& temp);
//input: 3 integer values
//output: the average based on these two numbers

void display(double blanks, double words, double letters);
//input: 3 integer variables
//output: none
//side effects: displays all required information

string getFileName();
//input: none
//output: String of user’s input
void FileOrganizer();
//input: none
//output: none
//side effects: runs all necessary subprograms

int main ( ) {
	FileOrganizer();
 return 0;
}

//**** define the 4 functions whose prototypes appear above ****
bool countBlank(int & blanks, string str){
	if (str.size()!=0){
		for(int i =0;i<str.length();i++){
			if (str.at(i)!= ' '){
				blanks++;
				return true;
			}

		}
		return false;
	}else{
		return false;
	}
}

void countWords(double& words, double& lines,double& letters, string str){
	istringstream iss(str);
	do
    {
        string subs;
        iss >> subs;
				bool check = false;
				for(int i =0;i<str.length();i++){

					if(isalpha(str.at(i))){
					//	cout<<str.at(i)<<endl;
						check = true;
					}
				}
				if(check && subs!="/"){
					//cout<<subs<<endl;

	        words++;
				}
        countLetters(letters,subs);
        }while (iss);
				words--;
}


void countLetters(double& num_1,string str){
	for(int i =0;i<str.length();i++){
		if(isalpha(str.at(i))&&str!="/"){
			num_1++;
			//cout<<str.at(i)<<"      "<<num_1<<endl;
		}
	}
}
void average(double num1,double num2, double& temp){
	//cout<<num1<<"      "<<num2<<endl;
	temp = num1/num2;
}

void display(double blanks, double words, double letters){
	cout<<"There are "<<blanks<<" non-blank lines"<<endl;
	cout<<"There are an average of "<<words<<" words per line."<<endl;
	cout<<"There are an average of "<<letters<<" letters per word."<<endl;
}

string getFileName(){
	cout<<"Enter file name: "<<endl;
	string test;
	getline(cin,test);
	return test;
}
void FileOrganizer(){
	int blanks = 0;
	double numLine = 0;
	double numWord = 0;
	double numLetter = 0;
	double averageWord = 0;
	double averageLetter = 0;
	string userInput;
	userInput = getFileName();
	ifstream myfile(userInput);
	string line;
	if(myfile.is_open()){
		while(getline(myfile,line)){
			if (countBlank(blanks,line)){
			//	cout<<line<<endl;
				countWords(numWord,numLine,numLetter, line);
			}
			average(numWord,blanks,averageWord);
			average(numLetter, numWord, averageLetter);
		}
			display(blanks,averageWord,averageLetter);
	}
}
