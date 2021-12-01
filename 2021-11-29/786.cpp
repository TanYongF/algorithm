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

bool cmp(pair<int,int> p1, pair<int,int> p2){
	return 1LL * p1.first * p2.second  < 1LL * p2.first * p1.second; 
}
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    	int len = arr.size();
    	vector<pair<int,int>> v;
    	for(int i = 0; i < len; i++){
    		for(int j = i + 1; j < len; j++){
    			v.push_back(make_pair(arr[i], arr[j]));
    		}
    	}
    	sort(v.begin(), v.end(), cmp);
    	return {v[k-1].first, v[k-1].second};


    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}