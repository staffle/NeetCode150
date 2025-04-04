class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while(i < j) {
            int h_here = min(arr[j], arr[i]);
            int ans_here = (j -  i) * h_here;
            if(ans_here > ans) ans = ans_here;
            if(arr[i] == h_here) i++;
            else  j--;
        }
        return ans;
    }
};
