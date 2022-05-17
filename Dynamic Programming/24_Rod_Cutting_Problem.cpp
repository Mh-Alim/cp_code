// rec + memo



int f(int ind,int maxLeng,vector<int> &price,vector<vector<int>> &dp){
	
	if(ind == 0){
		if(maxLeng >= ind+1)
			return (maxLeng/(ind+1))*price[0];
		return 0;
	}
	if(dp[ind][maxLeng] != -1) return dp[ind][maxLeng];
	int notTake = f(ind-1,maxLeng,price,dp);
	
	int take = -1e9;
	if(maxLeng >= ind+1) take = price[ind] + f(ind,maxLeng-ind-1,price,dp);
	
	return  dp[ind][maxLeng] = max(take,notTake);
}

int cutRod(vector<int> &price, int n)
{
	int maxLength = n;
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return f(n-1,maxLength,price,dp);
}


// tabulation 


int cutRod(vector<int> &price, int n)
{
	int maxLength = n;
	vector<vector<int>> dp(n,vector<int>(n+1,0));
	
	for(int i=0;i<=n;i++){
		dp[0][i] = (i/(0+1))*price[0];
	}
	
	for(int ind =1;ind<n;ind++){
		for(int maxLeng = 0;maxLeng<=n;maxLeng++){
			int notTake = dp[ind-1][maxLeng];
	
			int take = -1e9;
			if(maxLeng >= ind+1) take = price[ind] + dp[ind][maxLeng-ind-1];

			  dp[ind][maxLeng] = max(take,notTake);
		}
	}
	
	return dp[n-1][maxLength];
}


// space optimization ---> two row


int cutRod(vector<int> &price, int n)
{
	int maxLength = n;
// 	vector<vector<int>> dp(n,vector<int>(n+1,0));
	
	vector<int> prev(n+1,0),cur(n+1,0);
	
	for(int i=0;i<=n;i++){
		prev[i] = (i/(0+1))*price[0];
	}
	
	for(int ind =1;ind<n;ind++){
		for(int maxLeng = 0;maxLeng<=n;maxLeng++){
			int notTake = prev[maxLeng];
	
			int take = -1e9;
			if(maxLeng >= ind+1) take = price[ind] + cur[maxLeng-ind-1];

			  cur[maxLeng] = max(take,notTake);
		}
		prev = cur;
	}
	
	return prev[maxLength];
}


// one row space optimization 

