# 88. Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/

### Concept
```
merge from back to front
```

``` cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        while (m && n)
        {
            if (nums1[m-1] > nums2[n-1])
            {
                nums1[i] = nums1[m-1];
                i--;
                m--;
            }
            else
            {
                nums1[i] = nums2[n-1];
                i--;
                n--;
            }
        }
        
        while (n)
        {
            nums1[i] = nums2[n-1];
            i--;
            n--;
        }
        
    }
};
```
