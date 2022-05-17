

// rec + memo
int f(int i,int j,string s,string t,vector<vector<int>> &dp){


    if(i<0) return j+1;
    if(j<0) return i+1;


	if(dp[i][j] != -1) return dp[i][j];
	if(s[i] == t[j]) return dp[i][j] = f(i-1,j-1,s,t,dp);
	
	int insert = f(i,j-1,s,t,dp);
	int del = f(i-1,j,s,t,dp);
	int rep = f(i-1,j-1,s,t,dp);
	
	return dp[i][j] = 1+min(insert,min(del,rep));
	
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n,vector<int> (m,-1));
	return f(n-1,m-1,str1,str2,dp);
}



// shifted index -> rec+memo


int f(int i,int j,string s,string t,vector<vector<int>> &dp){
	if(i==0) return j;
	if(j==0) return i;
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i-1] == t[j-1]) return dp[i][j] = f(i-1,j-1,s,t,dp);
	
	int insert = f(i,j-1,s,t,dp);
	int del = f(i-1,j,s,t,dp);
	int rep = f(i-1,j-1,s,t,dp);
	
	return dp[i][j] = 1+min(insert,min(del,rep));
	
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
	
	
	return f(n,m,str1,str2,dp);
// 	return dp[n][m];
}



// tabulation 

int editDistance(string str1, string str2)
{
    int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
	
	for(int j=0;j<=m;j++) dp[0][j] = j;
	
	for(int i=1;i<=n;i++) dp[i][0] = i;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str1[i-1] == str2[j-1])  dp[i][j] = dp[i-1][j-1];
			else{
				int insert = dp[i][j-1];
				int del = dp[i-1][j];
				int rep = dp[i-1][j-1];

				dp[i][j] = 1+min(insert,min(del,rep));
			}
			
		}
	}
	
	return dp[n][m];
}

// space optimization

int editDistance(string str1, string str2)
{
    int n = str1.size();
	int m = str2.size();
// 	vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
	
	vector<int> prev(m+1,0),cur(m+1,0);
	
	for(int j=0;j<=m;j++) prev[j] = j;
	
	
	for(int i=1;i<=n;i++){
		cur[0] = i;
		for(int j=1;j<=m;j++){
			if(str1[i-1] == str2[j-1])  cur[j] = prev[j-1];
			else{
				int insert = cur[j-1];
				int del = prev[j];
				int rep = prev[j-1];

				cur[j] = 1+min(insert,min(del,rep));
			}
			
		}
		prev = cur;
	}
	
	return prev[m];
}

