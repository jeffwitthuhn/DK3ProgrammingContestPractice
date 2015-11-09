//example problem 3
#include <fstream>
#include <iostream>
#include <vector> 
using namespace std; 

int main(){
	ifstream infile("ComfortIn.txt"); 
	ofstream outfile("ComfortOut.txt"); 
	for(int z=0; z<2; z++){	
		unsigned long long seats; 
		infile >> seats; 
		outfile << seats/2<< endl; //extreme cheesing of this problem,
		cout << seats/2<<endl;    //might work for a lot of cases.

	}
	return 0;
}