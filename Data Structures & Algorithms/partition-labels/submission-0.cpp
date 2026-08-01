class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>lastIndex;
        for(int i=0;i<s.length();i++){
            lastIndex[s[i]]=i;
        }
        vector<int>ans;
        int end = 0 ,size = 0;
        for(int i=0;i<s.length();i++){
            end = max(end, lastIndex[s[i]]);
            size++;
            if(i==end){
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};
