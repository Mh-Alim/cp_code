// here coins supply is infinite

// rec + memo


int f(int ind,int tar,vector<int> &num,vector<vector<int>> &dp){
	
	if(ind == 0) {
		if(tar%num[ind] == 0) return tar/num[ind];
		return 1e8;
	}
	if(dp[ind][tar] != -1) return dp[ind][tar];
	
	int notTake = f(ind-1,tar,num,dp);
	int take = INT_MAX;
	if(tar>=num[ind]) take = 1+f(ind,tar-num[ind],num,dp);
	
	return dp[ind][tar] = min(take,notTake);
}

int minimumElements(vector<int> &num, int x)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans = f(n-1,x,num,dp);
	
	if(ans>=1e8) return -1;
	return ans;
}


// tabulation


int minimumElements(vector<int> &num, int x)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(x+1,0));
    
	for(int i=0;i<=x;i++){
		if(i%num[0] == 0) dp[0][i] = i/num[0];
		else dp[0][i] = 1e8;
	}
	
	for(int ind = 1;ind<n;ind++){
		for(int tar = 0;tar<=x;tar++){
			int notTake = dp[ind-1][tar];
			int take = 1e8;
			if(tar>=num[ind]) take = 1+dp[ind][tar-num[ind]];

			dp[ind][tar] = min(take,notTake);
		}
	}
	
	if(dp[n-1][x] >= 1e8) return -1;
	return dp[n-1][x];
}

 // two row space optimization 

 int minimumElements(vector<int> &num, int x)
{
	int n = num.size();
	
	vector<int> prev(x+1,0),cur(x+1,0);
    
	for(int i=0;i<=x;i++){
		if(i%num[0] == 0) prev[i] = i/num[0];
		else prev[i] = 1e8;
	}
	
	for(int ind = 1;ind<n;ind++){
		for(int tar = 0;tar<=x;tar++){
			int notTake = prev[tar];
			int take = 1e8;
			if(tar>=num[ind]) take = 1+cur[tar-num[ind]];

			cur[tar] = min(take,notTake);
		}
		prev = cur;
	}
	
	if(prev[x] >= 1e8) return -1;
	return prev[x];
}

