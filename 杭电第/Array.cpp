#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 1e6+10;
// 修改差分 来维护前缀和的前缀和
// c1 为差分d c2为d*i  c3 为d*i*i
LL c1[N * 2], c2[N * 2], c3[N * 2];
LL sum(int x) {
    LL res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        res += c1[i] * (x + 2) * (x + 1) - c2[i] * (2 * x + 3) + c3[i];
    }
    return res / 2;
}
void add(int x, LL d, int n) {
    for (int i = x; i <= n; i += i & -i) {
        c1[i] += d;
        c2[i] += d * x;
        c3[i] += d * x * x;
    }
}
int a[N];
vector<int> b[N];
int main() {
    int T;
    int n;
    cin >> T;
    while(T--){
        cin >> n;
        // scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            // scanf("%d", &a[i]);
            cin >> a[i];
            b[a[i]].push_back(i);
        }
        const int wc = n + 1;  // 偏移量，把[-n,n] 平移到 [1,2n+1]
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            b[i].push_back(n + 1);
            int last = 0;
            for (int j = 0; j < b[i].size(); j++) {
                int y = 2 * j - last + wc, x = 2 * j - (b[i][j] - 1) + wc;
                // 查询 sum([1,t-1] 的权值和), 其中t在[x,y]范围内，
                ans += sum(y - 1) - (x >= 3 ? sum(x - 2) : 0);
                // [x,y] 这些数的权值+1
                add(x, 1, 2 * n + 1);
                add(y + 1, -1, 2 * n + 1);
                last = b[i][j];
            }
            last = 0;
            for (int j = 0; j < b[i].size(); j++) {
                int y = 2 * j - last + wc, x = 2 * j - (b[i][j] - 1) + wc;
                add(x, -1, 2 * n + 1);
                add(y + 1, 1, 2 * n + 1);
                last = b[i][j];
            }
        }
        // printf("%lld\n", ans);
        cout << ans;
    }
    return 0;
}