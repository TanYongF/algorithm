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
	int bag[100];
	bool flag = false;
	bool check(int curId, int size, vector<int>& tasks, int sessionTime){
		if(curId >= tasks.size()) {flag = true; return true;}
		for(int i = 1; i <= size; i++){
			if(flag) return true;
			if(bag[i] >= tasks[curId] && !flag){
				bag[i] -= tasks[curId];
				check(curId+1, size, tasks, sessionTime);
				bag[i] += tasks[curId];
			}
		}

		return flag;

	}
    int minSessions(vector<int>& tasks, int sessionTime) {
    	int sum = 0, ans = 0;
    	if(sessionTime == 1) return tasks.size();
    	sort(tasks.begin(), tasks.end());
    	for(auto task : tasks) sum += task;
    	int L = max(1, sum/sessionTime ), R = tasks.size();
    	while(L <= R){
    		int mid =(L+R)>>1;
    		// cout<< L<< " "<<R;
    		for(int i = 1;i <= mid; i++) bag[i] = sessionTime;
    		flag = false;
    		if(check(0, mid, tasks, sessionTime)){
    			R = mid-1;
    			ans = mid;
    		}else{
    			L = mid + 1;
    		}
    	}
    	return ans;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> t = {10,10,10,10,10,10,10,10,10,10,10,10};
	cout << s.minSessions(t, 10);
	/* code */


    return 0;
}