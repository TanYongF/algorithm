#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T, n, x, score;
int main(int argc, char * argv[]){
	cin >> n >> x;
	vector<int> scores;
	for(int i = 0; i < n; i++){
		cin >> score;
		if(score != 0) scores.push_back(score);
	}
	sort(scores.begin(), scores.end(),less<int>());
	if(x > scores.size()) cout << scores.size();
	else{
		int need = scores[x-1], l = 0, r = scores.size()-1, ans;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(scores[mid] >= need) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans + 1;
	}


    return 0;
}