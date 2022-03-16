#include<iostream>
#include<vector>
using namespace std;

void func(vector<int> nums,int idx, vector<int> &ds,int &ans){
    if(idx == nums.size()){
        
        int sans = ds[0];
        if(ds.size()>1){

            for(int i = 1;i<ds.size();i++){
                sans = (sans^ds[i]);
            }
        }
        if(ds.empty()) ans += 0;
        else ans += sans;
        return;
    }
        ds.push_back(nums[idx]);
        func(nums,idx+1,ds,ans);
        ds.pop_back();
        func(nums,idx+1,ds,ans);
}

int main(){

    vector<int> nums    {5,1,6};
    vector<int> ds;
    int ans = 0;
    func(nums,0,ds,ans);

    return 0;
}