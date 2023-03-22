#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main(int argc, char * argv[]){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);
	map<int, int> mp;
	for(int i = 0; i <n; i++) mp[nums[i]]++;
	int ans = 0;
	for(auto it : mp){
		if(it.second > 1) ans += (it.second - 1);
	}
	cout << ans;
    return 0;
}