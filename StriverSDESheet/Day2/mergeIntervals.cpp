
class Solution {
   
public:
     
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        vector<int> temp = intervals[0];
            
        for(auto e : intervals){
            
            if(temp[1]>=e[0]){
                // merge
                temp[1] = max(e[1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp = e;
            }
            
        }
        ans.push_back(temp);
        return ans;
    }
    
    
};


// tc - O(N*logN)+O(N)
