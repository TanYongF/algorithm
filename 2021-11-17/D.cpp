#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 1004;

int T, m, n;
int valueA, valueB;
string A[MAXN], B[MAXN];
void printAns(bool needInv){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(needInv) cout << (A[i][j] == '.' ? 'X' : '.');
			else cout << A[i][j];
		}
		cout << endl;
	}
}
int main(){	
	cin >> m >> n;
	int diff = 0, maxOperation = m * n / 2;
	for(int i = 0; i < m; i++) cin >> A[i];
	for(int i = 0; i < m; i++) cin >> B[i];
	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(A[i][j] != B[i][j]) diff++;
	if(diff <= maxOperation) printAns(false);
	else printAns(true); 
	return 0;
}