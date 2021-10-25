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
#include <unordered_map>
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
int MAXN = 1e6+10;
int n;
int maxNum = INT_MIN;
ll ans = 0;
unordered_map<int,int> mp;
std::vector<int> v;
int main(int argc, char * argv[]){
	cin >> n;
	mp.clear();
	int num;
	for(unsigned i = 0; i < n; ++i) {
		scanf("%d", &num);
		maxNum = max(maxNum, num);
		mp[num]++;
	}
	for(auto iter1 = mp.begin(); iter1 != mp.end(); iter1++){
		v.push_back(iter1->first);
	}
	sort(v.begin(),v.end());
	for(unsigned i = 0; i < v.size(); ++i) {
		if(v[i] > (int)sqrt(maxNum) + 1) break;
		for(unsigned j = i; j < v.size(); ++j) {
			ll numToFind = v[i] * v[j];
			if(numToFind > maxNum) break;
			if(v[i] != v[j]) ans += mp[v[i]] * mp[v[j]] * mp[numToFind] * 2;
			else ans += mp[v[i]] * mp[v[j]] * mp[numToFind];
		}
	}
	cout << ans;
    return 0;
}