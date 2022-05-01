#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(s, val) memset(a, val, sizeof(a))


int main(){
	string a, b;
	cin >> a >> b;
	string aa, bb;
	for (int i = 1; i < a.size(); i++) {
	  if (a[i] % 2 == a[i-1] % 2) {
	    aa += max(a[i], a[i-1]);
	  }
	}
	for (int i = 1; i < b.size(); i++) {
	  if (b[i] % 2 == b[i-1] % 2) {
	    bb += max(b[i], b[i-1]);
	  }
	}
	if(aa==bb) cout << aa << endl;
	else{
		cout << aa << endl;
		cout << bb << endl;
	}
	return 0;
}