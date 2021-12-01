#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 5000;
int T;
vector<int> a;
int n, p, curCandy, use, minx = INT_MAX, maxx = INT_MIN, num;
int pre[MAXN];
int main(int argc, char * argv[]){
	cin >> n >> p;
	ms(pre, 0);
	for(unsigned i = 0; i < n; ++i){
		cin >> num;
		a.push_back(num);
		minx = min(minx, num);
		maxx = max(maxx, num);
	} 
	vector<int> ra;
	// sort(a.begin(), a.end());
	for(auto it : a) pre[it]++;
	for(int i = minx+1; i <= MAXN; i++) pre[i] = pre[i] + pre[i-1];
	// for(int i = minx+1; i <= maxx; i++) cout << pre[i] << " ";
		// cout << endl;
	for(int k = minx; k <= maxx; k++){
		ll curnum = 1;
		curCandy = k, use = 0; 
		for(auto it : a){
			// curnum *= (pre[curCandy] - use);
			curnum = (curnum * (pre[curCandy] - use)) % p;
			if(not curnum) break;
			// if(k == 4) cout << curnum << " ";
			// if(curnum % p == 0) break;
			curCandy++;
			use++;
		}
		// cout << k  <<  " : " << curnum << endl;
		if(curnum % p != 0) ra.push_back(k);
	}
	cout << ra.size() << endl;
	for(auto it : ra) cout << it << " ";
    return 0;
}