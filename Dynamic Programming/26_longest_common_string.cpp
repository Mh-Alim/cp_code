
// tabulation 

int lcs(string &str1, string &str2){
	int n1 = str1.size();
	int n2 = str2.size();
	vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
// 	vector<int> prev(n2+1,0),cur(p)
	
	for(int i=0;i<=n1;i++) dp[i][0] = 0;
	for(int j=0;j<=n2;j++) dp[0][j] = 0;
	
	int ans = 0;
	for(int ind1=1;ind1<=n1;ind1++){
		for(int ind2=1;ind2<=n2;ind2++){
			if(str1[ind1-1] == str2[ind2-1]) {
				 dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
				ans = max(ans,dp[ind1][ind2]);
			}
			else dp[ind1][ind2] = 0;
		}
	}
	return ans;
}


// space optimizaton 

int lcs(string &str1, string &str2){
	int n1 = str1.size();
	int n2 = str2.size();
// 	vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
	vector<int> prev(n2+1,0),cur(n2+1,0);
	
// 	for(int i=0;i<=n1;i++) dp[i][0] = 0;
// 	for(int j=0;j<=n2;j++) dp[0][j] = 0;
	
	int ans = 0;
	for(int ind1=1;ind1<=n1;ind1++){
		for(int ind2=1;ind2<=n2;ind2++){
			if(str1[ind1-1] == str2[ind2-1]) {
				 cur[ind2] = 1+prev[ind2-1];
				ans = max(ans,cur[ind2]);
			}
			else cur[ind2] = 0;
		}
		prev = cur;
	}
	return ans;
}