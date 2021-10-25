class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> grap[105];
        int  path[105][105];
        for(unsigned i = 0; i < times.size(); ++i) {
            int from,to,val;
            from = times[i][0];
            to   = times[i][1];
            val  = times[i][2];
            grap[from].push_back(to);
            // grap[from][to] = 1;
            path[from][to] = val;
        }
        


    }
};