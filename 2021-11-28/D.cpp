#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


const int MAXN = 1e5 + 10;
int fa[MAXN];
bool cmp(vector<int> x, vector<int> y){
	return x[2] < y[2];
}
class Solution {
public:
	int find(int x){
		if(fa[x] != x) fa[x] = find(fa[x]);
		return fa[x];
	}
	void merge(int x, int y){
        int fax =find(x), fay = find(y);
		if(fax > fay) swap(fax,fay);
		fa[fay] = find(fax);
	}
	int findd(int x, vector<int>& v){
		if(v[x] != x) v[x] = find(v[x]);
		return v[x];
	}
	void mergee(int x, int y,vector<int>& v){
        int fax = findd(x,v), fay = findd(y,v);
		if(fax > fay) swap(fax,fay);
		v[fay] = fax;
	}
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(int i = 0; i < n; i++)fa[i] = i;
        fa[firstPerson] = 0;
    	map<int,vector< pair<int,int>>> mp;
    	for(auto meeting : meetings) mp[meeting[2]].push_back({meeting[0],meeting[1]});
    	for(auto & mt : mp){
    		unordered_set<int> st;
    		for(auto &met : mt.second){
    			st.insert(met.first);
    			st.insert(met.second);
    		}
    		vector<int> temp(n);
    		unordered_map<int, unordered_set<int>> mpp;
    		for(auto it : st) temp[it] = it;
    		for(auto &met : mt.second){
    			mergee(met.first, met.second, temp);
    		}
    		for(auto it : st){
    			int fait = findd(it, temp);
    			mpp[fait].insert(it);
    		}
    		for(auto it : st){
    			if(find(it) == 0){
    				int fait = findd(it, temp);
    				for(auto itt : mpp[fait]) fa[itt] = 0;
    			}
    		}

    	}
    	vector<int> vs;
    	for(int i = 0; i < n; i++){
    		if(find(i) == 0) vs.push_back(i);
    	}
    	return vs;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}