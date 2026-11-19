// https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (int i = 0; i < piles.size(); i++) {
            r = max(piles[i], r);
        }

        int k;
        int preValid = 0;
        while (l <= r) {
            k = (r - l) / 2 + l;
            int total = h;
            for (int i = 0; i < piles.size(); i++) {
                total -= piles[i] % k == 0 ? (piles[i] / k) : (piles[i] / k + 1);
                if (total < 0) {
                    break;
                }
            }
            if (total >= 0) preValid = k;
            if (total < 0) {
                l =  k + 1;
            } else {
                r = k - 1;
            }
        }
        return preValid;
    }
};
