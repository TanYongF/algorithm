
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int sg[maxn], vis[maxn];
void init() {
    int i, j, k;
    sg[0] = 0, sg[1] = 1;
    for(i = 2; i <= 1000; i++) {
        memset(vis, 0, sizeof(vis));
        for(j = 1; j < i; j++)
            vis[sg[j]^sg[i - j]] = 1; //拆分
        // for(j = 0; j <= i; j++)
        //     vis[sg[j]] = 1;       //取石子
        for(j = 0;; j++)
            if(!vis[j])
                break;
        sg[i] = j;
    }
    for(i = 1; i <= 100; i++)
        cout << sg[i] << endl;
}
int main() {
    init();
}