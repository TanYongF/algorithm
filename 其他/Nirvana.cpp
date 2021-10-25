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
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

int n;
int main(int argc, char * argv[]){
	cin >> n;
	int nums[11];
	ms(nums);
	int dp[11];
	int index = 1; 
	while(n != 0){
		nums[index++] = n % 10;
		n /= 10;
	}
	dp[1] = nums[1];
	for(unsigned i = 2; i < 11; ++i) {
		int premax = 1;
		for(unsigned j = 1; j < i; ++j) {
			premax *= 9;
		}
		if(nums[i] == 0) {
			dp[i] = dp[i-1];
		}
		else {
			dp[i] = max(dp[i-1]*nums[i], ( (nums[i] == 1) ? 1 : (nums[i] - 1)) * premax);
		}
	}
	cout << dp[10];

    return 0;
}