// https://leetcode.com/problems/keys-and-rooms/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int explore(vector<vector<int>>& rooms, int n, vector<bool>& visited) {
        (visited)[n] = true;
        int total = 1;
        for (int i = 0; i < rooms[n].size(); i++) {
            if (visited[rooms[n][i]]) continue;
            total += explore(rooms, rooms[n][i], visited);
        }
        return total;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        return explore(rooms, 0, visited) == rooms.size();
    }
};

