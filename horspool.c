#include <stdio.h>
#include <string.h>

#define max 500
int table[max];

void shiftTable(char pattern[])
{
    int i;
    int size = strlen(pattern);

    for(i=0; i<max; i++)
        table[i] = size;

    for(int i=0; i<size-1; i++)
        table[pattern[i]] = size - 1 - i;
}

int horspool(char src[] , char pattern[])
{
    int i,j,k;
    int size_src = strlen(src); // n
    int size_pattern = strlen(pattern); // m

    printf("Size of source string is %d\n",size_src);
    printf("Size of pattern string is %d\n" , size_pattern);

    i = size_pattern - 1;
    while(i < size_src) {
        k = 0;
        while((k < size_pattern) && (pattern[size_pattern - 1 - k] == src[i-k])) {
            k++;
        }
        if(k == size_pattern)
            return i - size_pattern + 1;
        else
            i += table[src[i]];
    }
    return -1;
}

int main()
{
    int size = 1000;
    char src[size] , pattern[size];

    printf("Enter main string\n");
    fgets(src , size , stdin);


    // 'fgets' is preferrd over 'gets' because 'fgets' specify the buffer size of string
    
    printf("Enter pattern to match\n");
    fgets(pattern , size , stdin);

    // 'fgets' also take newline '\n' in its buffer, so it can be made 'null' as done below
    pattern[strlen(pattern)-1] = '\0';
    src[strlen(src)-1] = '\0';

    shiftTable(pattern);
    int ans = horspool(src , pattern);

    if(ans == -1) {
        printf("Pattern doesn't exist in source string.\n");
    }
    else {
        printf("Pattern exist in source string at %d.\n", ans);
    }
}
