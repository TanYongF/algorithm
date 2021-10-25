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
const int MAXN = 500010;
int n,ind;
int goods[MAXN];
int main(int argc, char * argv[]){
	cin >> n;
	ms(goods,0);
	for(int i = 1; i <= n; i++) {cin >> goods[i]; goods[i] += goods[i-1];}
	set<int> s;
	map<int,int> mp;
	mp.insert(pair<int,int>(goods[n],1));
	s.insert({0,n+1});
	for(int i = 1; i <= n; i++){
		cin >> ind;
		
		auto lowwer = s.lower_bound(ind);
		int right = *lowwer, left = *(--lowwer);
		int sum = goods[right-1]- goods[left];
		// cout << "left: " << left << " right : " << right << endl;
		// cout << "-----" << sum << " -------------"<<endl;
		if(mp.find(sum) != mp.end()){
			if(mp[sum] == 1) mp.erase(sum);
			else mp[sum]--;
		}
		s.insert(ind);
		mp[goods[ind-1]-goods[left]]++;
		mp[goods[right-1]-goods[ind]]++;
		cout << mp.rbegin()->first;
	}
    return 0;
}