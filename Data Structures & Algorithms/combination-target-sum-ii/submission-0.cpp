class Solution {
public:
    void solve(int i,int sum,vector<int>candidates,int target,vector<vector<int>>&ans,vector<int>&temp){
        if(sum > target)return;
        if(sum == target)return ans.push_back(temp);
        for(int j = i ; j < candidates.size();j++){
            if(j-1>=i && candidates[j]==candidates[j-1])continue;
            temp.push_back(candidates[j]);
            solve(j+1,sum+candidates[j],candidates,target,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        solve(0,0,candidates,target,ans,temp);
        return ans;
    }
};
