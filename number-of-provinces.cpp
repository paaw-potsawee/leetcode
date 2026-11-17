// https://leetcode.com/problems/number-of-provinces/description/
class Solution {
private:
    void explore(vector<vector<int>>& isConnected, int current, vector<bool>& visited) {
        if (visited[current]) return;
        visited[current] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[current][i] == 1 && !visited[i]) {
                explore(isConnected, i, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const auto n = isConnected.size();
        int total = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if(!visited[i]) {
                explore(isConnected, i, visited);
                total++;
            }
        }
        return total;
    }
};
