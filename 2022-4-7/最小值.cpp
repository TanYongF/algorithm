#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param k int整型 
     * @param x int整型 
     * @return int整型
     */
    int minMax(vector<int>& a, int k, int x) {
        priority_queue<int> q;
        for(auto num : a) q.push(num);
        while(k--){
            int maxx = q.top();
            cout << maxx << endl;
            q.pop();
            q.push(maxx - x);
        }
        return q.top();
        // write code here
    }
};
int main(){
    Solution s = Solution();
    vector<int> a = {7,2,1};
    
    // s.minMax();
}