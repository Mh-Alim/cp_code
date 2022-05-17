#include<iostream>
#include<queue>
using namespace std;


int main(){


    // this is maxheap
    priority_queue<pair<int,int>> maxh;
    maxh.push({4,5});
    maxh.push({4,5});
    maxh.push({3,9});
    maxh.push({9,1});

    while(!maxh.empty()){
       auto it =  maxh.top();
        maxh.pop();
       cout << it.first << " " << it.second << endl;

    }
    return 0;
}