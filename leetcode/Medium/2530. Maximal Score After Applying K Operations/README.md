
## Version 1

using hash map and heap

``` cpp
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        std::unordered_map<long long, long long> mp;
        std::vector<long long> v;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = 1;
                v.push_back(nums[i]);
            }
            else
            {
                mp[nums[i]] ++;
            }
        }
        
        std::make_heap(v.begin(), v.end());
        
        long long score = 0;
        
        
        while (k > 0)
        {
            long long num = v.front();
            std::pop_heap(v.begin(), v.end());
            v.pop_back();
            
            if (mp[num] >= k)
            {
                score += num * k;
                k -= k;
            }
            else if (num == 1)
            {
                score += k;
                k -= k;
            }
            else 
            {
                score += num * mp[num];
                k -= mp[num];
                if (k == 0)
                    break;
                
                long long decreased_num = num/3 + (num%3 > 0);
                
                if (mp.find(decreased_num) != mp.end())
                {
                    mp[decreased_num] += mp[num];
                }
                else
                {
                    mp[decreased_num] = mp[num];
                    v.push_back(decreased_num);
                    std::push_heap(v.begin(), v.end());
                }
            }
            
        }
        
        
        
        return score;
    }
};
```


#### note

heap

https://www.geeksforgeeks.org/heap-using-stl-c/

``` cpp
// convert vector to heap
make_heap(v1.begin(), v1.end());

// heap top
v1.front();

// push heap
v1.push_back(x);
push_heap(v1.begin(), v1.end());

// pop heap
pop_heap(v1.begin(), v1.end());
v1.pop_back();

// contert heap to sorted vector
sort_heap(v1.begin(), v1.end());
```

## Version2

try priority queue

``` cpp
priority_queue <int> pq;
priority_queue <int> pq(v.begin(), v.end());
priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int, vector<int>, cmp> pq;

struct cmp {
    bool operator()(node a, node b) {
        return a.x < b.x;
    }
};

pq.push(x);
x = pq.top();
pq.pop();
pq.empty();
pq.size();
```

reduced lots of code

``` cpp
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
        int num, decreased_num;
        while (k--)
        {
            num = pq.top();
            score += num;
            pq.pop();
            decreased_num = num/3 + (num%3 > 0);
            pq.push(decreased_num);
        }
        
        return score;
    }
};
```