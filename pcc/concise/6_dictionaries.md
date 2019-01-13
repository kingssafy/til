# DICTIONARIES

dict = {key:value, key:value, so on}

dict are series of sets of key and value

for key in dict: gives you keys!

for value in dict.values(): gives you values

for key, value in dict.items(): gives you both



you can access values in dictionary by key! dict[key] returns value

you can add key-value pairs if there's not

dict[newkey] = newvalue

you can start with an empty dictionary and add key-value pairs

### Removing Key-value pairs

you can use `del` statement

del dict[key] will remove a key-value pair

### good dictionary convention

```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', # <- Python doesn't care last comma. good practice.
}
```

## Loop dictionary's key in order

for key in sorted(dict.keys):

## What's Nesting?

store a set of dictionaries in a list or a list of items as a value in a dictionary. This is called `nesting`



