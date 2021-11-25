#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T, m, a, b;
int main(int argc, char * argv[]){
	cin >> m >> a >> b;
	int n = b -a + 1;
	ll ret = 1;
	for(int i = 0; i < m; i++){
		ret *= (i + n);
		ret /= (i + 1);
	}
	cout << ret << endl;
    return 0;
}