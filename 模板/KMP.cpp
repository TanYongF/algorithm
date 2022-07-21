#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
//pattern: a  b  a  b  a  b
//next:   -1  0  0  1  2  3
//next[i]代表前i个字符的组成的后缀子串与前缀子串的公共最大长度。
vector<int> getNext(string& pattern){
	auto next = vector<int>(pattern.size());
	next[0] = -1; // 第一个字符失配那么就是让匹配串往右移动
	int i = 0, j = -1; // i指向待求next值的字符，j指向最长相同前缀末尾
	while(i < pattern.size()-1){
		if(j == -1 or pattern[i] == pattern[j]){
			++i;
			++j;
			next[i] = j; 
		}else j = next[j]; //这里全
	}
	return next;
}

int kmp(string &t, string &p){
	auto next = getNext(p);
	
	cout << "Next: ";
	for(auto num : next) cout << num << " ";
	cout << endl;
	
	int i = 0, j = 0;
	while(i < t.size() and j < p.size()){
		if(j == -1 or t[i] == p[j]) i++, j++;
		else j = next[j];
	}	
	if(j == (int)p.size()) return i - j;
	else return -1;
}


int main(int argc, char * argv[]){
	string s1;
	string s2;
	cin >> s1 >> s2 ;

	cout << kmp(s1, s2);

    return 0;
}