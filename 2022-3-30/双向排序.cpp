#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int m, n, p, q;
int main(int argc, char * argv[]){
	cin >> n >> m;
	vector<int> status(n+1, 0);
	for(int i = 1; i <= n; i++) status[i] = i;
	int mid = 1, i, j;
	while(m--){
		cin >> p >> q;
		if(p == 1){
			 if(q >= mid) continue;
			 else{
			 	i = q, j = mid;
			 	while(i < j) swap(status[i++], status[j--]);
			 }
		}else{
			if(q <= st1.size()) continue;
			else{
				
			}
		}
	}
	for(auto num : st1) cout << num << " ";
	for(auto num : st2) cout << num << " ";


    return 0;
}