//example problem 2
#include <fstream>
#include <iostream>
#include <vector> 
using namespace std; 

int main(){
	ifstream infile("AntIn.txt"); 
	ofstream outfile("AntOut.txt"); 
	for(int z=0; z<2; z++){	
		unsigned long long int steps; 
		infile >> steps; 
		vector < vector < bool > > Grid; 
		Grid.resize(steps);
		for(int i=0; i<steps; i++)
			Grid[i].resize(steps);

		//initialize grid;
		//0 is white, 1 is black
		for(int i=0; i<steps; i++)
			for(int j=0; j<steps; j++)
				Grid[i][j]=0;

		cout<<"grid read from file: \n";
		for(int i=0; i<steps; i++){
			for(int j=0; j<steps; j++)
				cout << Grid[i][j]<<" ";
			cout<<endl;
		}
		unsigned long long int blackCount=0;
		unsigned long long int row=steps/2;
		unsigned long long int column=steps/2;
		int direction=0; //UDLR <=> 0123
		for(int i=0; i<steps; i++){
			if(Grid[row][column]){//1, black
				//flip square, rotate 90 degrees CCW and move
				Grid[row][column]=0;
				blackCount--;

				if(direction==0){//up
					direction=2;
					column--; 
				}
				else if(direction==1){//down
					direction=3;
					column++;
				}
				else if(direction==2){//left
					direction=1;
					row--;
				}
				else{ //right
					direction=0;
					row++;
				}

			}

			else {//0, white
				Grid[row][column]=1;
				blackCount++;
				if(direction==0){//up
					direction=3;
					column++; 
				}
				else if(direction==1){//down
					direction=2;
					column--;
				}
				else if(direction==2){//left
					direction=0;
					row++;
				}
				else{ //right
					direction=1;
					row--;
				}

			}



		}
	outfile << blackCount << endl;
	cout << "black squares: "<< blackCount << endl;

	}
	return 0; 
}