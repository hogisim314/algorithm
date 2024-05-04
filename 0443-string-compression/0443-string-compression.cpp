class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=0;
        string temp;
        vector<string> list;
        for (int i=0; i<chars.size(); i++) {
            if (temp=="") {
                temp+=chars[i];
                if (i==chars.size()-1) {
                    list.push_back(temp.substr(0,1));
                }
            }
            else if (temp[temp.size()-1]!=chars[i]) {
                list.push_back(temp.substr(0,1));
                if (temp.size()!=1) {
                    list.push_back(to_string(temp.size()));
                }
                temp="";
                temp.push_back(chars[i]);
                if (i==chars.size()-1) {
                    list.push_back(temp.substr(0,1));
                }
            }
            else if (temp[temp.size()-1]==chars[i]) {
                temp+=chars[i];
                if (i==chars.size()-1) {
                    list.push_back(temp.substr(0,1));
                    list.push_back(to_string(temp.size()));
                }
            }
        }
        chars.clear();
        for (int i=0; i<list.size(); i++) {
            for (int j=0; j<list[i].size(); j++) {
                chars.push_back(list[i][j]);
            }
        }
        for (int i=0; i<chars.size(); i++) {
            cout<<chars[i]<<' ';
        }
        return chars.size();
    }
};