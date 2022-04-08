#include<bits/stdc++.h>
using namespace std;
const int N = 3;
//0:1 1:N 2:No 
// int line[3], colum[3], block[3];
bitset<3> line[3], colum[3], block[3];
vector<pair<int,int>> place;
vector<vector<char>> g(3, vector<char>(3,0));
int h[N][N];	
int ans = 0;

void setStat(int i, int j, int stat, int digit){
	line[i][digit] = stat;
	colum[j][digit] = stat;
	block[h[i][j]][digit] = stat;	
}
void dfs(vector<vector<char>> &g, int pos){
	if(pos == (int)place.size()){
		ans++;
		return;
	}
	auto [x, y] = place[pos];
	for(int i = 1; i <= 3; i++){
		if(line[x][i-1] == 0 and colum[y][i-1] == 0 and block[h[x][y]][i-1] == 0){
			setStat(x, y, 1, i-1);
			g[x][y] = '0' + i; 
			dfs(g, pos+1);
			setStat(x, y, 0, i-1);
		}
	}
}

int main(){
	int T,cx, cy;
	cin >> T;
	while(T--){
		ans = 0;
		for(int i = 0; i < 3; i++){
			line[i] = bitset<3>();
			colum[i] = bitset<3>();
			block[i] = bitset<3>();

		}
		memset(h, 0, sizeof(h));
		place.resize(0);
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> g[i][j];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> cx >> cy;
				h[cx][cy] = i; 
			}
		}

		
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
			if(g[i][j] != '*'){
				int digit = g[i][j] - '0' - 1;
				setStat(i, j, 1, digit);
			}else place.push_back({i,j});
		}	
		dfs(g, 0);
		if(ans == 0) cout << "No" << endl;
		else if(ans == 1){
			cout << "Unique" << endl;
			for(int i = 0; i < N; i++){
			  for(int j = 0; j < N; j++)  cout << g[i][j] ; 
			  cout << endl;
			}

		}else cout << "Multiple" << endl;

	}
}