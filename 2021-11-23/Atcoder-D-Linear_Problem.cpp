#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5 + 10;
const int N = (1 << 2);
int T, t;
ll x;
vector<int> father(N);
vector<ll> val(N, -1);
unordered_map<int,int> mp;
int findSet(int val){
	if(father[val] != val) father[val] = findSet(father[val]);
	return father[val];
}
void unionSet(int a, int b){
	int fatherA = findSet(a);
	int fatherB = findSet(b);
	father[fatherA] = fatherB;
}
int main(int argc, char * argv[]){
	cin >> T;
	for(int i = 0; i < N; i++) father[i] = i;
	while(T--){
		cin >> t >> x;
		int h = x % N;
		if(t == 1){
			if(val[h] != -1) h = (findSet(h) + 1) % N;
			val[h] = x;
			int las = (h + 1) % N;
			int pre = (h - 1) >= 0 ? h-1 : h-1+N;
			if(val[las] != -1) unionSet(h, las);
			if(val[pre] != -1) unionSet(pre, h);
			for(auto it :val) cout << it << " ";
				cout << endl;
		}else{
			cout << val[h] << endl;
		}
	}

    return 0;
}