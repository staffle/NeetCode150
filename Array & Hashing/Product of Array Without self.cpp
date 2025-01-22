class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> suffix(N, 1), prefix(N, 1);
        for(int i = 0; i < N; i++) {
            suffix[N - i - 1] = nums[N - i - 1];
            prefix[i] = nums[i];
            if(i) prefix[i] *= prefix[i - 1];
            if(i) suffix[N - i - 1] *= suffix[N - i];
        }
        vector<int> ans(N, 1);
        for(int i = 0; i < N; i++) {
            if(i) ans[i] *= prefix[i - 1];
            if(N - 1 - i) ans[i] *= suffix[i + 1];
        }
        return ans;
    }
};
