#include<bits/stdc++.h>
using namespace std;

// my optimized code 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	for(int i = n-2;i>=0;i--){
		for(int j = i;j>=0;j--){
			int d = triangle[i][j] + triangle[i+1][j];
			int dg = triangle[i][j] + triangle[i+1][j+1];
			
			int cur = min(d,dg);
			triangle[i][j] = cur;
		}
	}
	return triangle[0][0];
}