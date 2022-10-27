# 217. Contains Duplicate

https://leetcode.com/problems/contains-duplicate/

### Concept
```
hash map
```

s
``` cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> dic;
        for (int i = 0; i < nums.size(); i++)
        {
            if (dic.find(nums[i]) == dic.end())
                dic[nums[i]] = true;
            else return true;
        }
        
        return false;
    }
};
```
