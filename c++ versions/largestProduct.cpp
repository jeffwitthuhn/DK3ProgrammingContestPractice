// Example problem 1
#include <fstream>
#include <iostream>
#include <vector> 
using namespace std; 

int main(){
	ifstream infile("GridIn.txt"); 
	ofstream outfile("GridOut.txt"); 
	for(int z=0; z<2; z++){	
		vector<vector <unsigned int> > Grid;
		unsigned int max=0;
		unsigned int height;
		unsigned int width; 
		infile >> height; 
		infile >> width; 
		Grid.resize(height);
		for(int i=0; i<height; i++)
			Grid[i].resize(width);
		//fill grid
		for(int i=0; i<height; i++)
			for(int j=0; j<width; j++)
				infile >> Grid[i][j];
		cout<<"grid read from file: \n";
		for(int i=0; i<height; i++){
			for(int j=0; j<width; j++)
				cout << Grid[i][j]<<" ";
			cout<<endl;
		}
		unsigned int product; 
		//get max horizontal
		for(int i=0; i<height; i++)
			for(int j=3; j<width; j++){
				product = Grid[i][j]*Grid[i][j-1]*Grid[i][j-2]*Grid[i][j-3];
				if(product>max)
					max=product;
			}
		//get max vertical
		for(int i=0; i<width; i++)
			for(int j=3; j<height; j++){
				product=Grid[j][i]*Grid[j-1][i]*Grid[j-2][i]*Grid[j-3][i];
				if(product>max)
					max=product;
			}
		//get max leftright diagonal
		for(int i=3; i<height; i++)
			for(int j=3; j<width; j++){
				product=Grid[i][j-3]*Grid[i-1][j-2]*Grid[i-2][j-1]*Grid[i-3][j];
				if(product>max)
					max=product;
			}
		//get max right left diagonal
		for(int i=3; i<height; i++)
			for(int j=3; j<width; j++){
				product=Grid[i][j]*Grid[i-1][j-1]*Grid[i-2][j-2]*Grid[i-3][j-3];
				if(product>max)
					max=product;
			}
		outfile << max << endl;
		cout << "max is: "<<max<<"\n";
	 }
	return 0; 
}
