bool f(int idx,int target,vector<int> &a,vector<vector<int>> &dp){
	if(target == 0) return true;
	if(idx == 0){
		return (a[0] == target);
	}
	if(dp[idx][target] != -1) {
		if(dp[idx][target] == 1) return true;
		else return false;
	}
	
	bool notTake = f(idx-1,target,a,dp);
	
	bool take = false;
	
	if(target>=a[idx]) take = f(idx-1,target-a[idx],a,dp);
	
	return dp[idx][target] = (take || notTake) ;
	
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> dp( n, vector<int> (k+1,-1));
    return f( n-1, k,arr,dp);
}