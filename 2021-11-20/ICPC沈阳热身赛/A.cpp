#include <bits/stdc++.h>
using namespace std;
int T, m;

bool slove(int n){
	if((n % 100 == 0 and n % 400 == 0) or (n % 100 != 0 and n % 4 == 0)) return true;
	return false;
}
int main(int argc, char const *argv[]){
	cin >> T;
	while(T--){
		cin >> m;
		cout << "no" << endl;
	}
	return 0;
}