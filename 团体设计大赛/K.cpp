#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(a, val) memset(a, val, sizeof(a))

const int MAXN = 500;
int main(){
	int num, n;
	int g[MAXN][MAXN];
	ms(g, 0);
	cin >> n;
	char sex[MAXN];
	ms(sex, 0);
	for(int i = 0 ;i < n; i++){
		cin >> sex[i];
		cin >> num;
		for(int j = 0; j < num; j++){
			string str;
			cin >> str;
			int k = 0;
			while(str[k] != ':') k++;
			int idx = stoi(str.substr(0, k)), score = stoi(str.substr(k+1));
			g[i][idx] = score;
		}
	}

	return 0;
}