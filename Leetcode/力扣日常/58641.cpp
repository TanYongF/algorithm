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

bool cmp(vector<int> p1, vector<int> p2){
	if(p1[0] == p2[0]) return p1[1] < p2[1];
	else return p1[0] > p2[0];

}
class Solution {
public:

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
    	int ans = 0;
    	int len = properties.size();
    	sort(properties.begin(), properties.end(), cmp);
    	int maxded = properties[0][1];
    	for(int i = 1; i < len; i++){
    		if(properties[i][1] < maxded) ans++;
    		else maxded = max(maxded, properties[i][1]);
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}