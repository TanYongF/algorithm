#include <iostream>
#include <climits>
using namespace std;
const int N =  2 * 100001;
struct Node{
    int l, r;
    int max_value;
}node[N * 4];
int n, m;
int w[N];
void getMax(int u){
    node[u].max_value = max(node[u << 1].max_value, node[u << 1 | 1].max_value); 
}

void build(int u, int l, int r){
    if(l == r) node[u] = {l, r, w[l]};
    else{
        node[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        getMax(u);
    }
}

int query(int u, int l, int r){
    if(l <= node[u].l && r >= node[u].r) return node[u].max_value;
    int mid = (node[u].l + node[u].r) >> 1;
    int max_value = INT_MIN;
    if(l <= mid) max_value = query(u << 1, l, r);
    if(r > mid) max_value = max(max_value, query(u << 1 | 1, l, r));
    return max_value;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    build(1, 1, n);
    while(m --){
        int x, y;   
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1, x+ 1 , y+1));
    }
    return 0;
}