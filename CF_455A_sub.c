#include <stdio.h>
long long n, a[1<<18];

int main(e) {
    for (; ~scanf("%d",&e); n=1<<17)
        n ? a[e] += e:0;
    for (e=1; e++<n;)
        (a[e] += a[e-2]) < a[e-1] && (a[e]=a[e-1]);
    printf("%lld",a[n]);
}

