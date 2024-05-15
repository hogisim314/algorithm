class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i=0; i<asteroids.size(); i++) {
            if (!st.empty()) {
                if (st.top()>0 && asteroids[i]<0) {
                    while(true) {
                        //stack끝까지 다 뚫고 내려갔을 때 
                        //같은 음수 만났을 때 
                        //더이상 안지워질때 (양수 절댓값이 클 때)
                        if (st.empty() || st.top() <0) {
                            st.push(asteroids[i]);
                            break;
                        }
                        if (st.top() > 0 && abs(st.top())>abs(asteroids[i])) {
                            break;
                        }
                        if (st.top()>0 && abs(st.top())==abs(asteroids[i])) {
                            st.pop();
                            break;
                        }
                        st.pop();
                    }
                }
                else {
                    st.push(asteroids[i]);
                }
                continue;
            }
            st.push(asteroids[i]);
        }
        vector<int> ans;
        stack<int> temp;
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()) {
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }
};