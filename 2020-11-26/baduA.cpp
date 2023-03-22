#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
const int MAXN = 1e5 + 10;

struct cmp1{
	bool operator()(const pair<int, int> &a, const pair<int,int> &b){
		return 1.0 * a.first / a.second < 1.0 * b.first / b.second;
	}
};
int main(int argc, char * argv[]){
	int v[MAXN];
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> mp;
	int n, k;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++){
		if(mp.size() < k){
			mp.insert(make_pair(v[i], 1));
		}else{
			auto front = mp.top();
			mp.pop();
			mp.insert(make_pair(front.first + v[i], front.second + 1));
		}
	}
	double ans = 0;
	
    return 0;
}