

// memo
int f(int ind,int mwt,vector<int> wt,vector<int> val,vector<vector<int>> &dp){
	
	if(ind == 0){
		if(wt[ind]<=mwt) return val[ind];
		return 0;
	}
	if(dp[ind][mwt] != -1) return dp[ind][mwt];
	int notTake = 0+f(ind-1,mwt,wt,val,dp);
	int take = INT_MIN;
	if(wt[ind]<=mwt) take = val[ind]+f(ind-1,mwt-wt[ind],wt,val,dp);
	
	return dp[ind][mwt] = max(take,notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}

// tabulation

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	
	for(int i=weight[0];i<=maxWeight;i++){
		dp[0][i] = value[0];
	}
	
	for(int ind=1;ind<n;ind++){
		for(int wt = 0;wt<=maxWeight;wt++){
				int notTake = dp[ind-1][wt];
				int take = INT_MIN;
				if(weight[ind]<=wt) take = value[ind]+dp[ind-1][wt-weight[ind]];

				 dp[ind][wt] = max(take,notTake);
		}
	}
	return dp[n-1][maxWeight];
}


// space optimize code --> two row space optimization

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0),cur(maxWeight+1,0);
	
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i] = value[0];
	}
	
	for(int ind=1;ind<n;ind++){
		for(int wt = 0;wt<=maxWeight;wt++){
				int notTake = prev[wt];
				int take = INT_MIN;
				if(weight[ind]<=wt) take = value[ind]+prev[wt-weight[ind]];

				 cur[wt] = max(take,notTake);
		}
		prev = cur;
	}
	return prev[maxWeight];
}


//one row optimization

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);
	
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i] = value[0];
	}
	
	for(int ind=1;ind<n;ind++){
		for(int wt = maxWeight;wt>=0;wt--){
			
				int notTake = prev[wt];
				int take = INT_MIN;
				if(weight[ind]<=wt) take = value[ind]+prev[wt-weight[ind]];

				 prev[wt] = max(take,notTake);
		}
	}
	return prev[maxWeight];
}