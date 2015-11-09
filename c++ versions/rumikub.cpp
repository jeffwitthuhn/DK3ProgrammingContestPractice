//example problem 6
#include <fstream>
#include <iostream>
#include <vector> 
#include <bits/stdc++.h>
//#include <string>
using namespace std; 
struct tile{
	char color; 
	int number; 
};
int main(){
	ifstream infile("RummikubIn.txt"); 
	ofstream outfile("RummikubOut.txt"); 
	unsigned long long inputs; 
	//string dummy; 
	infile>>inputs; 
	char c; 	
	infile.get(c);//consume endline
	//getline(infile, dummy);
	for(int z=0; z<inputs; z++){
	vector<tile> hand; 
	hand.resize(14);

		for(int i=0; i<14; i++){
			infile.get(c); 
			hand[i].color=c; 
			infile.get(c);
			hand[i].number=c-'0';
			infile.get(c);
			if (infile&&c!=' '&&c!='\n'){
				hand[i].number=hand[i].number*10+c-'0';
				infile.get(c);
			}

		}
		//getline(infile, dummy); consumes rest of line
		//initialize record keeping
		int bestScore=0; 
		vector<int> runindices; 
		vector<int> groupindices;
		runindices.resize(14);
		groupindices.resize(4);
		for(int i=0; i<14; i++)
			runindices[i]=-1;
		for(int i=0; i<4; i++)
			groupindices[i]=-1;
		vector<int> bestrunindices; 
		vector<int> bestgroupindices;
		bestrunindices.resize(14);
		bestgroupindices.resize(4);
		for(int i=0; i<14; i++)
			bestrunindices[i]=-1;
		for(int i=0; i<4; i++)
			bestgroupindices[i]=-1;
		//search for group
		int groupCount;
		int runCount;
		int score;
		bool isGroup=false;
		bool isRun=false;
		bool groupIsHigher=false;;
		for(int i=0; i<14; i++){
			for(int j=0; j<4; j++)
				groupindices[j]=-1;
			groupCount=0;
			groupindices[groupCount++]=i;
			for(int j=i; j<14; j++){
				if(hand[j].color!=hand[i].color&&hand[j].number==hand[i].number)
					groupindices[groupCount++]=j;
				if(groupCount>3)
					break;
			}
			if(groupCount>2){
				isGroup=true;
				score=0;
				for(int j=0; j<groupCount;j++)
					score+=hand[groupindices[j]].number;
				if(score>bestScore){
					groupIsHigher=true;
					bestScore=score;
					bestgroupindices=groupindices;
				}

			}
		}
		bool nextFound;
		for(int i=0; i<14; i++){
			for(int j=0; j<14; j++)
				runindices[j]=-1;
			runCount=0;
			runindices[runCount++]=i;
			do{
				nextFound=false;
				for(int j=0; j<14; j++){
					if(hand[j].color==hand[i].color&&hand[j].number==(hand[i].number+runCount)){
						runindices[runCount++]=j;
						nextFound=true;
					}
				}
			}while(nextFound);
			if(runCount>2){
				isRun=true;
				score=0;
				for(int j=0; j<runCount;j++)
					score+=hand[runindices[j]].number;
				if(score>bestScore){
					groupIsHigher=false;
					bestScore=score;
					bestrunindices=runindices;
				}

			}
		}
		if(isGroup&&groupIsHigher){
			vector<int> sorted;
			sorted.resize(4);
			for(int i=0; i<4; i++)
				sorted[i]=-1;
			for(int i=0; i<4; i++)
				switch(hand[bestgroupindices[i]].color){
					case 'A': sorted[0]=bestgroupindices[i]; break;
					case 'B': sorted[1]=bestgroupindices[i]; break;
					case 'C': sorted[2]=bestgroupindices[i]; break;
					case 'D': sorted[3]=bestgroupindices[i]; break;
			}
			bestgroupindices=sorted;
			for(int i=0; i<4; i++)
				if(bestgroupindices[i]>-1){
					cout<<hand[bestgroupindices[i]].color<<hand[bestgroupindices[i]].number<< " ";
					outfile<<hand[bestgroupindices[i]].color<<hand[bestgroupindices[i]].number<< " ";
				}
			
			outfile<< bestScore<<endl;
			cout<< bestScore<<endl;
		}
		else if(isRun&&!groupIsHigher){
			for(int i=0; i<14; i++)
				if(bestrunindices[i]>-1){
					cout<<hand[bestrunindices[i]].color<<hand[bestrunindices[i]].number<< " ";
					outfile<<hand[bestrunindices[i]].color<<hand[bestrunindices[i]].number<< " ";
					
				}
			cout<< bestScore<<endl;
			outfile<< bestScore<<endl;
		}
		else if(!isRun&&!isGroup){
			cout<<"NO GROUPS OR RUNS\n";
			outfile<<"NO GROUPS OR RUNS\n";
		}
		else {
			cout<<"error";
			outfile<<"error";
		}

	}

	return 0; 
}