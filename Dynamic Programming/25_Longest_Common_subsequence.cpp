


#include<bits/stdc++.h>

// rec+memo

int f(int ind1,int ind2,string s1,string s2,vector<vector<int>>& dp){
	
	if(ind1<0 || ind2<0) return 0;
	if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = 1+f(ind1-1,ind2-1,s1,s2,dp);
	
	return dp[ind1][ind2] =  max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
}

int lcs(string s, string t)
{
	int n1 = s.size();
	int n2 = t.size();
	vector<vector<int>> dp(n1,vector<int> (n2,-1));
	
	
	return f(n1-1,n2-1,s,t,dp);
}


// to convert about code into tabulation format it is difficuilt to convert 
// so we will use shifting of index
// after index shifting our code lookes like below code

// rec+memo + idx shifted



int f(int ind1,int ind2,string s1,string s2,vector<vector<int>>& dp){
	
	if(ind1==0 || ind2==0) return 0;
	if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	if(s1[ind1-1] == s2[ind2-1]) return dp[ind1][ind2] = 1+f(ind1-1,ind2-1,s1,s2,dp);
	
	return dp[ind1][ind2] =  max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
}

int lcs(string s, string t)
{
	int n1 = s.size();
	int n2 = t.size();
	vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
	
	
	return f(n1,n2,s,t,dp);
}

// tabulation 


int lcs(string s, string t)
{
	int n1 = s.size();
	int n2 = t.size();
	vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
	
	for(int i=0;i<=n1;i++) dp[i][0] = 0;
	for(int j=0;j<=n2;j++) dp[0][j] = 0;
	
	for(int ind1=1;ind1<=n1;ind1++){
		for(int ind2=1;ind2<=n2;ind2++){
			if(s[ind1-1] == t[ind2-1])  dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
	
			else dp[ind1][ind2] =  max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
		}
	}
	return dp[n1][n2];
}

// space optimization 

int lcs(string s, string t)
{
	int n1 = s.size();
	int n2 = t.size();
// 	vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
	
	vector<int> prev(n2+1,0),cur(n2+1,0);
	
	// for(int j=0;j<=n2;j++) prev[j] = 0;
	
	for(int ind1=1;ind1<=n1;ind1++){
		for(int ind2=1;ind2<=n2;ind2++){
			if(s[ind1-1] == t[ind2-1])  cur[ind2] = 1+prev[ind2-1];
	
			else cur[ind2] =  max(prev[ind2],cur[ind2-1]);
		}
		prev = cur;
	}
	return prev[n2];
}