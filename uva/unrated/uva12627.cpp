# include <stdio.h>

int bitCount(long long int a)
{
    int count = 0;
    while (a > 0)
    {
        if (a & 0x1)
            count++;

        a >>= 1;
    }

    return count;
}

long long int combination(int n, int k)
{
    if (k > n) return 0;
    else {
        long long int ans = 1;
        for (int i = 1; i <= k; i++) {
            ans *= n;
            ans /= i;
            n--;
        }
        return ans;
    }
}

long long int bitCombinationCount(int bit, long long int max)
{
    // calculate combinations of different numbers with spicified bitBount between 0 to max
    // ex : 
    //     max = 0b010101, bit = 2
    //     step1 : check 0b010000, there are 4 bit space combinate 2 bits
    //             => C(4,2) = 6   // 0011 0101 0110 1001 1010 1100
    //     step2 : check 0b010100, there are 2 bit space combinate 1 bit
    //             => C(2,1) = 2   // 10001 10010
    //     step3 : 0b010100 is also a case
    //             => 1
    //     step4 : get result = 6+2+1 = 9
    //     reverse step:
    //     step1 : know there are 3 bits -> k = 2-3 = -1 (because bit = 2)
    //     step2 : 3 >= 2, so there is a speciall case -> ans ++;
    //     step3 :   101 -> shift = 2, k = 1 -> C(2,1) = 2
    //     step4 :     1 -> shift = 4, k = 2 -> C(4,2) = 6

    if (max < 0) return 0;
    if (bit == 0) return 1;

    int k = bit - bitCount(max);
    int shift = 0;
    long long int ans = 0;

    if (k <= 0) ans++;
    if (max & 0x1) k++;

    while (max > 0)
    {
        max >>= 1;
        shift++;
        if (max & 0x1)
        {
            k++;
            if (k > 0) 
                ans += combination(shift, k);
        }
    }

    return ans;
}

int main()
{
    int testNum;
    scanf("%d", &testNum);
    for (int q = 1; q <= testNum; q++)
    {
        int K;
        long long int A, B;
        scanf("%d %lld %lld", &K, &A, &B);
        long long int ans = 0;

        // hint : the number of red balloon in line x is 2^(K-bitCount(x-1))
        for (int i = 0; i <= K; i++)
        {
            ans += (((long long int)1) << (K - i)) * (bitCombinationCount(i, B-1) - bitCombinationCount(i, A-2));
        }

        printf("Case %d: %lld\n", q, ans);
    }
    return 0;
}
