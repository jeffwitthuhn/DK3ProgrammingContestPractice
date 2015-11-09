//example problem 4
#include <fstream>
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <string> 
#include <algorithm>
#include <cctype>
#include <clocale>
#include <map>

char easytolower(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
} 
/*
std::string data = "Abc"; 
std::transform(data.begin(), data.end(), data.begin(), ::tolower);
*/
using namespace std; 
//INCOMPLETE
int main(){

	
	ifstream infile("ReductionIn.txt"); 
	ofstream outfile("ReductionOut.txt"); 
	for(int z=0; z<2; z++){	
		vector <string> words; 
		words.resize(0);
		string str; 
		map<string, int> wordtoint;
		getline(infile, str);
		istringstream strstream(str);
		//fill words.
		string temp;
		int count=0;
		while (strstream.peek()!=EOF){
			strstream>>temp;
			for (int i = 0; i < temp.size(); i++)  {
			        if (ispunct(temp[i])){
			            temp.erase(i--, 1);
			        }
			    }
			transform(temp.begin(), temp.end(), temp.begin(), easytolower);
			if(std::find(words.begin(), words.end(), temp) != words.end()) {
				//do nothing
						} else {

							count++;
							words.push_back(temp);
							wordtoint.insert(make_pair(temp, count)).second;
							//cout<<temp<<count;
					}
		}
		istringstream strstream2(str);

		while (strstream2.peek()!=EOF){
			strstream2>>temp;
			for (int i = 0; i < temp.size(); i++)  {
			        if (ispunct(temp[i])){
			            temp.erase(i--, 1);
			        }
			    }
			transform(temp.begin(), temp.end(), temp.begin(), easytolower);
			outfile<<wordtoint[temp]<<" ";
			cout<<wordtoint[temp]<<" ";
		}
		outfile<<endl;
		cout<<endl;


	}

	return 0; 
}