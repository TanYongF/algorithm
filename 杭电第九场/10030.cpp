#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = 5005;
int T,n;
vector<ll> a(inf), b(inf), sortedA(inf);
unordered_map<ll,P> mp(inf);
int main(int argc, char * argv[]){
    cin >> T;
    while(T--){
        cin >> n;
        ll maxNum = 0 ,minNum = 0;
        mp.clear();
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        sortedA = vector<ll>(a);
        sort(sortedA.begin()+1, sortedA.begin()+1+n);
        reverse(b.begin()+1, b.begin()+1+n);
        for(int i = 1; i <= n; i++){
            if(mp.find(sortedA[i])!=mp.end()) continue;
            maxNum = 0, minNum = 0;
            ll curScore = sortedA[i] + b[1];
            int k = 2;
            for(int j = n; j >= 1 && k <= n;j--){
                if(j == i) continue;
                while(k <= n && b[k] + sortedA[j] <= curScore){
                    k++;
                }
                // cout << "cal: " << b[k] << " " << sortedA[j] << " curScore: " << curScore << endl;
                if(k<=n) minNum++;
                k++;
            }

            ll curMaxScore = sortedA[i] + b[n];
            k = n-1;
            for(int j = 1; j <= n  && k >= 1;j++){
                if(j == i) continue;
                while(k >= 1 && b[k] + sortedA[j] > curMaxScore){
                    k--;
                }
                if(k>=1) maxNum++;
                k--;
            }
            mp[sortedA[i]] = P( n - maxNum, minNum+1);            
        }
        for(int i = 1; i <= n; i++){
            cout << mp[a[i]].first << " " << mp[a[i]].second << endl;}
    }
    return 0;
}