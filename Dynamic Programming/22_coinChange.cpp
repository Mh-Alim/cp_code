#include<bits/stdc++.h> 
long f(int ind,int tar,int *a,vector<vector<long>> &dp){
	
	if(ind == 0){
		return (tar % a[0] == 0);
	}
	if(dp[ind][tar] != -1) return dp[ind][tar];
	long notTake = f(ind-1,tar,a,dp);
	long take = 0;
	if(tar >= a[ind]) take = f(ind,tar-a[ind],a,dp);
	
	return  dp[ind][tar] = take+notTake;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
	vector<vector<long>> dp(n,vector<long> (value+1,-1));
    return f(n-1,value,denominations,dp);
}


// tabulation 

long countWaysToMakeChange(int *a, int n, int value)
{
	vector<vector<long>> dp(n,vector<long> (value+1,0));
	
	for(int tar=0;tar<=value;tar++){
		if(tar%a[0] == 0) dp[0][tar] = 1;
	}
	
	for(int ind = 1;ind<n;ind++){
		for(int tar=0;tar<=value;tar++){
			long notTake = dp[ind-1][tar];
			long take = 0;
			if(tar >= a[ind]) take = dp[ind][tar-a[ind]];

			  dp[ind][tar] = take+notTake;
		}
	}
		return dp[n-1][value];
}


// space optimization 

long countWaysToMakeChange(int *a, int n, int value)
{
// 	vector<vector<long>> dp(n,vector<long> (value+1,0));
	
	vector<long> prev(value+1,0),cur(value+1,0);
	
	for(int tar=0;tar<=value;tar++){
		if(tar%a[0] == 0) prev[tar] = 1;
	}
	
	for(int ind = 1;ind<n;ind++){
		for(int tar=0;tar<=value;tar++){
			long notTake = prev[tar];
			long take = 0;
			if(tar >= a[ind]) take = cur[tar-a[ind]];

			  cur[tar] = take+notTake;
		}
		prev = cur;
	}
		return prev[value];
}
