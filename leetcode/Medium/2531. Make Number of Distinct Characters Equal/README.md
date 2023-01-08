
## source code

O(26*26)

``` cpp
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> mp1, mp2;
        unordered_map<char, int>::iterator it1, it2;
        for (int i = 0; i < word1.length(); i++)
        {
            mp1[word1[i]]++;
        }
        for (int i = 0; i < word2.length(); i++)
        {
            mp2[word2[i]]++;
        }
        for (it1 = mp1.begin(); it1 != mp1.end(); it1++)
        {
            for (it2 = mp2.begin(); it2 != mp2.end(); it2++)
            {
                unordered_map<char, int> mp1_copy = mp1, mp2_copy = mp2;
                mp1_copy[it2->first]++;
                mp2_copy[it1->first]++;
                mp1_copy[it1->first]--;
                mp2_copy[it2->first]--;
                if (mp1_copy[it1->first] == 0)
                    mp1_copy.erase(it1->first);
                if (mp2_copy[it2->first] == 0)
                    mp2_copy.erase(it2->first);
                if (mp1_copy.size() == mp2_copy.size())
                    return true;
            }
        }

        return false;
    }
};
```

## note
``` cpp
// unordered_map copy
unordered_map<int, int> mp_copy = mp;

// unordered_map erase key
mp.erase(key);
```