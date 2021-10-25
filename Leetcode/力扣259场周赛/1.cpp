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
    int finalValueAfterOperations(vector<string>& operations) {
    	int ans =0;
    	for(auto o : operations){
    		for(auto ch : o) {
    			if(ch == '+'){
    				ans++;
    				break;
    			} 
    			else if(ch == '-') {
    				ans--;
    				break;
    			}
    			
    		}
    	}
    	return ans;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}