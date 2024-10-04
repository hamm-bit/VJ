# L1 Week 4

## 0-1 KS
The recurrence we obtain:
$f(i, r) = \mr{max}(f(i + 1, r - s_i) + v_i, f(i + 1, r))

## Roof Tiling
```python
    # encoding white as 0, black as 1
    
    # loop:

    Ks[m] = Ks[m-1] + (tile[i] - old)
    old = tile[i - m]
    DP[m] = DP[m-1] * (1 + (Ks[m-1] < k))


    # solution
    for s in range(1 << m):
        dp[m % 2][s] = (popcount(s) >= k)
    for i in range(m + 1, n):
        fill(DP[i % 2], dp[i % 2] + 1 << M, 0)
        for s in range (1 << m):
            if (popcount(s) >= k):
                dp[i % 2][s] = dp[(i+1) % 2][s >> 1]
                             + dp[(i+1) % 2][(s) >> 1 | (1 << (m-1))] 
```

## TSP
```python
    def tsp():
        for msk in range(1 << n):
            for city in range(n):
                dp[msk][city] = inf
        dp[1][0] = 0

        int ans = inf;
        for msk in range(1, 1 << n):
            for cur in range(n):
                if (msk & (1 << cur)):
                    cdp = dp[msk][cur]
                    if (msk == 1 << cur - 1):
                        # sample answer
                        ans = min(ans, cdp)
                    for nxt in range(n):
                        if (!(msk % (1 << nxt))):
                            dp[msk | (1 << nxt)][nxt] = 
                                min(dp[msk | (1 << nxt)][nxt], cdp + adj[cur][nxt])
```
