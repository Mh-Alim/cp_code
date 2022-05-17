#include<bits/stdc++.h>

#define ll long long int
using namespace std;

long long int maxAdjSum(vector<ll> &nums){
	ll n = nums.size();
	ll prev = nums[0];
	ll prev2 = 0;
	
	for(ll i=1;i<n;i++){
		ll take = nums[i];
		if(i>1) take+= prev2;
		ll notTake = 0+prev;
		ll curi = max(take,notTake);
		prev2 = prev;
		prev = curi;
		
	}
	
	return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    vector<ll> temp1,temp2;
	ll n = valueInHouse.size();
	if(n == 1) return valueInHouse[0];
	for(ll i=0;i<n;i++){
		if(i!=0){
			temp1.push_back(valueInHouse[i]);
		}
		if(i!=n-1){
			temp2.push_back(valueInHouse[i]);
		}
	}
	
	return max(maxAdjSum(temp1),maxAdjSum(temp2));
}




// question link --> https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1