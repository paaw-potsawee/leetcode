// https://leetcode.com/problems/unique-number-of-occurrences/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        unordered_set<int> st;
        int n=arr.size();
        bool ans=true;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(auto it:mpp){
            st.insert(it.second);
        }
        if(st.size()==mpp.size()){
            ans=true;
        }
        else{
            ans=false;
        }
        return ans;
    }
};
