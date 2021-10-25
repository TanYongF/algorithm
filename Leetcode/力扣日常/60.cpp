//https://leetcode-cn.com/problems/permutation-sequence/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <deque>
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
	deque<int> dq;
	void eraseNum(deque<int> &q, int numToErase){
    	for(deque<int>::iterator it = dq.begin(); it != dq.end(); ++it){
    		if(*it == numToErase){
    			dq.erase(it);
    			return;
    		} 
    	}
	}
    string getPermutation(int n, int k) {
    	string ans = "";
    	int curBit = 1,	cur ;
    	for(int i = 1; i <= n; i++)	curBit *= i;
    	for(int i = 1; i <= n; i++) dq.push_back(i);
    	for(int i = n; i >= 2; i--){
    		curBit /= i;
    		cur = (k-1)/curBit + 1;
    		ans += to_string(dq[cur-1]);
    		eraseNum(dq, dq[cur-1]);
    		k = (k-1)%curBit + 1;
    	}
    	return (ans += to_string(dq[0]));
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	// for(int i = 1; i <= 3; i++){
	// 	cout << s.getPermutation(3,1) << endl;
	// }
	// for(int i = 1; i <= 6; i++) cout << s.getPermutation(3,i) << endl;
	cout << s.getPermutation(3, 6);
	/* code */


    return 0;
}