//https://leetcode-cn.com/problems/validate-stack-sequences/
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
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    	stack<int> st;
    	int len = pushed.size();
    	
    	int j = 0;
    	for(int i = 0; i < len; i++){
    		st.push(pushed[i]);
    		while(st.top() == popped[j]){
    			st.pop();
    			j++;
    		}
    	}
    	return st.empty(); 

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}