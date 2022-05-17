#include<bits/stdc++.h>
using namespace std;

int jump(int idx,vector<int> &h,vector<int> &dp){
	if(idx == 0) return 0;
	if(dp[idx] != -1) return dp[idx];
	int left = jump(idx-1,h,dp)+abs(h[idx]-h[idx-1]) ;
	int right = INT_MAX;
	if(idx>1)  right = jump(idx-2,h,dp) + abs(h[idx]-h[idx-2]);
	
	return dp[idx] = min(left,right);
	
	
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
	return jump(n-1,heights,dp);
}