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
int cmp(int a, int b){return a > b;}

class RangeFreqQuery {
public:
	map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
    	for(int i = 0; i < arr.size(); i++)	mp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
    	auto fi = lower_bound( mp[value].begin(), mp[value].end(), left);
    	auto se = lower_bound( mp[value].begin(), mp[value].end(), right, cmp);
    	cout << fi -mp[value].begin();
    	cout << se -mp[value].begin();
    	return (int)distance(fi, se) + 1;

    }
};

int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}