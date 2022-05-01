#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
	int a, b;
	ull ans = 1;
	cin >> a >> b;
	for(int i = 1; i <= (a + b); i++){
		ans = ans * i;
	}
	cout << ans;
	return ans;
}