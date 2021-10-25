#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
int num;

set<char> st;
int father[28];
int findset(int x)  {    
    if(x != father[x])    
        father[x]=findset(father[x]);//查的过程中进行路径压缩，有效加快并查集运算    
    return father[x];    
}    
    
int unionset(int a, int b){    
    int x=findset(a);    
    int y=findset(b);    

    if(x != y)     //不在同一根上，进行合并操作      
        father[y]=x;
    return 0;    
} 
int n;
string ss;
int main(int argc, char * argv[]){
	cin >> n;
	// memser(father, -1, sizeof(father));
	for(unsigned i = 0; i < 27; ++i) {
		father[i] = i;
	}
	while(n--){
		cin >> ss;
		int first = (int)(ss[0]-'a');
		st.insert(ss[0]);
		int ffather = findset(first);
		for(unsigned i = 1; i < ss.size(); ++i) {
			int ch = (int)(ss[i]-'a');
			st.insert(ss[i]);
			unionset(ffather, ch);
		}
	}
	int allCharNum = st.size();
	for(unsigned i = 0; i <= 26; ++i) {
		if(father[i] != i){
			allCharNum--;
		}
	}
	cout << allCharNum;


	/* code */


    return 0;
}