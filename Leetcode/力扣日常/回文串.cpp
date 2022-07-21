#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
string s;
int count(string &s){
	int len = 0;
	int ans=  0;
	int res = 0, im, rm;
	string t = "$#";
	for(auto &ch : s){
		t.push_back(ch);
		t.push_back('#');
	}
	t += "!";
	len = t.size();
	vector<int> f(len);
	im = rm  = 0;
	for(int i = 1; i < t.size(); i++){
		f[i] = (i <= rm) ? min(rm - i + 1, f[2 * im - i]) : 1;
		while(t[i+f[i]] == t[i-f[i]]) ++f[i];
		if(i + f[i] - 1 > rm){
			im = i;
			rm = i + f[i] - 1;
		}
		ans += (f[i] / 2);
	}
	return ans;
}
int main(int argc, char * argv[]){
	cin >> s;
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0 ;i < s.size(); i++){
		cnt[s[i] - 'a']++;
	}
	string ans;
	for(int i = 0 ;i  < 26; i++){
		for(int j = 0; j < cnt[i]; j++){
			ans.push_back(i + 'a');
		}
	}
	cout << count(ans);

    return 0;
}