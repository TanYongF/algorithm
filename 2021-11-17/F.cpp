#include<iostream>
using namespace std;
int T, n, now = 1;
int main(){
	cin >> T;
	while(T--){
		cin >> n;
		cout << "Case #" + to_string(now++) + ":" << endl << "YES" << endl;
		for(int j = 1; j <= n; j++) 
			for(int i = 1; i <= j; i++) 
				printf("%d %d %d %d %d %d %d %d\n", i,j  ,i,1,j  ,i,2,j);
	}
}