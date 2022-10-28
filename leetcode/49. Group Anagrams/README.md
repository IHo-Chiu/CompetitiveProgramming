# 49. Group Anagrams

https://leetcode.com/problems/group-anagrams/

### Concept
```
hash map up with sorted string

```

``` cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> hashMap;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            hashMap[key].push_back(strs[i]);
        }
        
        for (auto it : hashMap)
            answer.push_back(it.second);
        
        return answer;
    }
};
```
