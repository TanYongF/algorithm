#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
int x[4] = {0,1,0,-1};
int y[4] = {1,0,-1,0};
char a[510][510];
bool check (int j, int k){
	for (int i = 0; i < 4; ++i)
	{
		j += x[i];
		k += y[i];
		if(j >= 0 && j < m && k >=0 && k < n){
			if(a[j][k] == 'W'){
				return false;
			}
		}
		j -= x[i];
		k -= y[i];

	}
	return true;
}

int main(){
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(a[i][j] == 'S'){
				if (check(i,j))
				{
					continue;
				}else{
					cout << "No";
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(a[i][j] == '.'){
				cout << 'D';
			}else{
				cout << a[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}