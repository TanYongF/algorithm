#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int n;
	cin >> n;
	long long ans = 1;
	for(int i = 1; i <= n; i++){
		ans *= i;
	}
	cout << ans;
	// 1 2 3 4 5 6 7 8 9 10 3628800
	// 


    return 0;
}