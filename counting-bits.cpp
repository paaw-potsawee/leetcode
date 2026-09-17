// https://leetcode.com/problems/counting-bits/description/
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        vector<int> store(n + 1); 
        res[0] = 0;
        if (n == 0) return res;
        res[1] = 1;
        store[0] = 0;
        store[1] = 1;
        
        int tracker = 0;
        int maxCheck = 2;
        for (int i = 2; i <= n; i++) {
            // look up at tracker
            store[i] = store[tracker] + 1;
            res[i] = store[i];
            if (tracker == maxCheck - 1) {
                maxCheck *= 2;
                tracker = 0;
            } else {
                tracker++;
            }
        }
        
        return res;
    }
};

int main() {
    auto sol = Solution();
    auto res = sol.countBits(5);
    for (auto i:res) {
        cout << i << " ";
    }
    return 0;
}