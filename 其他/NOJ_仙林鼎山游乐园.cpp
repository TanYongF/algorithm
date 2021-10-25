#include <iostream>
#include <cstring>
using namespace std;
int const MAX = 55;
bool E[MAX][MAX];
void floyd(int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if(E[i][j] && E[j][k]){
					E[i][k] = true;
				}
				
			}

		}
	}
}
bool check(int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(E[i][j] && E[j][i]) {
				return true;
			}
		}
	}
	return false;
}
int main(){
	int T;		//测试用例数目
	cin >> T;
	while(T--){
		int n;
		int e;
		cin >> n >> e;
		int first , target;

        memset(E, false, sizeof(E));
		for (int i = 0; i < e; ++i)
		{
			cin >> first >> target;
			E[first][target] = true;
		}
		floyd(n);
		if(check(n)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}

	}
	return 0;
}