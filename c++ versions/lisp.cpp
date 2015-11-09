//example problem 9
#include <fstream>
#include <iostream>
#include <vector> 
using namespace std; 
int main(){
	ifstream infile("LispIn.txt"); 
	ofstream outfile("LispOut.txt"); 
	for(int z=0; z<2; z++){	
		vector<char> leftparens;
		vector<int> timeofpush;
		timeofpush.resize(0);
		leftparens.resize(0);
		bool found=false;
		int counter=0;
		char c;
		infile.get(c);
		int last_push;
		while(c!='\n'&&!found){
			counter++;
			switch(c){
				case '(': 
					cout<<c;
					last_push=counter;
					timeofpush.push_back(counter);
					leftparens.push_back(c);
					break;
				case ')': 
					cout<<c;
					if(leftparens.size()>0){
						leftparens.pop_back();
						timeofpush.pop_back();

					}
					else {
						outfile<<counter<<endl;
						cout<<counter<<endl;
						found=true;
						cout<<"a";
					}
					break;

			}
			if(infile.peek()==EOF)
				break;
			infile.get(c);
		}
		if(leftparens.size()>0){
			outfile<<timeofpush[0]<<endl;
			cout<<timeofpush[0]<<endl;
		}
		else {
			outfile<<"OK\n";
			cout<<"OK\n";
		}
	}

	return 0; 
}