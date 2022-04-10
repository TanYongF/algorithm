#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 1e18;
int main(){
	long long N, ans;
	cin >> N;
	for(int i = 1; i <= N; i++){
		ans = max( 1LL * (1* i-1)*2, 1LL *(N-i) * 2);
		printf("%lld\n", ans);
	}
	return 0;
}