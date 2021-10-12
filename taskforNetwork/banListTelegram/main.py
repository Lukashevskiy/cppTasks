ans = 0
with open('blocked-networks.txt', 'r') as f:
        ans += sum([2 ** (32 - int(l.split('/')[1].split('\n')[0])) for l in f])
print(ans)
