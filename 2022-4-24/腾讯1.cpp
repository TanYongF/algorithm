#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5 + 10;
int T;
int main(int argc, char * argv[]){
	int n, len;
	cin >> n;

	vector<string> g(MAXN);
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		len = str.size();
		for(int j = 0; j < len; j++){
			g[j].push_back(str[j]);
		}
	}
	vector<ll> nums;
	for(int i = 0; i < len; i++){
		nums.push_back(stoll(g[i]));
	}
	sort(nums.begin(),nums.end());
	for(int i = 0; i < len; i++){
		cout << nums[i];
		if(i != len-1) cout << " ";
	}

    return 0;
}