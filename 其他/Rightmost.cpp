#include <iostream>
#include <cmath>
using namespace std;
int T, M;
int a[]={2,4,8,6},b[]={3,9,7,1},d[]={7,9,3,1},e[]={8,4,2,6};
int cal(int N){
		int NN = N % 10;
		if(NN == 1 || NN == 5 || NN== 6 || NN == 0 || NN == 9) return NN;
		if (NN == 4) return 6;
		if(NN == 2) return  (N % 4 == 0 ? 6 : a[N%4 - 1]);
		if(NN == 3) return  (N % 4 == 0 ? 1 : b[N%4-1]);
		if(NN == 7) return  (N % 4 == 0 ? 1 : d[N%4-1]);
		if(NN == 8) return  (N % 4 == 0 ? 6:  e[N%4-1]);
}
int main(){
	cin >> T;
	while(T--){
		cin >> M;
		cout << cal(M) << endl;
	}
	return 0;
}