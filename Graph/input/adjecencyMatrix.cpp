#include<iostream>
#include<vector>
using namespace std;

// adjacency matrix to take input of a graph;

int main(){

    int n = 5;
    int row = n;
    int col = n;
    vector<vector<int>> vect( row ,vector<int> (col,0));

    for(int i=0;i<2;i++){
        int u,v;
        cin>>u>>v;
        vect[u][v] = 1;
        vect[v][u] = 1;
    }

    for(int i=0;i<vect.size();i++){
        for(int j=0;j<vect[i].size();j++){
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}