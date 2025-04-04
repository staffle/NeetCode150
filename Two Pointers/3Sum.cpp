class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> ans;
        unordered_set<int> rest;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int left = -nums[i] - nums[j];
                if(rest.count(left)) {
                    vector<int> here = {left, nums[i], nums[j]};
                    ans.insert(here);
                }
            }
            rest.insert(nums[i]);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
