// Recursion + Memoization


int f(int ind,int tar,vector<int>&num,vector<vector<int>> &dp){
	if(tar==0) return 1;
	if(ind == 0) return (num[0] == tar);
	if(dp[ind][tar] != -1) return dp[ind][tar];
	int notTake = f(ind-1,tar,num,dp);
	int take = 0;
	if(tar>=num[ind]) take = f(ind-1,tar-num[ind],num,dp);
	
	
	return dp[ind][tar]  = take+notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,-1));
	return f(n-1,tar,num,dp);
}

// if in our array we can also take 0 then this above code will give me wrong ans .....
// {0,0,1} --> for this type of cases base case will change
// base case will be like this 
// above target vala base case will be removed 
// the one and only base case will be 

/*
if(ind == 0){
	if(tar == 0 and num[0] == 0) return 2;
	if(tar == 0 || num[0] == tar) return 1;
	return 0;
}
*/

// Tabulation


int findWays(vector<int> &num, int tar)
{
    int n = num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,0));
	
	
	for(int i=0;i<n;i++) dp[i][0] = 1;
	if(num[0]<=tar) dp[0][num[0]] = 1;
	for(int ind =1;ind<n;ind++){
		for(int target =0;target<=tar;target++){
			int notTake = dp[ind-1][target];
			int take = 0;
			if(target>=num[ind]) take = dp[ind-1][target-num[ind]];


			dp[ind][target]  = take+notTake;
		}
	}
	
	return dp[n-1][tar];
}