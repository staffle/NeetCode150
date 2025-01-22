class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq; 
        for(auto i: nums)
            freq[i]++;
        set<pair<int, int>, greater<pair<int, int>>> hp;
        for(auto& it: freq) {
            hp.insert({it.second, it.first});
        }
        vector<int> ans;
        for(auto& i: hp) {
            ans.push_back(i.second);
            if(ans.size() == k)
                return ans;
        }
    }
};
