#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e6+10;
int a[MAXN];
int T, m;
ll sum;
multiset<int> st;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> m;
		st.clear();
		sum = 0;
		int ans = 0;
		ll cur = 0;
		for(int i = 0; i < m; i++){
			cin >> a[i];
			sum += a[i];
		} 
		if(sum < 0){
			cout << -1 << endl;
			continue;
		}

		for(int i = 0; i < m; i++){
			st.insert(a[i]);
			cur += a[i];
			if(cur < 0){
				auto minit = st.begin();
				int minx = *minit;
				st.erase(minit);
				cur -= minx;
				ans++;
			}
		}
		cout << ans << endl;
	}

	


    return 0;
}