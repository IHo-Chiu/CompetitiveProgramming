# 53. Maximum Subarray

https://leetcode.com/problems/maximum-subarray/

### Concept
```
greedy algorithm

```

s
``` cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = 0;
        int largest = -10000;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = max(0, sum+nums[i]);
            ans = max(ans, sum);
            largest = max(largest, nums[i]);
        }
        
        if (largest < 0) return largest;
        else return ans;
    }
};
```
