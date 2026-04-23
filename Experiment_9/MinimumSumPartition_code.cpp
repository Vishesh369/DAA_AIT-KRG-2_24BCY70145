class Solution {
public:
    int minDifference(vector<int>& arr) 
{
        int n = arr.size();
        int totalSum = 0;
        for (int x : arr) totalSum += x;
    
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }} }
        int s1 = 0;
        for (int i = target; i >= 0; i--) {
            if (dp[i]) {
                s1 = i;
                break;
            }} return totalSum - 2 * s1;
    }};
