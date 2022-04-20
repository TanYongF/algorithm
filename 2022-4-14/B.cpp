#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string colors;
	cin >> n;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	cin >> colors;
	unordered_map<int, pair<int,int>> mp;
	for(int i = 0; i < n; i++){
		if(colors[i] == 'R') mp[nums[i]].first++;
		else mp[nums[i]].second++;
	}
	long long ans = 0;
	for(auto &it : mp){
		ans += it.second.first * it.second.second;
	}
	cout << ans;
	
	return 0;
}