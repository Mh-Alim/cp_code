
// rec + memp

int f(int ind,int mwt,vector<int> wt,vector<int> val,vector<vector<int>> &dp){
	
	if(ind == 0){
		if(wt[ind]<=mwt) return (mwt/wt[0]) *val[ind];
		return 0;
	}
	if(dp[ind][mwt] != -1) return dp[ind][mwt];
	int notTake = 0+f(ind-1,mwt,wt,val,dp);
	int take = INT_MIN;
	if(wt[ind]<=mwt) take = val[ind]+f(ind,mwt-wt[ind],wt,val,dp);
	
	return dp[ind][mwt] = max(take,notTake);
}



// tabulation 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,0));
	
	for(int prof=0;prof<=w;prof++) {
		dp[0][prof] = (prof/weight[0])*profit[0];
	}
	
	for(int ind =1;ind<n;ind++){
		for(int mwt = 0; mwt<=w; mwt++){
			int notTake = 0+dp[ind-1][mwt];
			int take = INT_MIN;
			if(weight[ind]<=mwt) take = profit[ind]+dp[ind][mwt-weight[ind]];

			dp[ind][mwt] = max(take,notTake);
		}
	}
	return dp[n-1][w];
}


// space optimizaiton ---> two row

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
//     vector<vector<int>> dp(n,vector<int>(w+1,0));
	
	vector<long> prev(w+1,0),cur(w+1,0);
	
	
	for(int prof=0;prof<=w;prof++) {
		prev[prof] = (prof/weight[0])*profit[0];
	}
	
	for(int ind =1;ind<n;ind++){
		for(int mwt = 0; mwt<=w; mwt++){
			int notTake = 0+prev[mwt];
			int take = INT_MIN;
			if(weight[ind]<=mwt) take = profit[ind]+cur[mwt-weight[ind]];

			cur[mwt] = max(take,notTake);
		}
		prev = cur;
	}
	return prev[w];
}

// one row space optimization 

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
//     vector<vector<int>> dp(n,vector<int>(w+1,0));
	
	vector<long> prev(w+1,0);
	
	
	for(int prof=0;prof<=w;prof++) {
		prev[prof] = (prof/weight[0])*profit[0];
	}
	
	for(int ind =1;ind<n;ind++){
		for(int mwt = 0; mwt<=w; mwt++){
			int notTake = 0+prev[mwt];
			int take = INT_MIN;
			if(weight[ind]<=mwt) take = profit[ind]+prev[mwt-weight[ind]];

			prev[mwt] = max(take,notTake);
		}
// 		prev = cur;
	}
	return prev[w];
}

