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

class DetectSquares {
public:
    map<pair<int,int>,int> mp; 
    set<pair<int,int>> st; 
    DetectSquares() {


    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
        st.insert({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int ans= 0 ;
        int x = point[0], y = point[1];
        for(auto &it : st){
            if(it.first == x && it.second == y) continue;
            ans += mp[{it.first, y}] * mp[{it.first, it.second}] * mp[{x, it.second}]; 
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}