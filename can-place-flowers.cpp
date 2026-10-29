// https://leetcode.com/problems/can-place-flowers/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 1) return n == 0;
            return n <= 1;
        }
        if (flowerbed[1] == 0 && flowerbed[0] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        int ln = flowerbed.size();
        for (int i = 1; i < ln - 1; i++) {
            if (n  <= 0) return true;
            if (flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1) {
                if (flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        if (flowerbed[ln - 2] == 0 && flowerbed[ln - 1] == 0) {
            n--;
        }
        return n <= 0;
    }
};
