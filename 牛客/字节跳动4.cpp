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
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T, M, ans = INT_MIN, x, y, len;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		map<P,int> mp;
		cin >> M;
		while(M--){
			vector<P> vs;
			cin >> len;
			map<P,int> temp_mp;
			for(int i = 0; i < len; i++) {
				cin >> x >> y;
				P p = make_pair(x,y);
				vs.push_back(p);
				temp_mp[p] = mp[p] + 1;
				ans = max(ans, temp_mp[p]);
			}
			mp = temp_mp;
		}
		cout << ans;
		/* code */
	}
    return 0;
}