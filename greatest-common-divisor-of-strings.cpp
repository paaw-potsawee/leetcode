// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
class Solution {
private:
    bool isSub(string str, string sub) {
        if (sub.length() == 0) return false;
        if (str.length() % sub.length() != 0) return false;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != sub[i % sub.length()]) return false;
        }
        return true;
    }
    string getS(string str1, string str2) {
        if (isSub(str1, str2)) {
            return str2;
        }
        // assume str2 is shorter or equal than str1
        // use str2 as prefix
        int i = str2.length() / 2;
        while (i >= 0) {
            if (str1[i] == str2[i] && isSub(str1, str2.substr(0,i)) && isSub(str2, str2.substr(0,i))) {
                return str2.substr(0,i);
            } else if (i == 0) break;
            i--;
            while (i > 0 && str1.length() % i != 0 && str2.length() % i != 0) {i--;}
        }
        return "";
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() >= str2.length())
            return getS(str1, str2);
        return getS(str2, str1);
    }
};
