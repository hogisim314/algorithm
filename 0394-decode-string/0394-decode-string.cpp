class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> num_st;
        string result = "";
        int num = 0;
        for (int i=0; i<s.size(); i++) {
            if (isdigit(s[i])) {
                num = num*10 + (s[i]-'0');
            }
            else if (isalpha(s[i])) {
                result+=s[i];
            }
            else if (s[i]=='[') {
                st.push(result);
                result = "";
                num_st.push(num);
                num=0;
            }
            else if (s[i]==']') {
                int prev_num = num_st.top();
                num_st.pop();
                string prev_str = st.top();
                st.pop();
                for (int i=0; i<prev_num; i++) {
                    prev_str += result;
                }
                result = prev_str;
            }
        }
        return result;
    }
};