MINIMUM SUM PARTITION ALGORITHM
===============================

Problem:
Given an array of positive integers, partition it into two subsets such that the absolute difference between the subset sums is minimized.

Approach:
This problem can be solved using a dynamic programming technique based on subset sum.

Steps:
1. Calculate the total sum of all array elements.
2. Compute the target as half of the total sum: `half = total / 2`.
3. Use a boolean DP array `dp[0..half]` where `dp[j]` is true if a subset with sum `j` can be formed.
4. Initialize `dp[0] = true` because a sum of 0 is always possible with an empty subset.
5. For each array element `value`, update the DP array from `half` down to `value`:
   - `dp[j] = dp[j] || dp[j - value]`
6. After processing all elements, find the largest `j` such that `dp[j]` is true.
   This represents the best achievable subset sum closest to half the total.
7. The minimum difference is `total - 2 * j`.

Why it works:
- If one subset has sum `j`, the other subset has sum `total - j`.
- Minimizing `|total - 2*j|` is equivalent to choosing `j` closest to `total/2`.
- The DP subset-sum structure efficiently finds reachable sums.

Example:
For array `[1, 6, 11, 5]`, total = 23, half = 11.
Possible subset sums near 11 are 11 and 10.
Using 11 gives subsets `{11}` and `{1, 6, 5}` with difference 1.

Use case:
- Works for positive integers.
- Good when `n` and sum are moderate.
- Ideal for classic minimum partition or balanced partition problems.
