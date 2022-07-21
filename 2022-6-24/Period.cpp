#include<iostream>
#include<vector>
#include<string>
#include <cstring>
#include<climits>
// #include
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

const int MAXN = 1e6+10;
int Next[MAXN]; 
int T;
void getNext(string &p){
	int len = p.size();
	memset(Next, 0, sizeof(Next));
	Next[0] = -1;
	int i = 0, j = -1;
	while(i < len){
		if(j == -1 or p[i] == p[j]){
			Next[++i] = ++j;
		}else j = Next[j];
	}
}
int main(int argc, char * argv[]){
	int len, idx = 1;
	while(cin >> len){
		if(len == 0) break;
		string str;
		cin >> str;
		getNext(str);
		cout << "Test case #" << idx++ << endl;
		for(int i = 2; i <= str.size(); i++){
			if(Next[i] > 0 and i % (i - Next[i]) == 0) 
				cout << i << " " << i / (i - Next[i]) << endl;
		}
		cout << endl;
	}
    return 0;
}