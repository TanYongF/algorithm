#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(2);
	dp.push_back(3);
	dp.push_back(4);
	dp.push_back(5);
	dp.push_back(6);
	int n = 5;
	int ans[6];
	ms(ans, 0);
	while(next_permutation(dp.begin(),dp.end())){
		int nums = 0;
		for(int i = 1; i < n; i++){
			if(dp[i] > dp[i-1]){
				nums++;
			}
			
		}
		ans[nums]++;
	}
	for(int i = 0; i < n; i++){
		cout << i << " :" << ans[i] <<endl;
	}

	


    return 0;
}