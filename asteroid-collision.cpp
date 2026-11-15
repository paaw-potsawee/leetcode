// https://leetcode.com/problems/asteroid-collision/description/
class Solution {
private:
    bool collide(vector<int>& st, int ast) {
        if (st.size() == 0) return true;
        if (st.back() < 0 || ast > 0) return true;
        if (st.back() == -(ast)) {
            st.pop_back();
            return false;
        }
        if (st.back() < -(ast)) {
            st.pop_back();
            return collide(st, ast);
        }
        return false;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st = {};
        for (int i = 0; i < asteroids.size(); i++) {
            if (st.size() == 0) st.push_back(asteroids[i]);
            else {
                if (st.back() > 0 && asteroids[i] < 0) {
                    // collides
                    if (collide(st, asteroids[i])) {
                        st.push_back(asteroids[i]);
                    }
                } else {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};
