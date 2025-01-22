class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> occoured;
        for(auto& num: nums) {
            if(occoured.find(num) != occoured.end())
                return true;
            occoured.insert(num);
        }
        return false;
    }
};
