

// tabulation code 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;
	for(int i=0;i<n;i++) totSum += arr[i];
	int k = totSum;
	vector<vector<bool>> dp( n, vector<bool> (k+1,0));
    
	for(int i=0;i<n;i++){
		dp[i][0] = true;
	}
	if(arr[0]<=k) dp[0][arr[0]] = true; 
	for(int ind = 1;ind<n;ind++){
		for(int target = 1;target<=k;target++){
			
			bool notTake = dp[ind-1][target];
			bool take = false;
			if(target>=arr[ind]) take = dp[ind-1][target-arr[ind]];
			
			dp[ind][target] = (notTake | take);
		}
	}
	
	int mini = 1e9;
	for(int i=0;i<=totSum/2;i++){
		if(dp[n-1][i]){
			int s1 = i;
			int s2 = totSum-i;
			mini = min(mini,abs(s2-s1));
		}
	}
	
	return mini;
}
