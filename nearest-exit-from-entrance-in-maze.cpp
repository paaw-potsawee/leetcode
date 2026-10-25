#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        if (maze.size() == 0) return -1;
        const int col = maze[0].size();
        const int row = maze.size();
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            vector<int> tmp = q.front();
            q.pop();
            int i = tmp[0];
            int j = tmp[1];
            int step = tmp[2];
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                if (step != 0) return step;
            }
            for (auto& a:dir) {
                int ii = i + a[0];
                int jj = j + a[1];

                if (maze[ii][jj] == '.' && ii >= 0 && ii < row && jj >= 0 && jj < col) {
                    maze[ii][jj] = '+';
                    q.push({ii, jj, step + 1});
                }
            }
        }
        return -1;
    }
};
