#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	
    return 0;
}


const int MAXN = 1e5 + 10;
int fa[MAXN];
void init(){
	for(int i = 0; i < N; i++) fa[i] = i;
}
int getFa(int val){
	return fa[val] == val ? val : fa[val] = getFa(fa[val]);
}
void merge(int v1, int v2){
	fa[getFa(v1)] = getFa(v2);
 }
