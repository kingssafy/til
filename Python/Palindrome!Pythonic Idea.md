```python
# I solved this problem like following
def ispalindrome(word):
    n = 1
    front = word[:int(len(word)/2)]
    end = word[int(len(word)/2):]
    for char in front:
        if char == end[-n]:
            n += 1
        else:
            return False
    return True

#Pythonic Answer !!! WOW! how simple . intuitive idea
def isPalindrome(word):
    return list(word) == list(reversed(word))

```

