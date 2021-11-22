#include<bits/stdc++.h>
using namespace std;
string s;
bool check(int start){
	if(s[start] == 'e' and s[start+1] == 'd' and s[start+2] == 'g' and s[start+3]== 'n' and s[start+4] == 'b') return true;
	return false;
}
int main(){
	cin >> s;
	int ans = 0;
	if(s.length() <5){
		cout << 0;
		return 0;
	}
	for(int i = 0; i < (int)s.length() - 4; i++){
		if(check(i)) ans++;
	} 
	cout << ans;
}