#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int maxn = 1e5+10;
struct node{
	ll x, y, z;
}nodes[1005];
int T,n;
ll h,r;
int father[maxn];
vector<int> down, up;
int getFa(int val){
	if(father[val] != val) father[val] = getFa(father[val]);
	return father[val];
}
void unionSet(int a, int b){
	father[getFa(b)] = getFa(a);
}
ll dis(node n1, node n2){
	return (n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y) + (n1.z - n2.z)*(n1.z - n2.z);
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		bool ok = false;
		down.clear();
		up.clear();
		cin >> n >> h >> r;
		for(int i = 0; i < n; i++) father[i] = i;
		for(int i = 0; i < n; i++) cin >> nodes[i].x >> nodes[i].y >> nodes[i].z;
		for(int i = 0; i < n; i++){
			if(nodes[i].z <= r) down.push_back(i);
			if(h - nodes[i].z <= r) up.push_back(i);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++) if(dis(nodes[i], nodes[j]) <= 4*r*r) unionSet(i, j);
		}
		for(int i = 0; i < n; i++) cout << father[i] << " ";
			cout << endl;

		for(auto d : down){
			for(auto u : up) if(getFa(d) == getFa(u)) ok = true;
			if(ok) break;
		}
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
		/* code */
	}
    return 0;
}