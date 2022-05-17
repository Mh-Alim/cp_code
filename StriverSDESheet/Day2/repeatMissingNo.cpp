#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int> ans;
	
	unordered_map<int,int> mp;
	
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	
	for(int i=1;i<=n;i++){
		if(mp[i] == 0) ans.first = i;
		if(mp[i] > 1) ans.second = i;
	}
	return ans;
	
}


// i have to others three method to to understand the question properly
