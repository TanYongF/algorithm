#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
const int MAXN =1e6+10;
int T;
vector<long long> vs(MAXN);
unordered_set<int> s;
int ask[110];
int hasV = 0;
vector<string> ans(MAXN, "");
int main(int argc, char * argv[]){
	for(int i = 1; i <= MAXN; i++) vs[i] = i*i;
	// cin >> T;
	// for(int i = 1;i <= T; i++) cin >> ask[i];
	s.insert(1);
	ans[1] = "1";
	for(int i = 2; i <= MAXN; i++){
		unordered_set<int> st2;
		for(auto it : s){
			if(it + vs[i] < MAXN) {
				st2.insert(it+vs[i]);

			}
			if(vs[i]-it >= 0) st2.insert(-it+vs[i]);
		}
		for(auto it : s){
			if(it >= 0)cout << it << " ";
		}
		cout << endl;
		cout << "size" << i << " : "<< st2.size() << endl;
		cout << endl;
		s = st2;
	}

	


    return 0;
}