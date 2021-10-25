//https://leetcode-cn.com/problems/restore-ip-addresses/
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
    int len;
    vector<string> ans;
    vector<int> item;
    void backtracing(int startIndex, string &s){
        if(startIndex == len && item.size() == 4){
        	string retstr = to_string(item[0]);
        	for(int i = 1; i < 4; i++) retstr = retstr + '.' + to_string(item[i]);
            ans.push_back(retstr);
        	return;
        }else if(startIndex == len || item.size() > 4) return;
        if(3 * (4 - item.size()) < (len - startIndex + 1)) return; 
        if(s[startIndex] == '0'){
        	item.push_back(0);
        	// cout << startIndex << endl;
        	backtracing(startIndex + 1, s);
        	item.pop_back();
        	return;
        }
        for(int i = 1; i <= 3 && startIndex + i - 1 < len; i++){
            int num = 0;
            for(int j = 0; j < i; j++) num = num * 10 +(s[startIndex+j]-'0');
            	// cout << num << endl;
            if(num > 255) break;
        	item.push_back(num);
        	// cout << num << endl;
        	backtracing(startIndex + i, s);
        	item.pop_back();
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        len = s.length();
        if(len > 12 || len < 4) return ans;
        backtracing(0, s);
        for(auto an : ans) cout << an << endl;
        return ans;
           
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	s.restoreIpAddresses("010010");
	


    return 0;
}