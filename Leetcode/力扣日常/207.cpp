#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <bitset>
#include <list>
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

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	int inDegree[numCourses], hasVisted[numCourses];
    	vector<vector<int>> mp;
    	queue<int> q;
    	memset(inDegree, 0, sizeof(inDegree));
    	memset(hasVisted, false, sizeof(hasVisted));
    	for(auto prerequisity : prerequisites){
    		inDegree[prerequisity[0]]++;
    		mp[prerequisity[1]].push_back(prerequisity[0]);
    	}
    	for(int i = 0; i < numCourses; i++)	if(!inDegree[i]){
    		q.push(i);
    		hasVisted[i] = true;
    	} 
    	while(!q.empty()){
    		int cur = q.front();
    		q.pop();
    		for(auto next : mp[cur]){
    			inDegree[next]--;
    			if(!inDegree[next] and not hasVisted[next]){
    				q.push(next); 
    				hasVisted[next] = true;
    			} 
    		}
    	}
    	for(int i = 0; i < numCourses; i++)	if(!hasVisted[i]) return false;
    	return true;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}