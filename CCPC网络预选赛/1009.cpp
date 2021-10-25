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
typedef pair<int,int> P;
int T,n;
string s;
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
int main(){
	cin >> T;
	while(T--){
		P pre(0,0);
		unordered_map<pair<int,int>,int, hash_pair> mp;
		mp[P(0,0)]++;
		cin >>n;
		cin >> s;
		for(int i = 0; i < n; i++){
			if(s[i] == 'U'){
				pre.second++;
			}else if(s[i] == 'D'){
				pre.second--;
			}else if(s[i] == 'R'){
				pre.first++;
			}else{
				pre.first--;
			}
			mp[P(pre.first, pre.second)]++;
		}
		ll ans = 0;
		for(auto it : mp){

			ans += ((ll)(it.second)*(it.second-1)/2);
		}
		cout << ans << endl;
	}


    return 0;
}