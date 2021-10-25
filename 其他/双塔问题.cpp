#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
int a[101]; //水晶高度
int dp[101][2001]; //定义前i个水晶两者相差j高度的时候比较高的那个水晶的高度
int main(){
    int num ;
    int sum = 0;
    cout << "请输入所有水晶的数量" << endl;
    cin >> num;
    for(int i = 1; i <= num; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < 2002; i++){
        dp[0][i] = -INF;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= num; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = dp[i-1][j] > dp[i-1][j + a[i]] ?  dp[i-1][j] : dp[i-1][j + a[i]]; //如果不放或者是放在矮的上面但是还是低于高的情况
            if( j >= a[i]){
                dp[i][j] = max(dp[i][j] , dp[i-1][j-a[i]]+a[i]); //放在高的上面
            }else{
                dp[i][j] = max(dp[i][j], dp[i-1][a[i]-j]+j); //放在矮的上面超过高的情况
            }
        }
    }
    if(dp[num][0] > 0 ){
        cout << dp[num][0];
    }else{
        cout << "Impossible" ;
    }
    return 0;
}