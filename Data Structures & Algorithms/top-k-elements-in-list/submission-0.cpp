class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }

        vector<pair<int, int>> v;

        for(auto it : mp){
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end());

        vector<int> res;

        int j = v.size() - 1;

        while(k > 0){
            res.push_back(v[j].second);
            k--;
            j--;
        }

        return res;
    }
};
