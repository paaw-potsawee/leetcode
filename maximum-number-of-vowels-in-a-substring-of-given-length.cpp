// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
class Solution {
private:
    bool isVowels(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int count = 0;
        for (int j = 0; j < k; j++) {
            if (isVowels(s[j])) count++;
        }
        int mCount = count;
        int i = 0;
        k--;
        while(k < s.length() - 1) {
            if (isVowels(s[i])) count--;
            i++;
            k++;
            if (isVowels(s[k])) count++;

            if (count > mCount) mCount = count;
        }
        return mCount;
    }
};
