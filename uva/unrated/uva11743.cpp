# include <stdio.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc getchar_unlocked
#define pc putchar_unlocked

inline void valid() { pc('V'); pc('a'); pc('l'); pc('i'); pc('d'); pc('\n'); }
inline void invalid() { pc('I'); pc('n'); pc('v'); pc('a'); pc('l'); pc('i'); pc('d'); pc('\n'); }

int main()
{
    while (gc() != '\n')  // clear first line
        ;

    register char ch;
    register unsigned char sum;
    do {
        sum = 0;
        for (int i = 0; i < 4; ++i) // four groups
        {
            ch = (gc() - '0') << 1; // 1st number
            sum += ch;
            if (ch > 9) sum -= 9;

            sum += gc() - '0';      // 2nd number

            ch = (gc() - '0') << 1; // 3rd number
            sum += ch;
            if (ch > 9) sum -= 9;

            sum += gc() - '0';      // 4th number

            ch = gc();              // ' ' or '\n' or EOF
        }

        if (sum % 10) invalid();
        else valid();

    } while (ch != EOF);

    return 0;
}