

// rec + memo


bool f(int i,int j,string &pattern,string &text,vector<vector<int>> &dp){
	
	if(i<0 && j<0) return true;
	if(i<0 && j>=0) return false;
	if(j<0 && i>=0){
		for(int k=0;k<=i;k++){
			if(pattern[k] != '*') return false;
		}
		return true;
	}
	if(dp[i][j] != -1) return dp[i][j];
	
	if(pattern[i] == text[j] || pattern[i] == '?')  return dp[i][j] =   f(i-1,j-1,pattern,text,dp);
	if(pattern[i] == '*') return dp[i][j] = f(i,j-1,pattern,text,dp) | f(i-1,j,pattern,text,dp);
	return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
	int m = text.size();
	vector<vector<int>> dp(n,vector<int> (m,-1));
	return f(n-1,m-1,pattern,text,dp);
}

// 1 based indexing code  --> rec+memo


bool f(int i,int j,string &pattern,string &text,vector<vector<int>> &dp){
	
	if(i==0 && j==0) return true;
	if(i==0 && j>=1) return false;
	if(j==0 && i>=1){
		for(int k=1;k<=i;k++){
			if(pattern[k-1] != '*') return false;
		}
		return true;
	}
	if(dp[i][j] != -1) return dp[i][j];
	
	if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')  return dp[i][j] =   f(i-1,j-1,pattern,text,dp);
	if(pattern[i-1] == '*') return dp[i][j] = f(i,j-1,pattern,text,dp) | f(i-1,j,pattern,text,dp);
	return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
	int m = text.size();
	vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
	return f(n,m,pattern,text,dp);
}



// tabulation 


bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
	int m = text.size();
	vector<vector<bool>> dp(n+1,vector<bool> (m+1,0));
	
	dp[0][0] = true;
	for(int j=1;j<=m;j++) dp[0][j] = false;
	
	bool f = true;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=i;k++){
			if(pattern[k-1] != '*'){ 
				dp[i][0] = false;
				f = false;
			}
		}
		if(f == true) dp[i][0] = true;
		f = true;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')  dp[i][j] =   dp[i-1][j-1];
			else if(pattern[i-1] == '*')  dp[i][j] = dp[i][j-1] | dp[i-1][j];
			else  dp[i][j] = false;
		}
	}
	
	return dp[n][m];
}


// space optimized code

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
	int m = text.size();
	
	vector<bool> prev(m+1,false),cur(m+1,false);
	
	prev[0] = true;
	for(int j=1;j<=m;j++) prev[j] = false;
	
	bool f = true;

	
	for(int i=1;i<=n;i++){
		
		for(int k=1;k<=i;k++){
			if(pattern[k-1] != '*'){ 
				cur[0] = false;
				f = false;
			}
		}
		if(f == true) cur[0] = true;
		f = true;
		
		
		for(int j=1;j<=m;j++){
			if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')  cur[j] =   prev[j-1];
			else if(pattern[i-1] == '*')  cur[j] = cur[j-1] | prev[j];
			else  cur[j] = false;
		}
		prev = cur;
	}
	
	return prev[m];
}



