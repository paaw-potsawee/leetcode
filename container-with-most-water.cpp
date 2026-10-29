// https://leetcode.com/problems/container-with-most-water/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ma = 0;
        int p1 = 0;
        int p2 = height.size() - 1;
        while(p1 < p2) {
            int n = p2 - p1;
            int a = n * min(height[p1], height[p2]);
            if (height[p1] > height[p2]) {
                p2--;
            } else {
                p1++;
            }
            ma = max(ma, a);
        }
        return ma;
    }
};
