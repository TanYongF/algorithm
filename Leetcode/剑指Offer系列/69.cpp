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
    int peakIndexInMountainArray(vector<int>& arr) {
    	int len = arr.size();
    	if(arr[len-1] > arr[len-2]) return len-1;
    	if(arr[1] < arr[0]) return 0;
    	int L = 1, R = arr.size()-2;
    	while(L <= R){
    		int mid = L + R >> 1;
    		if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid + 1]) return mid;
    		else if(arr[mid] < arr[mid-1]) R = mid - 1;
    		else if(arr[mid+1] > arr[mid]) L = mid + 1;
    	}
    	return 0;

    }

};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}