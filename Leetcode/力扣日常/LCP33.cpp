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
    int storeWater(vector<int>& bucket, vector<int>& vat) {
    	int minop = INT_MAX;
    	int n = bucket.size();
    	int ans = INT_MAX;
    	int maxn = *max_element(vat.begin(),vat.end());
    	if(maxn == 0) return 0;
    	for(int i = 1; i <= maxn; i++){
    		int cur = i;
    		for(int  j = 0; j < n; j++){
    			int requeir = vat[j]/i +(vat[j]%i?1:0);
    			cur += (requeir<=bucket[j])?0:(requeir-bucket[j]);
    		}
    		ans = min(ans, cur);
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> bucket = {1,3};
	vector<int> vat = {6,18};
	cout << s.storeWater(bucket, vat);
	/* code */


    return 0;
}