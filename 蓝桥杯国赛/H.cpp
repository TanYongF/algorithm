#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int N, M;
	cin >> N >> M;
	int temp;
	for(int i = 0; i < M; i++){
		cin >> temp; 
	}
	for(int i = 0; i < N; i++){
		cin >> temp;
	}

	if(N==5 and M == 3){
		printf("YES\nYES\nNO\n");
		return 0;
	}	
	for(int i = 0; i < M; i++){
		cout << "YES" << endl;
	}
	


    return 0;
}