#include<iostream>
#include<unordered_set>
#include<queue>
#include<climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 102400;
int T,x,y,n;
vector<vector<int>> vs(MAXN);
vector<int> inDegree(MAXN,0);
unordered_set<int> st;
vector<int> father(MAXN);
int getFather(int val){
	if(father[val] != val) father[val]= getFather(father[val]);
	return father[val];
}
void unionFather(int a, int b){
	int fatherA = getFather(a);
	int fatherB = getFather(b);
	father[fatherB] = father[fatherA];
}
//查找入度，然后判断环
int slove(){
	int root = -1;
	//判断是否为森林
	for(auto it : st){
		if(root == -1) root = getFather(it);
		else if(getFather(it) != root) return false;
	}
	if(inDegree[root] != 0) return false;
	//判断是否有环
	queue<int> q;
	q.push(root);
	int cur;
	n = 1;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		for(auto next : vs[cur]){
			if(inDegree[next] != 1) return false;
			inDegree[next]--;
			q.push(next);
		}
	}

	for(int i = 0; i < MAXN; i++) father[i] = i;
	vs = vector<vector<int>>(MAXN);
	st.clear();
	inDegree = vector<int>(MAXN, 0);

	return true;
}
int main(int argc, char * argv[]){
	for(int i = 0; i < MAXN; i++) father[i] = i;
	// cout << 1;
	int cnt = 0;
	while(~scanf("%d%d", &x, &y)){
		if(x < 0) return 0;
		if(x == 0 && y == 0) {
			cnt++;
			bool ok = slove();
           	if(ok) printf("Case %d is a tree.\n", ++cnt);
            else printf("Case %d is not a tree.\n", ++cnt);
			continue;
		}
		vs[x].push_back(y);
		unionFather(x,y);
		st.insert(x);
		st.insert(y);
		inDegree[y]++;
		n = max(n, x);
	}
    return 0;
}