#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <bitset>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
	const int N  = 1e6;
	string ret(int num, int n){
		string ans;
		while(n--){
            // cout << (num&1);
			ans.insert(ans.begin(),(num&1)+'0');
            // cout << ans << endl;
			num >>= 1;
		}
        
        return ans;
	}
    string findDifferentBinaryString(vector<string>& nums) {
    	bool num[N];
        memset(num, false, sizeof(num));
    	int len = nums[0].length();
    	for(auto str : nums){
    		bitset<17> bit(str);
            // cout << bit.to_ulong()<<endl;
    		num[(int)bit.to_ulong()] = true;
    	}
    	for(int i = 0; i < 1e6; i++){
    		if(!num[i]) return ret(i, len);
    	}
    	return "";
    }
};

int main(int argc, char * argv[]){
vector<string> nums ={"01","10"}; 
	Solution s = Solution();
	cout << s.findDifferentBinaryString(nums);
	/* code */


    return 0;
}