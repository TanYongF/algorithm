#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int flag[16][16]; //0 未被占领  1 2 分别占领
unordered_map<char,int> xx;
unordered_map<char,int> yy;
unordered_map<char, int> hh;
string s, t;
bool checkMove(char ch){
	return ch == 'U' or ch == 'D' or ch == 'L' or ch == 'R';
}

int main(int argc, char * argv[]){
	cin >> s >> t;
	xx['U'] = -1, xx['D'] = 1, xx['L'] = xx['R'] = 0;
	yy['L'] = -1, yy['R'] = 1, yy['D'] = yy['U'] = 0;
	// hh['L'] = 4, hh['R'] = 2, hh['D'] = 3, hh['U'] = 1;
	int n = s.size();
	int x1 = 0, y1 = 0, x2 = 15, y2 = 15;
	int h1 = 'R', h2 = 'L';
	int a = n - 1, b = 0;

	flag[0][0] = 1, flag[15][15] = 2;
	for(int i = 0; i < 256; i++){
		int cx1 = x1, cy1 = y1, cx2 = x2, cy2 = y2;
		//判断是否能否被摧毁
		bool at1 = false, at2 = false;
		if(not checkMove(s[i])){
			if(h1 == 'U' and y1 == y2 and x2 < x1){ a = i, b = 1; at1 = true;}
			if(h1 == 'R' and x1 == x2 and y2 > y1){ a = i, b = 1; at1 = true;}
			if(h1 == 'D' and y1 == y2 and x2 > x1){ a = i, b = 1; at1 = true;}
			if(h1 == 'L' and x1 == x2 and y2 < y1){ a = i, b = 1; at1 = true;}
		}
		if(not checkMove(t[i])){
			if(h2 == 'U' and y1 == y2 and x2 > x1){ a = i, b = 2; at2 = true;}
			if(h2 == 'R' and x1 == x2 and y2 < y1){ a = i, b = 2; at2 = true;}
			if(h2 == 'D' and y1 == y2 and x2 < x1){ a = i, b = 2; at2 = true;}
			if(h2 == 'L' and x1 == x2 and y2 > y1){ a = i, b = 2; at2 = true;}
		}
		if(at1 or at2){
			if(at1 and at2) a = i, b = 3;
			break;
		}
		cx1 = x1 + xx[s[i]], cy1 = y1 + yy[s[i]];
		cx2 = x2 + xx[t[i]], cy2 = y2 + yy[t[i]];
		//相撞
		if(cx1 == cx2 and cy1 == cy2 and flag[cx1][cy1] == 0){
			a = i;
			b = 3;
			break;
		}
		if(checkMove(s[i])){
			h1 = s[i];
			if(flag[cx1][cy1] != 2) flag[cx1][cy1] = 1, x1 = cx1, y1 = cy1; 
		}
		if(checkMove(t[i])){
			h2 = t[i];
			if(flag[cx2][cy2] != 1) flag[cx2][cy2] = 2, x2 = cx2, y2 = cy2; 
		}


	}


	if(b == 0){
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				if(flag[i][j] == 1) cnt1++;
				if(flag[i][j] == 2) cnt2++;
			}
		}
		if(cnt1 > cnt2) b = 1;
		else if(cnt1 < cnt2) b = 2;
		else b = 3;
		a = n - 1;
	}

	if(b == 1) cout << a + 1 << endl << "D" << endl;
	else if(b == 2) cout << a + 1 << endl  << "W" << endl;
	else cout << a + 1 << endl  << "P" <<endl;

    return 0;
}