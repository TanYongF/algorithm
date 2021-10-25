//https://leetcode-cn.com/problems/gcd-sort-of-an-array/
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

const int MAXN = 100010;
class Solution {
public:
	int father[MAXN];
	unordered_map<int ,vector<int>> st;

	int gcd(int a, int b){
		if(b == 0) return a;
		else return gcd(b, a % b);
	}
	int getf(int x){
		if(father[x] != x) father[x] = getf(father[x]);
		return father[x];
	}
	void unionset(int x, int y){
		int a = getf(x);
		int b = getf(y);
		if(a != b) father[b] =a;
		return;
	}

    bool gcdSort(vector<int>& nums) {
    	int len = nums.size();
    	vector<int> res = vector<int>(nums);
    	for(int i = 0; i < MAXN; i++) father[i] = i;

    	for(auto num : nums){
    		// cout << num << endl;
    		int k = num;
    		for(int i = 2; i <= num / i ;i++){
    			if(num % i == 0){
    				// cout << i << " " ;
    				while(num % i == 0) num /= i;
    				unionset(i, k);
    			}
    			if(num > 1)  unionset(num, k);
    		}
    		// cout << endl;
    	}
    	// for(auto num : nums) cout << getf(num) << endl;
    	sort(res.begin(), res.end());
    	for(int i = 0 ; i < len; i++){
    		if(res[i] == nums[i]) continue;
    		if(getf(res[i]) != getf(nums[i])) return false;
    	}
    	return true;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> nums ={5,2,6,2};
	 cout << s.gcdSort(nums);
	/* code */


    return 0;
}