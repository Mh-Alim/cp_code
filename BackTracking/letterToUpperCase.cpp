#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;


void solve(int i,int j,vector<vector<int>> &vect,vector<vector<int>> &vis,int &cans){
    
    if(i>0 && vis[i-1][j] == 0 && vect[i-1][j] != 0){
        vis[i-1][j] = 1;
        cans += vect[i-1][j];
        solve(i-1,j,vect,vis,cans);
        cans -= vect[i-1][j];
        vis[i-1][j] = 0;
    }

    if(i<vect.size()-1 && vis[i+1][j] == 0 && vect[i+1][j] != 0){
        vis[i+1][j] = 1;
        cans+= vect[i+1][j];
        solve(i+1,j,vect,vis,cans);
        cans -= vect[i+1][j];
        vis[i+1][j] = 0;
    }
    
    if(j>0 && vis[i][j-1] == 0 && vect[i][j-1] != 0){
        vis[i][j-1] = 1;
        cans+= vect[i][j-1];
        solve(i,j-1,vect,vis,cans);
        cans -= vect[i][j-1]; 
        vis[i][j-1] = 0;
    }
    if(j<vect[0].size()-1 && vis[i][j+1] == 0 && vect[i][j+1] != 0){
        vis[i][j+1] = 1;
        cans+= vect[i][j+1];
        solve(i,j+1,vect,vis,cans);
        cans -= vect[i][j+1];
        vis[i][j+1] = 0;
    }
    
    
}


int main(){

    vector<vector<int>> vect 
    {
        {0,6,0},
        {5,8,7},
        {0,9,0}
    };
    vector<vector<int>> vis( vect.size() , vector<int> (vect[0].size(), 0));
    int ans = 0;
    int cans = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if(vect[i][j] != 0){
                vis[i][j] = 1;
                cans += vect[i][j];
                solve(i,j,vect,vis,cans);
                ans = max(ans,cans);
                cans -= vect[i][j];
                // cans = 0;
                vis[i][j] = 0;
            }
        }   
        cout << endl;
    }

    return 0;
}