// https://leetcode.com/problems/reverse-vowels-of-a-string/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < 5; i++) {
            if (c == vowels[i] || c == vowels[i] - 32) {
                return true;
            }
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int st,en;
        st =  0;
        en = s.length() - 1;
        while (st < en) {   
            while(st < s.length() && !isVowel(s[st])) st++;
            while(en >= 0 && !isVowel(s[en])) en--;
            if (st >= en) return s;
            if (st >= s.length() || en < 0) return s; 
            char tmp = s[st];
            s[st] = s[en];
            s[en] = tmp;
            st++;
            en--;
        }
        return s;

    }
};
