
## CPE_Problem_Generator

自動產生7題CPE試題，已考過的題目不會出現

|題目|題數|
|---|---|
1星必考題|1
1星題|2
2星題|2
3星題|1
4星題|1

## uva

My code on uva onlinejudge.

## note 

#### include all
``` cpp
#include<bits/stdc++.h>
using namespace std;
```

#### bubble sort
``` 
for i in [0,n-1]
    for j in [0,n-i-1]
        if A[j] > A[j+1]
            swap A[j], A[j+1]
```

#### vector
``` cpp
vector<int> v(size, value);

v.push_back(x);
x = v.pop_back();
v.size();

// search
vector<int>::iterator it = find(v.begin(), v.end(), x);
index = distance(v.begin(), it);

// concat
v.insert(v.end(), v2.begin(), v2.end());

// insert
v.insert(v.begin()+index, val);

// reverse
reverse(v.begin(), v.end());
```

#### unordered_map (hash map)
``` cpp
int main()
{
    // allocate
    unordered_map<int, int> mp;
    unordered_map<int, int>::iterator it;
    unordered_map<int, int>::const_iterator const_it;
    
    // find key
    const_it = mp.find(x);
    
    // if not found
    if (k == mp.end()) {
        // create one
        mp[x] = value;
    }
    else {
        // get key and value
        cout << const_it->first << const_it->second;
    }
    
    // traverse key
    for (it = mp.begin(); it != mp.end(); it++) {
        // get key and value
        cout << it->first << it->second;
    }

    // unordered_map copy
    unordered_map<int, int> mp_copy = mp;

    // unordered_map erase key
    mp.erase(key);
}
```

#### sort 
``` cpp
vector<int> v;

// increasing
sort(v.begin(), v.end());

// decreasing
sort(v.begin(), v.end(), greater<int>());

// sort using lambda
sort(v.begin(), v.end(), [](const int& a, const int& b){
    return a > b;
});

// sort with some keys
vector<vector<int>> v;
sort(v.begin(), v.end(), [key](const vector<int>& a, const vector<int>& b){
    return a[key] > b[key];
});
```

#### string

``` cpp
string s = to_string(num)
string s = s.substr(start_idx, len);
int start_index = s.find(sub_str);
```

#### priority queue (heap)

``` cpp
priority_queue<int> pq;
priority_queue<int> pq(v.begin(), v.end());
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

#### queue

``` cpp
queue<int> q;

q.push(x);
q.pop();
q.empty();
q.size();
q.front();
q.back();
```