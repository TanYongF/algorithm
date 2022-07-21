#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

//http://acm.hdu.edu.cn/showproblem.php?pid=1711
int T;
vector<int> getNext(string &p){
	auto next = vector<int>(p.size());
	next[0] = -1;
	int i = 0, j = -1;
	while(i < p.size()){
		if(j == -1 or p[i] == p[j]){
			next[++i] = ++j;
		}else{
			j = next[j];
		}	
	}
	return next;
}

int kmp(string &s, string &p){
	auto next = getNext(p);
	int i = 0, j = 0;
	while(i < (int)s.size() and j < (int)p.size()){
		if(j == -1 or s[i] == p[j]) i++, j++;
		else j = next[j];
	}
	if(j == p.size()) return i - j + 1;
	else return -1;
}


int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		int m, n;
		cin >> m >> n;
		string s, p;
		char ch;
		for(int i = 0;i < m; i++){
			cin >> ch;
			s.push_back(ch);
		}
		for(int i = 0; i < n; i++){
			cin >> ch;
			p.push_back(ch);
		}
		cout << kmp(s, p) << endl;
	}
    return 0;
}