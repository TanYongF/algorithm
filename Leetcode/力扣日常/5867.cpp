#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int len = word.length();
        for(string::iterator it = word.begin(); it!=word.end();it++){
            if(*it == ch) {reverse(word.begin(), it+1); break;}
        }
        return word;

    }
};

int main(int argc, char * argv[]){

    Solution s = Solution();
    cout << s.reversePrefix("a", 'a');
    


    return 0;
}