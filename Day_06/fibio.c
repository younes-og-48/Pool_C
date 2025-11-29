#include <stdio.h>

long long fib_tail(int n, long long a, long long b)
{
    if (n == 0)
        return a;
    return fib_tail(n - 1, b, a + b);
}

int main(void)
{
    int n = 10;
    long long result = fib_tail(n, 0, 1);
    printf("F(%d) = %lld\n", n, result);
    return 0;
}