#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <utility>



using namespace std;

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};


int main(){
	priority_queue<pair<int,int>, vector<pair<int,int> >, CompareDist> q;
	return 0;

}