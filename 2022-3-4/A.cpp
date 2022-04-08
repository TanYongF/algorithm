#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int n,m,a,b;
int main(int argc, char * argv[]){
	// cin >> T;
	while(cin >> n >> m >> a >> b){
		int minn = INT_MAX, maxx = INT_MIN, last = n - m, need = 0,cur;
		if(a < b) swap(a,b);
		for(int i = 0; i < m; i++){
			cin >> cur;
			minn = min(minn, cur);
			maxx = max(maxx, cur);
		}
		if(minn < b or maxx > a){
			cout << "NO" << endl;
			continue;
		}
		if(a != maxx) need++;
		if(b != minn) need++;
		if(need > last) cout << "NO" << endl;
		else cout << "YES" << endl; 
	}
    return 0;
}