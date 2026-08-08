class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<char,int>indegree;
        map<char,set<char>>adj;
        for(auto it: words){
            for(auto c:it){
                indegree[c]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            if(s1.length()>s2.length() &&                       
                s1.substr(0,s2.length())==s2){
                return "";
            }
            for(int j=0;j<min(s1.length(),s2.length());j++){
                if(s1[j]!=s2[j]){
                    if(!adj[s1[j]].count(s2[j])){
                        adj[s1[j]].insert(s2[j]);
                        indegree[s2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char>q;
        for(auto it:indegree){
            if(it.second==0){
                q.push(it.first);
            }
        }
        string ans = "";
        while(q.size()){
            char cur = q.front();
            ans += cur;
            q.pop();
            for(auto it:adj[cur]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.length()!=indegree.size())return "";
        return ans;
    }
};
