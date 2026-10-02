// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st = {};
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if (token == "+") {
                int n1 = st.back();st.pop_back();
                int n2 = st.back();st.pop_back();
                st.push_back(n2 + n1);
            } else if (token == "-") {
                int n1 = st.back();st.pop_back();
                int n2 = st.back();st.pop_back();
                st.push_back(n2 - n1);
            } else if (token == "*") {
                int n1 = st.back();st.pop_back();
                int n2 = st.back();st.pop_back();
                st.push_back(n2 * n1);
            } else if (token == "/") {
                int n1 = st.back();st.pop_back();
                int n2 = st.back();st.pop_back();
                st.push_back(n2 / n1);
            } else {
                st.push_back(stoi(token));
            }
        }
        return st.back();
    }
};