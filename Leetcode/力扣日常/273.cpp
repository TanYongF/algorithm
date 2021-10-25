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
	string ans;
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        if(num == 0) return "Zero";
    	string str = to_string(num);
    	reverse(str.begin(), str.end());
    	int len = str.length();
    	while(len % 3){
    		str.push_back('0');
    		len = str.length();
    	}
   		int inv = len / 3;
   		for(int i = 0 ; i < inv; i++){
   			string t = get(3 * i, 3 * i + 2 , str);
   			if(t == "") continue;
   			ans = t + " " + thousands[i] + " " + ans;
   		}
   		if(*ans.begin() == ' ') ans.erase(ans.begin());
        while(*ans.rbegin() == ' '){
            ans.pop_back();
        }
   		return ans;
    }
    string get(int start, int end, string& s){
    	string ret;
    	if(s[end] != '0') ret = singles[s[end] - '0'] + " " + "Hundred";
    	int temp = (s[start]-'0' + 10 * (s[start+1] - '0')); 
    	if(temp == 0) return ret;
    	ret +=  " ";
    	if(temp < 10){
    		ret += singles[temp];
    	}else if(temp <= 19 && temp >= 10){
    		ret += teens[temp - 10];
    	}else{
    		ret += tens[(temp / 10)]  + " " + singles[(temp % 10)];
    	}
        if(*ret.begin() == ' ') ret.erase(ret.begin());
        while(*ret.rbegin() == ' '){
            ret.pop_back();
        }
    	return ret;



    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.numberToWords(1000000);
	/* code */


    return 0;
}