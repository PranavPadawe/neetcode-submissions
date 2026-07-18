class CountSquares {
    map<int,map<int,int>>mp;
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;
        for(auto [ny,cnt]: mp[x]){
            if(ny==y)continue;
            int dis = ny-y;
            ans+=cnt*mp[x+dis][y]*mp[x+dis][ny];
            ans+=cnt*mp[x-dis][y]*mp[x-dis][ny];
        }
        return ans;
    }
};
