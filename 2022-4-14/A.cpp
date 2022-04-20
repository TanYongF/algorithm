#include<bits/stdc++.h>
using namespace std;
int main(){
	int n ;
	cin >> n;

	for(int i = 1; i <= 4 * n; i++){
		string row = "";
		if(i <= 3 * n) row = string(n, '*') + string(n, '.');
		else{
			row = string(i-3*n, '.') +string(n, '*') + string(4*n-i, '.');
		}
		string rev = row;
		reverse(rev.begin(), rev.end());
		cout << row << rev << endl;
	}
	return 0;
}