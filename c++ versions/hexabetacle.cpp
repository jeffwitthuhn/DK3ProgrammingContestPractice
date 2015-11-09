//example problem 8
#include <fstream>
#include <iostream>
#include <vector> 
#include <string>
#include <sstream> //string stream
#include <cmath> //pow
#include <algorithm> //sort
using namespace std; 
struct HexNum{
	string number;
	int numberinteger;
};
bool compareHexNum(HexNum left, HexNum right){return left.number<right.number;}
int main(){
	ifstream infile("BobIn.txt"); 
	ofstream outfile("BobOut.txt"); 
	for(int z=0; z<2; z++){	
		string str; 
		vector<int> numbers;
		vector<int> temp; 
		numbers.resize(10000);
		getline(infile, str);
		istringstream strstream(str);

		int in_num;
		int num_counter=0;
		//fill numbers.
		while (strstream.peek()!=EOF){
			strstream>>in_num;
			//if(strstream.peek()!=EOF){
			 num_counter++;
			 if(num_counter>numbers.size()){
			 	temp=numbers;
			 	numbers.resize(temp.size()*2);
			 	for(int i=0; i<temp.size(); i++){
			 		numbers[i]=temp[i];
			 	}
			 }
			 numbers[num_counter-1]=in_num;
			//}
		}
		cout<<"numbers: ";
		for(int i=0; i<num_counter; i++){
			cout<<numbers[i]<<" ";
		}
		cout<<endl;

		//5 digits for numbers < 1,000,000
		//5 masks for digits F0000, 0F000, 00F00, 000F0, 0000F
		//masks in decimal = ‭983040‬, ‭61440‬, ‭3840‬, 360, 16
		vector<HexNum> numbersAsStrings;
		unsigned int first,second,third,fourth,fifth;
		numbersAsStrings.resize(numbers.size());
		for(int i=0; i<numbersAsStrings.size(); i++){
			numbersAsStrings[i].numberinteger=numbers[i];
			numbersAsStrings[i].number="";
			first=(numbers[i]&983040)/pow(16,4);
			switch(first){
				case 0: break;case 1: case 2: case 3: case 4:
				case 5: case 6: case 7: case 8: case 9:
				numbersAsStrings[i].number.append(1,first+'0'); break;
				case 10: numbersAsStrings[i].number.append(1,'A'); break;
				case 11: numbersAsStrings[i].number.append(1,'B'); break;
				case 12: numbersAsStrings[i].number.append(1,'C'); break;
				case 13: numbersAsStrings[i].number.append(1,'D'); break;
				case 14: numbersAsStrings[i].number.append(1,'E'); break;
				case 15: numbersAsStrings[i].number.append(1,'F'); break;
			}
			second=(numbers[i]&61440)/pow(16,3);
			switch(second){
				case 0: break;
				case 1: case 2: case 3: case 4:
				case 5: case 6: case 7: case 8: case 9:
				numbersAsStrings[i].number.append(1,second+'0'); break;
				case 10: numbersAsStrings[i].number.append(1,'A'); break;
				case 11: numbersAsStrings[i].number.append(1,'B'); break;
				case 12: numbersAsStrings[i].number.append(1,'C'); break;
				case 13: numbersAsStrings[i].number.append(1,'D'); break;
				case 14: numbersAsStrings[i].number.append(1,'E'); break;
				case 15: numbersAsStrings[i].number.append(1,'F'); break;
			}
			third=(numbers[i]&3840)/pow(16,2);
			switch(third){
				case 0: break;case 1: case 2: case 3: case 4:
				case 5: case 6: case 7: case 8: case 9:
				numbersAsStrings[i].number.append(1,third+'0'); break;
				case 10: numbersAsStrings[i].number.append(1,'A'); break;
				case 11: numbersAsStrings[i].number.append(1,'B'); break;
				case 12: numbersAsStrings[i].number.append(1,'C'); break;
				case 13: numbersAsStrings[i].number.append(1,'D'); break;
				case 14: numbersAsStrings[i].number.append(1,'E'); break;
				case 15: numbersAsStrings[i].number.append(1,'F'); break;
			}
			fourth=(numbers[i]&240)/pow(16,1);
			switch(fourth){
				case 0: break;case 1: case 2: case 3: case 4:
				case 5: case 6: case 7: case 8: case 9:
				numbersAsStrings[i].number.append(1,fourth+'0'); break;
				case 10: numbersAsStrings[i].number.append(1,'A'); break;
				case 11: numbersAsStrings[i].number.append(1,'B'); break;
				case 12: numbersAsStrings[i].number.append(1,'C'); break;
				case 13: numbersAsStrings[i].number.append(1,'D'); break;
				case 14: numbersAsStrings[i].number.append(1,'E'); break;
				case 15: numbersAsStrings[i].number.append(1,'F'); break;
			}
			fifth=(numbers[i]&15)/pow(16,0);
			switch(fifth){
				case 0: break;case 1: case 2: case 3: case 4:
				case 5: case 6: case 7: case 8: case 9:
				numbersAsStrings[i].number.append(1,fifth+'0'); break;
				case 10: numbersAsStrings[i].number.append(1,'A'); break;
				case 11: numbersAsStrings[i].number.append(1,'B'); break;
				case 12: numbersAsStrings[i].number.append(1,'C'); break;
				case 13: numbersAsStrings[i].number.append(1,'D'); break;
				case 14: numbersAsStrings[i].number.append(1,'E'); break;
				case 15: numbersAsStrings[i].number.append(1,'F'); break;
			}
		}
		for(int i=0; i<num_counter; i++){
			cout<<numbersAsStrings[i].number<<" ";
		}
		cout<<endl;
		numbersAsStrings.resize(num_counter);
	   std:: sort (numbersAsStrings.begin(), numbersAsStrings.end(), compareHexNum); 
	   for(int i=0; i<num_counter; i++){
			cout<<numbersAsStrings[i].number<<" ";
		}
		cout<<endl;
	   for(int i=0; i<num_counter; i++){
			cout<<numbersAsStrings[i].numberinteger<<" ";
		}
		cout<<endl;




	}

	return 0; 
}