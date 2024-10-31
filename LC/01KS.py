wts = [i for i in range(1000)]
vals = [i for i in range(500)]
items = [(i, j) for i in wts for j in vals]

dp = [0] * 10
for (w, v) in items:
    for j in reversed(range(w, 10)):
        oldval = dp[j]
        prevval = dp[j - w]
        dp[j] = max(oldval, prevval + v)

print(dp[-1])

