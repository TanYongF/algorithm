#include <iostream>
#include <stdio.h>
#include <cstring>
#include <climits>
#define V 5005
using namespace std;
#define ms(s,val) memset(s, val, sizeof(s))
typedef long long ll;
typedef unsigned long long ull;
int n;
ll map[V][V];
ll key[V];
bool visit[V];
int x[V],y[V];
int minKey(){
    int min = INT_MAX;
    int pos = -1;
    for(int i = 0; i < n; i++){
        if( key[i] < min && !visit[i]){
            min = key[i];
            pos = i;
        }
    }
    return pos;
}
void update(int pos){
    for(int i = 0; i < n; i++){
        if( !visit[i] && map[pos][i] < key[i]){
            key[i] = map[pos][i];
        }
    }
}
 
ll prim(){
    ll max = -1;
    for(int i = 0; i < n;i++){
        visit[i] = false;
    }
    visit[0] = true;
    for(int i = 0; i < n;i++){
        key[i] = map[0][i];
    }
    for(int i = 1; i <= n-1; i++){
        int pos = minKey();
        visit[pos] = true;
        if(key[pos] > max) {
            max = key[pos];
        }
        update(pos);
    }
    return max;
}
 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ms(x,0);
        ms(y,0);
        scanf("%d",&n);
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                map[i][j] = 1.L * abs(x[i]-x[j]) * abs(x[i]-x[j]) + 1.L* abs(y[i]- y[j])* abs(y[i]-y[j]);
                map[j][i] = 1.L * abs(x[i]-x[j]) * abs(x[i]-x[j]) + 1.L* abs(y[i]- y[j])* abs(y[i]-y[j]);
            }
        long long result = 0;
        result = prim();
        cout << result << endl;
    }
    return 0;
}