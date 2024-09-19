sequence, stack, letter_count, ans = input(), [], [0] * 26, ''

# O(n)
for x in sequence:
    letter_count[ord(x) - 97] += 1
     
for x in sequence:
    stack.append(x)
    letter_count[ord(x) - 97] -= 1
    print(stack)
    
    while stack and sum(letter_count[:ord(stack[-1]) - 97]) == 0:
        ans += stack.pop()
print(ans)
