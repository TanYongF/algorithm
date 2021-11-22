#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5 + 10;
int a[MAXN];
int T;
int main(int argc, char * argv[]){
	int N, X;
	cin >> N >> X;
	set<int> st;
	for(int i = 1; i <= N; i++) cin >> a[i]; 
	st.insert(X);
	 int cur = X;
	while(true){
		if(st.find(a[cur]) != st.end()) break;
		st.insert(a[cur]);
		cur = a[cur];
	}
	cout << st.size();
    return 0;
}