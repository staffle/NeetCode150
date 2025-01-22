class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        for(int i = 0, j = n - 1; i < j;) {
            if(a[i] + a[j] > target) {
                j--;
            }
            else if(a[i] + a[j] < target){
                i++;
            }
            else {
                return {i + 1, j + 1};
            }
        }
    }
};
