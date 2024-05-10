class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for (int i=0; i<arr.size(); i++) {
            m[arr[i]]++;
        }
        set<int> s;
        for (auto itr = m.begin(); itr!=m.end(); itr++) {
            if (s.find(itr->second)!=s.end()) {
                return false;
            }
            s.insert(itr->second);
        }
        return true;
    }
};