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
	bool check(string &s, string &p){
		int len_s = s.length(), len_p = p.length();
		if(len_s < len_p) return false;
		int i = 0, j = 0;
		while(i < len_s && j < len_p){
			if(s[i] == p[j]) j++;
			i++;
		}
		if(j != len_p ) return false;
		return true;
	}
    
    string & min_s(string &s,string &p){
    	if(s.length() > p.length()) return s;
    	else if(s.length() < p.length()) return p;
    	else{
    		for(int i = 0; i < s.length(); i++){
    			if(s[i] == p[i]) continue;
    			return s[i] > p[i] ? p : s;
    		}
    	}
    	return s;

    }
    string findLongestWord(string s, vector<string>& dictionary) {
    	string ans = "";
    	for(auto dic : dictionary){
    		if(check(s,dic)) ans = min_s(ans, dic);
    	}
    	return ans;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	// cout << s.check("1223", "1234");
	/* code */


    return 0;
}