class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for (char a : s) {
            mp[a]++;
        }
        for (char a : t) {
            if (mp.count(a)) {
                mp[a]--;
                if (mp[a] == 0) {
                    mp.erase(a);
                }
            } else {
                mp[a]++;
            }
        }
        return mp.size() == 0;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> mp;
        for (int i = 0; i < strs.size(); i++) {
            mp[strs[i]]++;
        }

        for (int i = 0; i < strs.size(); i++) {
            string curr = strs[i];
            vector<string> res;
            if (mp[curr] != 0) {
                res.push_back(curr);
                mp[curr]--;
                for (int j = i; j < strs.size(); j++) {
                    string nextCurr = strs[j];
                    if (curr.length() == nextCurr.length() && mp[nextCurr] != 0) {
                        if (isAnagram(curr, nextCurr)) {
                            res.push_back(nextCurr);
                            mp[nextCurr]--;
                        }
                    }
                }
                result.push_back(res);
            }
        }
        return result;
    }
};
