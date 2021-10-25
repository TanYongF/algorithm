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
#include <bitset>
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
	unordered_set<bitset<12>> vs;
	int len;
	string str;
	bool judge(string s){
		// cout << s << endl;
		if(s.length() == 0) return false;
		int i = 0,  j = s.length()-1;
		while(i < j) {
			if(s[i] != s[j]) return false;
			i++;j--;
		}
		return true;
	}
	int cal( const bitset<12>& bt){
		int ans =0 ;
		for(int i = 0; i < 12; i++){
			ans += (bt[i] == 1);
		} 
		return ans;
	}
	void dfs(string cur, int idx, bitset<12> st){
		if(judge(cur)){ vs.insert(st); }
		if(idx == len) return;
		dfs(cur, idx+1, st);

		st[idx] = 1;
		cur = cur + str[idx];
		dfs(cur, idx+1, st);
	}
    int maxProduct(string s) {
    	int ans = 0;
    	this->len = s.length();
    	this->str = s;
    	bitset<12> st;
    	dfs("", 0, st);
    	cout << vs.size();
    	for(auto &one : vs){
    		for(auto &two : vs){
				if((one&two)==0) ans = max(ans, cal(two)*cal(one));
    		}
    	}
    	return ans;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.maxProduct("aaaaaaaaaaaa");
	/* code */


    return 0;
}