```python
arr = [-7,-3,-2,5,8]
n = len(arr)

for i in range(1 << n):
        print([x for x, y in zip(reversed(arr), bin(i)[2:][::-1]) if int(y)])
```

