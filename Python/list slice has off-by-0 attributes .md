```python
slice_list = list(range(1, 11))
#slice_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

print(slice_list[:4])
#will gives you [1, 2, 3, 4] not [1, 2, 3, 4, 5]
```

when arrive last number it`ll b terminated

index refers very before of an element





```python
a = '123'
b = '563434347'
list(zip(a,b))

from itertools import zip_longest
list(zip_longest(a, b, fillvalue=0))
```

