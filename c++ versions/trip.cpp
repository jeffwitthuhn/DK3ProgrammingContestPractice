#include <bits/stdc++.h>

using namespace std;
struct vertex{
	string name; 
};
struct edge {
	string v1;
	string v2;
	int weight;

};
int main(){
	ifstream infile("LessIn.txt"); 
	ofstream outfile("LessOut.txt");
	string str; 
	vector<edge> edges; 
	edges.resize(0);
	string start, end; 
	int distance;
	bool done=false;
	while(!done){
		//loop
		edge temp; 
		getline(infile, str); 
		stringstream strstream(str);
		strstream >> start;
		strstream >> end;
		strstream >> distance;
		cout<<start<<end<<distance<<endl;
		if(distance==0)
			done=true; 
		else {
			temp.v1=start;
			temp.v2=end;
			temp.weight=distance;
			edges.push_back(temp);
		}
	}

	for(int i=0; i<edges.size();i++){
		cout<<edges[i].v1<<" "<<edges[i].v2<<" "<<edges[i].weight<<"\n";
	}

	vector<string> vertices; 
	map<string,int> nametoint; 
	map<int,string> inttoname; 

	vertices.resize(0);
	int count=0;
	string temp;
	for(int i=0; i<edges.size();i++){
		temp=edges[i].v1;
		if(std::find(vertices.begin(), vertices.end(), temp) != vertices.end()) {
				//do nothing
						} else {

							vertices.push_back(temp);
							nametoint.insert(make_pair(temp, count)).second;
							inttoname.insert(make_pair(count, temp)).second;

							//cout<<temp<<count;
							count++;
					}
	}
	for(int i=0; i<edges.size();i++){
		temp=edges[i].v2;
		if(std::find(vertices.begin(), vertices.end(), temp) != vertices.end()) {
				//do nothing
						} else {

							vertices.push_back(temp);
							nametoint.insert(make_pair(temp, count)).second;
							inttoname.insert(make_pair(count, temp)).second;
							//cout<<temp<<count;
							count++;
					}
	}
	cout<<"start is: " << nametoint[start]<<" "<<start<<endl;
	cout<<"end is: " << nametoint[end]<<" "<<end<<endl;


	for(int i=0; i<vertices.size();i++){
		outfile<<nametoint[vertices[i]]<<" "<<inttoname[i]<<endl;
	}
	cout<<endl;
	vector<bool> visited;
	vector<int> previous; 
	previous.resize(vertices.size());
	visited.resize(vertices.size());
	priority_queue<int, vector<int>, greater<int> > q;
	return 0; 
}