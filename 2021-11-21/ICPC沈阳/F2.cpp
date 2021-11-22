#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int sa[MAXN];
string str;
int n;
vector<pair<int,int>> vp;   
vector<int> vs;  
char ch;
unordered_set<int> st;
unordered_map<char,int> mp;
int maxInv = 0;
int maxLen = 0;


void get(int len){
	int tem = 0;
	mp = unordered_map<char, int>();
	for(int i = len - 1; i >= 0; i--){
		if(mp.find(str[i]) == mp.end()){
			mp[str[i]] = tem;
			tem++;
		}
		if(mp.find(ch) != mp.end()){
			if(mp[ch] <= maxInv){
				return;
			}else{
				maxInv = mp[ch];
				maxLen = len;
			}
		}
	}
}

int main(){
	memset(sa, 0, sizeof(sa));
	cin >> n >> str;
	int len = str.length();
	maxLen = len;
	ch = str[0];
	for(int i = 0; i < len; i++) if(str[i] == ch) vs.push_back(i); 
	get(len);
	for(int i = vs.size() -1; i >= 0; i--){
		get(vs[i]);
	}
	mp = unordered_map<char,int>();
	char ch = 'a';
	for(int i = maxLen - 1; i >= 0; i--){
		if(mp.find(str[i]) == mp.end()){
			mp[str[i]] = ch;
			ch++;
		}
	}
	for(int i = 0; i < maxLen; i++){
		str[i] = mp[str[i]];
	}
	cout << str.substr(0, maxLen) << endl;
	return 0;
}