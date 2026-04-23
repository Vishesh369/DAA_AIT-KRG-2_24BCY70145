TIME AND SPACE COMPLEXITY ANALYSIS
===================================

Time Complexity:
- The algorithm loops over each of the `n` array elements.
- For each element, it iterates from `half` down to the value.
- Worst-case time complexity is O(n * sum), where `sum` is the total sum of array elements.
- Since `half = sum / 2`, this is O(n * sum).

Space Complexity:
- The DP array requires O(sum) space, specifically O(total / 2 + 1).
- The input array itself uses O(n) space.
- Overall space complexity is O(sum + n), dominated by the DP array.

Practical notes:
- This solution is efficient when `sum` is not too large.
- For arrays with sum up to a few thousand or tens of thousands, it runs quickly.
- If values are very large, alternative heuristics or approximations may be needed.
