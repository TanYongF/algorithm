#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int len = s.size(), a = 0, b = 0;
	long long ans = 0;
	vector<int> zeros, ones;
	for(int i = 0; i < len; i++){
		if(s[i] == '0') zeros.push_back(i);
		else ones.push_back(i);
	}
	a = zeros.size(), b = ones.size();
	if(len % 2){
		if(b > a) for(int i = 0, j = 0; i < len and j < b; i+=2, j++) ans += abs(i - ones[j]);
		if(a > b) for(int i = 0, j = 0; i < len and j < a; i+=2, j++) ans += abs(i - zeros[j]);
	}else{
		int n1 = 0, n2 = 0;
		for(int i = 0, j = 0; i < len and j < a; i+=2, j++) n1 += abs(i - zeros[j]);
		for(int i = 0, j = 0; i < len and j < b; i+=2, j++) n2 += abs(i - ones[j]);
		ans = min(n1, n2);
	}
	cout << ans;	
	return 0;
}