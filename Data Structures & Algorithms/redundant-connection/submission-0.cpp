class Solution {
class DSU {
private: vector<int>parent, size;
public: DSU(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);
		}
	}
public: int findPar(int node) {
		if (node == parent[node]) {
			return node;
		}
		return parent[node] = findPar(parent[node]);
	}

public: void unionBySize(int u, int v) {
		int pu = findPar(u);
		int pv = findPar(v);
		if (pu == pv) {
			return;
		}
		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pv] += size[pu];
		}
		else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
	}
};
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto it:edges){
            if(dsu.findPar(it[0])!=dsu.findPar(it[1])){
                dsu.unionBySize(it[0],it[1]);
            }
            else{
                return {it[0],it[1]};
            }
        }
        return {-1,-1};
    }
};
