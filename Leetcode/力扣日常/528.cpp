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
#include <numeric>
#include <set>
#include <random>
#include <ctime>
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
	Solution(){}
	vector<int> preadd;
	vector<int> w;
	default_random_engine e;
    Solution(vector<int>& w) {
    	this -> w = w;
    	// preadd = vector<int>(w.size());
    	partial_sum(w.begin(), w.end(), back_inserter(preadd));
    	for(auto pre :  preadd) cout << pre << endl;
    }
    
    int pickIndex() {
    	// cout << preadd.size() << " " <<  *(preadd.end()-1;
    	// return 1;
    	return lower_bound(preadd.begin(), preadd.end(),(e() % *(preadd.end()-1) + 1)) - preadd.begin();
    }
};

int main(int argc, char * argv[]){
	vector<int>  t = {1,2,3,4};
	Solution s = Solution(t);
	default_random_engine e;
	// cout << e();
	cout << s.pickIndex();
	/* code */


    return 0;
}