#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	unordered_map<int,int> mp;
	string str;
	while(true){
		cin >> str;
		vector<int> nums(100, 0);
		for(int i =0; i < str.size(); i++){
			nums[i] = str[i] == '0' ? -1 : 1;
		}
		for(int i = 1; i < str.size(); i++){
			nums[i] += nums[i-1];
		}
		int ans = 0;
		for(int i = 0; i < str.size(); i++){
			if(not mp.count(nums[i])) mp[nums[i]] = i;
			if(nums[i] == 0) ans = i + 1;
			ans = max(ans, i - mp[nums[i]]); 
		}
		cout << ans << endl;	
	}

    return 0;
}