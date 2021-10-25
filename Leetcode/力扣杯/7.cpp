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
	vector<int> ans;
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
    	const int m = finalCnt.size() + 1;
    	vector<vector<int>> mp(m);
    	for(auto edge : edges){
    		mp[edge[0]].push_back(edge[1]);
    		mp[edge[1]].push_back(edge[0]);
    	}
    	long long  k[m], b[m];
    	memset(k, 0, sizeof(k));
    	memset(b, 0, sizeof(b));
    	for(int i = 1; i < m; i++) b[i] = finalCnt[i-1];
    	k[0] = 1;
    	reverse(plans.begin(), plans.end());
    	for(auto plan : plans){
    		int num = plan[0], idx = plan[1];
    		if(num == 1){
    			k[idx] *= 2;
    			b[idx] *= 2;
    		}else if(num == 2){
    			for(auto neibor : mp[idx]){
    				k[neibor] -= k[idx];
    				b[neibor] -= b[idx];
    			}
    		}else if(num == 3){
    			for(auto neibor : mp[idx]){
    				k[neibor] += k[idx];
    				b[neibor] += b[idx];
    			}
    		}
    	}
    	long long sum_k = 0 , sum_b = 0, x;
    	for(int i = 0; i < m; i++){
    		sum_k += k[i];
    		sum_b += b[i];
    	}
    	cout << sum_k << " " << sum_b << " "  ;
    	x = ((long long)totalNum - sum_b) / sum_k;

    	for(int i = 0; i < m; i++)	ans.push_back((int)k[i] * x + b[i]);
    	return ans;
    }
};

 
int main()
{
	Solution s= Solution();
	vector<int> finalCnt = {1,16};
	vector<vector<int>> edges = {{0,1},{1,2}};
	vector<vector<int>> plans = {{2,1},{1,0},{3,0}};
 	s.volunteerDeployment(finalCnt, 21, edges, plans);
 
	return 0;
}
