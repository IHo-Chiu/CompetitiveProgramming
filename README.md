
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
```

#### bubble sort
``` 
for i in [0,n-1]
    for j in [0,n-i-1]
        if A[j] > A[j+1]
            swap A[j], A[j+1]
```

#### unordered_map
``` cpp
#include<iostream>
#include<unordered_map>

int main()
{
    // allocate
    std::unordered_map<int, int> mp;
    std::unordered_map<int, int>::iterator it;
    std::unordered_map<int, int>::const_iterator const_it;
    
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
}
```

#### sort 
``` cpp
vector<int> v;

// increasing
std::sort(v.begin(), v.end());

// decreasing
std::sort(v.begin(), v.end(), std::greater<int>());

// custom rule
bool mycompare(int a, int b) {
    return a > b;
}
std::sort(v.begin(), v.end(), mycompare);
```