#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
int a[105],b[32];

int cmp(int a,int b){
    return a>b;
}
int main(){
	cin >> M >> N;
	for (int i = 0; i < M; ++i){
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i){
		cin >> b[i];
	}
	sort(b,b+N);
	int cur_size = M;
	long long  sum = 0;
	for (int i = 0,k = 0; i < M; ++i){
		if(b[k]-1 != i){
			sum += a[i];
			cur_size--;
			a[i] = 0;
		}else{
			k++;
		}
	}
	sort(a, a+M,cmp);
	for(int i = 0; i < cur_size; i++){
		if(a[i] > sum){
			sum += a[i];
		}else{
			sum *= 2;
		}
	}
	printf("%lld",sum);
	return 0;
}