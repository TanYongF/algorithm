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
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
int N;
int a[2005], b[2005];

//存储所有可能的值
std::set<int> st;
map<int,int> mp;
std::vector<int> res;
int main(int argc, char * argv[]){
	cin >> N;
	/* code */
	int ans = 0;
	for(unsigned i = 1; i <= N; ++i) {
		scanf("%d", &a[i]);
		ans ^= a[i];
	}
	for(unsigned i = 1; i <= N; ++i) {
		scanf("%d", &b[i]);
		ans ^= b[i];
	}
	// // cout << ans;
	if(N % 2 == 0 && ans != 0){
		cout << 0;
		return 0;
	}
	// if(N % 2 != 0){
	// 	cout << 1 << endl;
	// 	cout << ans;
	// 	return 0; 
	// }
	for(unsigned j = 1; j <= N; ++j) {
		st.insert(a[1]^b[j]);
	}
	for(auto it : st){
		for(unsigned i = 1; i <= N; ++i) {
			mp[a[i]^it]++;
		}
		bool flag = true;
		for(unsigned i = 1; i <= N; ++i) {
			if(mp[b[i]] == 0) flag = false;
			else mp[b[i]]--;
		}
		if(flag) res.push_back(it);
		mp.clear();
	}
	sort(res.begin(),res.end());
	cout << res.size() << endl;
	for(auto it : res) {
		cout << it << endl;
	}

    return 0;
}