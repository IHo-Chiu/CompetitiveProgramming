#include <stdio.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
	return *p++;
}

unsigned long int scanInt()
{
    register char ch;
    register unsigned long int x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

void printUInt(unsigned long int n) {
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}

#define MAX_HEAP_SIZE 100000

long int maxHeap[MAX_HEAP_SIZE];
long int minHeap[MAX_HEAP_SIZE];
long int medianValue, value, temp;
int minHeapSize, maxHeapSize;

int main()
{
    maxHeapSize = 0;
    minHeapSize = 0;
    medianValue = scanInt();
    printUInt(medianValue), pc('\n');
    while (value = scanInt())
    {
        if (value >= medianValue)
        {
            // push value to min heap
            minHeap[++minHeapSize] = value;
            for (int i = minHeapSize; i > 1; i >>= 1)
                if (minHeap[i] < minHeap[i>>1])
                    SWAP(minHeap[i], minHeap[i>>1], temp);
                else break;
        }
        else
        {
            // push value to max heap
            maxHeap[++maxHeapSize] = value;
            for (int i = maxHeapSize; i > 1; i >>= 1)
                if (maxHeap[i] > maxHeap[i>>1])
                    SWAP(maxHeap[i], maxHeap[i>>1], temp);
                else break;
        }

        if (minHeapSize == maxHeapSize + 2)
        {
            // push medianValue to max heap
            maxHeap[++maxHeapSize] = medianValue;
            for (int i = maxHeapSize; i > 1; i >>= 1)
                if (maxHeap[i] > maxHeap[i>>1])
                    SWAP(maxHeap[i], maxHeap[i>>1], temp);
                else break;

            // pop min heap to medianValue
            medianValue = minHeap[1];
            minHeap[1] = minHeap[minHeapSize--];
            for (int i = 2; i <= minHeapSize; )
            {
                if (minHeap[i] > minHeap[i+1])
                    i++;
                if (minHeap[i] < minHeap[i>>1])
                {
                    SWAP(minHeap[i], minHeap[i>>1], temp);
                    i <<= 1;
                }
                else break;
            }

            printUInt(medianValue), pc('\n');
        }
        else if (maxHeapSize == minHeapSize + 2)
        {
            // push medianValue to min heap
            minHeap[++minHeapSize] = medianValue;
            for (int i = minHeapSize; i > 1; i >>= 1)
                if (minHeap[i] < minHeap[i>>1])
                    SWAP(minHeap[i], minHeap[i>>1], temp);
                else break;

            // pop max heap to medianValue
            medianValue = maxHeap[1];
            maxHeap[1] = maxHeap[maxHeapSize--];
            for (int i = 2; i <= maxHeapSize; )
            {
                if (maxHeap[i] < maxHeap[i+1])
                    i++;
                if (maxHeap[i] > maxHeap[i>>1])
                {
                    SWAP(maxHeap[i], maxHeap[i>>1], temp);
                    i <<= 1;
                }
                else break;
            }

            printUInt(medianValue), pc('\n');
        }
        else if (maxHeapSize == minHeapSize + 1)
            printUInt((medianValue + maxHeap[1])>>1), pc('\n');
        else if (minHeapSize == maxHeapSize + 1)
            printUInt((medianValue + minHeap[1])>>1), pc('\n');
        else 
            printUInt(medianValue), pc('\n');
    }

    return 0;
}