# 835. Image Overlap

https://leetcode.com/problems/image-overlap/

### Concept
```
run correlation
```

s
``` cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int answer = 0;
        int overlap = 0;
        for (int i = -(n-1); i <= (n-1); i++)
            for (int j = -(n-1); j <= (n-1); j++)
            {
                overlap = 0;
                for (int k = 0; k < n; k++)
                    for (int l = 0; l < n; l++)
                    {
                        if (k+i < 0 || k+i >= n || l+j < 0 || l+j >= n)
                            continue;
                        if (img1[k+i][l+j] && img2[k][l])
                            overlap++;
                    }
                
                answer = max(answer, overlap);
            }
        
        return answer;
    }
};
```
