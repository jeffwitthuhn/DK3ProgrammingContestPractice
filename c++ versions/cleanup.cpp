//example problem 7
#include <fstream>
#include <iostream>
#include <vector> 
#include <string>
using namespace std; 
struct player{
	string name; 
	int hits; 
	int bats;
	double average; 

	//bool operator < (player const& lhs, player const& rhs){
	//	return (lhs.average<rhs.average? true : false);
	//}
	/* //code mysteriously worked only some of the time when I used this. 
	player operator = (player const& rhs){
		this->name=rhs.name;
		this->hits=rhs.hits;
		this->bats=rhs.bats;
		this->average=rhs.average;
	}
	*/
};
/*
//stable_sort(myvector.begin(), myvector.end(), comparePlayers);

bool comparePlayers(player const& lhs, player const& rhs){
	return lhs.average<rhs.average;
}
*/
int main(){
	ifstream infile("CleanIn.txt"); 
	ofstream outfile("CleanOut.txt"); 
	

	for(int z=0; z<2; z++){
		double bestAverage=0;
		int bestIndex=-1; 
		int hits, bats; 
		vector<player> temp;
		temp.resize(2);
		vector<player> players;
		players.resize(9);
		for(int i=0; i<9; i++){
			infile>>players[i].name>>players[i].hits>>players[i].bats;
		}
		for(int i=0; i<9; i++){
			infile>>hits>>bats;
			players[i].hits+=hits;
			players[i].bats+=bats;
			players[i].average=((double)players[i].hits)/players[i].bats;



		}
		for(int i=0; i<9; i++){
			if(players[i].average>bestAverage){

				bestAverage=players[i].average;
				bestIndex=i;
			}
		}
		if(bestIndex==1||bestIndex==2||bestIndex==0){
			//temp[0]=players[3];
			temp[0].name=players[3].name;
			temp[0].hits=players[3].hits;
			temp[0].bats=players[3].bats;
			temp[0].average=players[3].average;
			//players[3]=players[bestIndex];
			players[3].name=players[bestIndex].name;
			players[3].hits=players[bestIndex].hits;
			players[3].bats=players[bestIndex].bats;
			players[3].average=players[bestIndex].average;
			//players[bestIndex]=temp[0];
			players[bestIndex].name=temp[0].name;
			players[bestIndex].hits=temp[0].hits;
			players[bestIndex].bats=temp[0].bats;
			players[bestIndex].average=temp[0].average;

		}
		else if(bestIndex>3&&bestIndex<9){
			//temp[0]=players[3];
			temp[0].name=players[3].name;
			temp[0].hits=players[3].hits;
			temp[0].bats=players[3].bats;
			temp[0].average=players[3].average;
			//players[3]=players[bestIndex];
			players[3].name=players[bestIndex].name;
			players[3].hits=players[bestIndex].hits;
			players[3].bats=players[bestIndex].bats;
			players[3].average=players[bestIndex].average;
			for(int i=4; i<=bestIndex; i++){
				//temp[1]=players[i];
				temp[1].name=players[i].name;
				temp[1].hits=players[i].hits;
				temp[1].bats=players[i].bats;
				temp[1].average=players[i].average;

				//players[i]=temp[0];
				players[i].name=temp[0].name;
				players[i].hits=temp[0].hits;
				players[i].bats=temp[0].bats;
				players[i].average=temp[0].average;

				//temp[0]=temp[1];
				temp[0].name=temp[1].name;
				temp[0].hits=temp[1].hits;
				temp[0].bats=temp[1].bats;
				temp[0].average=temp[1].average;

			}


		}
		else cout<<"error\n";

		for(int i=0; i<9; i++){
			outfile<<players[i].name<<endl;
			cout<<players[i].name<<endl;
		}

		outfile<<endl;
		cout<<endl;
	}
	outfile.close();
	infile.close();
	return 0;
}