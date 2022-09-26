/*
以題目例子為例
D = 4
 答案 I   (以二進位表示)
1000 000
1100 001
1010 010
1110 011
1001 100
1101 101
1011 110
1111 111

三位數內剛好對稱
因此 bit_reverse(I-1) + 2^(D-1) 就是答案
*/

# include <stdio.h>

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
	return *p++;
}

void printUInt(unsigned int n) {
    if (n != 0)
    {
        printUInt(n/10);
        putchar_unlocked((n%10) + '0');
    }
}

inline int bits_19_reverse(register int x)
{
    register unsigned char temp = (x & 0x70000) >> 16; // last 3 bits

    // calculate 16 bit number reverse
    x = (x & 0b1111111100000000) >> 8 | (x & 0b0000000011111111) << 8;
    x = (x & 0b1111000011110000) >> 4 | (x & 0b0000111100001111) << 4;
    x = (x & 0b1100110011001100) >> 2 | (x & 0b0011001100110011) << 2;
    x = (x & 0b1010101010101010) >> 1 | (x & 0b0101010101010101) << 1;

    // last 3 bits
    x <<= 3;
    x |= (temp & 0b100) >> 2 | (temp & 0b010) | (temp & 0b001) << 2;

    return x;
}

int main()
{

    while (readchar() != '\n')
        ;

    char ch = '\0';
    do
    {
        int D = 0;
        int I = 0;
        while ((ch = readchar()) >= '0')
            D = D * 10 + ch - '0';

        if (ch == EOF)
            break;

        while ((ch = readchar()) >= '0')
            I = I * 10 + ch - '0';

        printUInt(bits_19_reverse((I-1)<<(20-D)) | (1<<(D-1)));
        putchar_unlocked('\n');

    } while(1);

    return 0;
}