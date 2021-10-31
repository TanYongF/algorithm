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
  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    	vector<int> nodes;
    	int maxRet = INT_MIN, minRet= INT_MAX;
    	while(head) {nodes.push_back(head->val); head = head->next;}
    	vector<int> dis;
    	for(int i =1 ; i<(int)nodes.size()-1; i++){
    		if(nodes[i] > nodes[i-1] and nodes[i] > nodes[i+1]) dis.push_back(i);
    		else if(nodes[i] < nodes[i-1] and nodes[i] < nodes[i+1]) dis.push_back(i);
    	}
    	if(dis.size() < 2) return {-1,-1};
    	maxRet = dis.back() - dis[0];
    	for(int i = 1; i < (int)dis.size(); i++){
    		minRet = min(minRet, (dis[i] - dis[i-1]));
    	}
    	return {minRet, maxRet};
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}