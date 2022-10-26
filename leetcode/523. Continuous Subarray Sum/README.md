# 523. Continuous Subarray Sum

https://leetcode.com/problems/continuous-subarray-sum/

### Concept
```
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

(2+4) = (23+2+4) - 23
=> (2+4)%6 = (((23%6)+2)%6+4)%6 - (23%6) = 0
              mod_of_sum[0:i]      mod_of_sum[0:j] for j in [0:i-2]
=> if there are (mod_of_sum[0:i] - mod_of_sum[0:j] == 0) for j in [0:i-2]
    return true
```

s
``` cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int sum = 0;
        hashMap[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]) % k;
            if (hashMap.find(sum) == hashMap.end())
                hashMap[sum] = i;
            else if (i - hashMap[sum] > 1)
                return true;
        }
        
        return false;
    }
};
```

