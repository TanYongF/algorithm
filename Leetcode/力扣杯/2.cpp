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

bool cmp(int a, int b){
	return a > b;
}
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
    	vector<int> odd;
    	vector<int> good;
    	for(auto card : cards){
    		if(card % 2 == 0)  good.push_back(card);
    		else odd.push_back(card);
    	}
    	sort(odd.begin(), odd.end(),cmp);
    	sort(good.begin(), good.end(),cmp);
    	for(int i = 1; i < odd.size(); i++) odd[i] += odd[i-1];
    	for(int i = 1; i < good.size(); i++) good[i] += good[i-1]; 

    		for(auto od : odd) cout << od << " ";
    			cout << endl;
    		for(auto go : good) cout << go << " ";
  //   	std::partial_sum(odd.begin(), odd.end();
		// std::partial_sum(good.begin(), good.end();
		odd.insert(odd.begin(),0);
		good.insert(good.begin(),0);
		if((cnt % 2 != 0 && good.size() == 1)) return 0;
		int ans = 0;
		int size = odd.size();
		for(int i = 0; i <= min(size-1, cnt); i+=2){
			if(cnt-i < 0) break;
			if(cnt-i > good.size()-1) continue;
			ans = max(ans, odd[i] + good[cnt-i]);
		}
		return ans;



    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test = {3,3,3,1};
	cout << s.maxmiumScore(test,1);
	/* code */


    return 0;
}