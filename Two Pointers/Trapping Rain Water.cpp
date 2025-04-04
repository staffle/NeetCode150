class Solution {
public:
    int trap(vector<int>& a) {
        vector<int> suffix = a;
        int n = a.size();
        for(int i = n - 2; i >= 0; i--) 
            suffix[i] = max(suffix[i], suffix[i + 1]);

        int p_max_so_far = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            p_max_so_far = max(p_max_so_far, a[i]);
            int height = min(p_max_so_far, suffix[i]);
            ans += max(0, height - a[i]);
        }
        return ans;
    }
};
