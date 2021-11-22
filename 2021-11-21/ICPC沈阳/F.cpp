#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int sa[MAXN];
string str;
int n;
vector<pair<int,int>> vp;   
vector<int> vs;  
unordered_set<int> st;
bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p1.first == p2.first)
		return p1.second > p2.second;
	return p1.first>p2.first;
}
int main(){
	unordered_map<char,int> mp;
	unordered_map<char,int> mm;
	memset(sa, 0, sizeof(sa));
	cin >> n;
	cin >> str;
	int len = str.length();
	char ch = str[0];
	for(int i = 0; i < len; i++){
		if(str[i] == ch) vs.push_back(i);
	}
	vs.push_back(len);

	for(int i = 0; i < vs.size() - 1; i++){
		st = unordered_set<int>();
		for(int j = vs[i] + 1; j < vs[i+1]; j++){
			st.insert(str[j]);
		}
		vp.push_back({(int)st.size(), vs[i + 1] - 1});
	}

	sort(vp.begin(), vp.end(), cmp);
	auto last= vp[0];
	len = last.second + 1;
	str = str.substr(0, len);
	char tem = 'a';
	for(int i = len - 1; i >= 0; i--){
		if(mp.find(str[i]) == mp.end()){
			mp[str[i]] = tem;
			tem++;
		} 
	}
	for(auto &it : str){
		char cur = it;
		it = mp[cur];
	}
	cout << str;
	return 0;
}