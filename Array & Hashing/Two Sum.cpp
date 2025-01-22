class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> have;
        for(int i = 0; i < (int)nums.size(); i++) {
            if(have.find(target- nums[i]) != have.end())
                return {have[target- nums[i]], i};
            have[nums[i]] = i;
        }
        return {-1, -1};
    }
};
