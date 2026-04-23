DRY RUN
=======

Input:
4
1 6 11 5

Step 1: Compute total sum
- total = 1 + 6 + 11 + 5 = 23
- half = total / 2 = 11

Step 2: Initialize DP array of size 12
- dp = [true, false, false, false, false, false, false, false, false, false, false, false]

Step 3: Process first value = 1
- Update dp from 11 down to 1:
  dp[1] = dp[1] || dp[0] = true
- dp becomes: [true, true, false, false, false, false, false, false, false, false, false, false]

Step 4: Process second value = 6
- Update dp from 11 down to 6:
  dp[6] = dp[6] || dp[0] = true
  dp[7] = dp[7] || dp[1] = true
- dp becomes: [true, true, false, false, false, false, true, true, false, false, false, false]

Step 5: Process third value = 11
- Update dp from 11 down to 11:
  dp[11] = dp[11] || dp[0] = true
- dp becomes: [true, true, false, false, false, false, true, true, false, false, false, true]

Step 6: Process fourth value = 5
- Update dp from 11 down to 5:
  dp[11] = dp[11] || dp[6] = true
  dp[10] = dp[10] || dp[5] = false
  dp[9] = dp[9] || dp[4] = false
  dp[8] = dp[8] || dp[3] = false
  dp[7] = dp[7] || dp[2] = true
  dp[6] = dp[6] || dp[1] = true
  dp[5] = dp[5] || dp[0] = true
- dp becomes: [true, true, false, false, false, true, true, true, false, false, false, true]

Step 7: Find largest reachable `j` <= 11
- Check j = 11: dp[11] is true
- best = 11

Step 8: Compute minimum difference
- result = total - 2 * best = 23 - 22 = 1

Output:
1
