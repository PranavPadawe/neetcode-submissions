class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int n = nums.size();
        vector<pair<int,int>>arr;
        for(int i = 0 ;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        while(l < r){
            if(arr[l].first + arr[r].first < target){
                l++;
            }
            else if(arr[l].first + arr[r].first > target){
                r--;
            }
            else return {min(arr[l].second,arr[r].second),max(arr[l].second,arr[r].second)};
           
        }
        return {-1,-1};
    }
};
