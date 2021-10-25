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
int dp[300005];
ll heigth[300005];
stack<int> st;
int main(){
    cin >> num;
    st.push(0);
    for(int i = 1; i <= num;i++){
        cin >> heigth[i];
    }
    dp[1] = 1;
    memset(dp, INT_MAX, sizeof(dp));
    for (int i = 1; i <= num; i++){
        dp[i+1] = min(dp[i+1],dp[i]+1);
        int caseTwoIndex = i+1, caseThreeIndex = i+1;
        curH = num[i];
         st.push(curH);
        if(num[i+1] > num[i]){
            //case Two
            st.push(num[i+1]);
            
        }
       
        while(){
            if(num[caseThreeIndex] >= cuH && num[caseThreeIndex] <= st.top()){
                st.push(num[caseThreeIndex++]);
            }
        }

    }
    

}

