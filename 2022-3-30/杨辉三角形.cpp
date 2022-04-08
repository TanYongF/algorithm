#include<bits/stdc++.h>
using namespace std;
int main(){
	long long N;
	cin >> N;
	if(N == 1) cout << 1 << endl;
	else if(N == 2) cout << 5 << endl;
	else cout << 5 + (N - 2) * (N + 3) / 2 << endl;
	return 0;
}