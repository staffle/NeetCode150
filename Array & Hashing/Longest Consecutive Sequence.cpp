class Solution {
public:

    int solve(int num,  unordered_set<int>& cache, unordered_map<int, int>& ans_cache) {
        if(ans_cache.find(num) != ans_cache.end()) {
            return ans_cache[num];
        }
        if(cache.find(num + 1) != cache.end()) {
            int nxt = solve(num + 1, cache, ans_cache);
            return ans_cache[num] = 1 + nxt;
        }
        return ans_cache[num] = 1;
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache(begin(nums), end(nums));
        unordered_map<int, int> ans_cache;

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int ans_here = solve(nums[i], cache, ans_cache);
            if(ans_here > ans)
                ans = ans_here;
        }
        return ans;
    }
};
