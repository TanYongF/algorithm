#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int S, T, X;
	cin >> S >> T >> X;
	if(S < T and X >= S and X < T) cout << "Yes" ;
	else if(S > T and (X >= S or X < T)) cout << "Yes";
	else cout << "No";


    return 0;
}