#include <iostream>
#include <cstring>
using namespace std;
int T, n, V;
int w[1005], c[1005]; 
int dp[1005];
void CompletePack(int cur_w, int V){
	for(int i = 1; i <= V; i++){
		dp[i] = max(dp[i], dp[i-1] + cur_w); 
	}
}
void ZeroOnePack( int cur_w, int V){
	for (int i = V ; i >= 1; --i){
		dp[i] = max(dp[i], dp[i-1]+cur_w);
	}
}
void MultiplePack(int cur_w, int cur_v, int V){
	int newN = 0;
	int newV[10], newW[10];

	for(int j = 1; j <= cur_v; j *= 2){
		newV[newN] = j;
		newW[newN] = j * cur_w;
		newN++;
		cur_v-=j;
	} 
	if(cur_v > 0){
		newV[newN] = cur_v;
		newW[newN] = cur_v * cur_w;
		newN++;
	}
	for(int i = 0; i < newN; i++){
		for(int j = V; j >= newV[i]; j--){
			dp[j] = max(dp[j], dp[j-newV[i]]+ newW[i]);
		}
	}
}
int main(){
	cin >> T ;
	while(T--){
		cin >> n >> V;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i){
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < n; ++i){
			scanf("%d", &c[i]);
		}
		for (int i = 0; i < n; ++i){
			if(c[i] == 1){
				ZeroOnePack(w[i], V);	
			}else if(c[i] == -1){
				CompletePack(w[i], V);
			}else{
				MultiplePack(w[i], c[i], V);
			}
		}
		cout << dp[V] << endl;
	}
	return 0;

}