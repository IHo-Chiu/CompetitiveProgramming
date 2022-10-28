# 1. Two Sum

https://leetcode.com/problems/two-sum/

### Concept
```
hash map up with pairing number and it's index

```

``` cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.find(nums[i]) == hashMap.end())
                hashMap[target-nums[i]] = i; 
            else
            {
                answer.push_back(hashMap[nums[i]]);
                answer.push_back(i);
                return answer;
            }
        }
        
        return answer;
    }
};
```
