class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums) {
            int dp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = dp;
        }

        return prev1;
    }
};