#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char cstr[2000001];
int L[2000000];
int R[2000000];
vector<pair<int, int>> v;

int main(int argc, const char * argv[]) {
    scanf("%s", cstr);
    string s(cstr);
    int len = (int) s.length();

    // 对于每个字符a，寻找最近的左侧s
    int left = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == 's') {
            left = i;
        }
        else if (s[i] == 'a') {
            L[i] = left;
        }
    }
    
    // 对于每个字符a，寻找最近的右侧d
    int right = -1;
    for (int i = len - 1; i > -1; i--) {
        if (s[i] == 'd') {
           right = i;
        }
        else if (s[i] == 'a') {
            R[i] = right;
        }
    }
    
    // 找到所有有效的左边界s中a右边界d的子串，收集区间信息，并保留相同左端点中找右端点最左的区间
    int lastL = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            if (L[i] != -1 && R[i] != -1) {
                if (L[i] != lastL)
                    v.push_back({L[i], R[i]});
                lastL = L[i];
            }
        }
    }
    
    // 累计最终结果
    int vlen = (int) v.size();
    lastL = -1;
    long long res = 0;
    for (int i = 0; i < vlen; i++) {
        res += (long long) (v[i].first - lastL) * (len - v[i].second);
        lastL = v[i].first;
    }
    printf("%lld\n", res);
    
    return 0;
}
