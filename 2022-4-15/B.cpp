#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T, m, n;
int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
int main(int argc, char * argv[]){
	cin >> m >> n;
	vector<string> v;
	for(int i = 0; i < m; i++){
		string row;
		cin >> row;
		v.push_back(row);
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(v[i][j] == '.') continue;
			int a = 1, b = 1, c = 1, d = 1;
			//1x`x`
			for(int k = i - 1; k >= 0; k--) {
				if(v[k][j] == v[i][j]) a++;  
				else break;
			}
			for(int t = i + 1; t < m; t++) {if(v[t][j] == v[i][j]) a++; else break;}

			//2
			for(int k = j - 1; k >= 0; k--) {if(v[i][k] == v[i][j]) b++ ;  else break;}
			for(int t = j + 1; t < m; t++) {if(v[i][t] == v[i][j]) b++;  else break;}

			//3
			for(int k = i - 1, t = j - 1; k >= 0 and t >= 0; k--, t--) {if(v[k][t] == v[i][j])  c++;  else break;}
			for(int k = i + 1, t = j + 1; k < m and t < n; k++, t++) {if(v[k][t] == v[i][j]) c++;  else break;}

			//4
			for(int k = i - 1, t = j + 1; k >= 0 and t < n; k--, t++) {if(v[k][t] == v[i][j]) d++;  else break;}
			for(int k = i + 1, t = j - 1; k < m and t >= 0; k++, t--) {if(v[k][t] == v[i][j]) d++;  else break;}

			if(a >= 4 or b >= 4 or c >= 4 or d >= 4){
				if(v[i][j] == 'r') cout << "kou";
				if(v[i][j] == 'p') cout << "yukari";
				return 0 ;
			}
		}
	}
	cout << "to be continued" << endl;
    return 0;
}