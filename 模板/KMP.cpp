#include <bits/stdc++.h>
using namespace std;
// typedef long long 
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
//pattern: a  b  a  b  a  b
//next:   -1  0  0  1  2  3
//next[i]代表前i个字符的组成的后缀子串与前缀子串的公共最大长度。
vector<int> getNext(string &pattern){
     int i = 0, j = -1;
     vector<int> next = vector<int>(pattern.size());
     next[0] = -1;
     while(i < (int)pattern.size()){
          if(j == -1 or pattern[i] == pattern[j]){
               next[++i] = ++j;
          }else{
               j = next[j];
          }  
     }
     return next;
}
int kmp(string &t, string &p){
     auto next = getNext(p);
     int i = 0, j = 0;
     while(i < (int)t.size() and j < (int)p.size()){ // remeber that  Member type size_type is an unsigned integral type.
          if(j == -1 or t[i] == p[j]){
               i++, j++;
          }else{
               j = next[j];
          }
     }
     if(j == (int)p.size()) return i-j;
     else return -1;
}

int main(int argc, char * argv[]){
	string s1;
	string s2;
	cin >> s1 >> s2 ;

	cout << kmp(s1, s2);

	// vector<int> 

    return 0;
}
