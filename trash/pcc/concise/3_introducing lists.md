# INTRODUCING LISTS

Lists allow you to store sets of information in one place.

## What is A list

- List : collection of items **in a particular order**.

- name your list **plural**

- In Python, square brackets([]) indicate a list, and individual elements in the list are separated by commas

  ```python
  bicycles = ['trek', 'cannondale', 'redline', 'specialized']
  ```

### Accessing Elements in a List

- access element in a list by `index`

  ```python
  bicycles[0].title #returns 'trek' off-by-zero(Index Positions Start at 0, Not 1)
  ```



## Changing adding removing elements

- lists are **dynamic**: means you'll build a list and then add and remove elements from it 

### Modifying Element in a list

```python
bicycles[0] = 'ducati'
print(bicycles) # ['ducati', 'cannondale', 'redline', 'specialized']
```



## Methods

- `list.append('value')` : add  'value' to the end of the list

- `del` statement : you can remove from a list by position(index)

  ```python
  del bicycles[index]
  ```

- `list.pop(index=-1)` : remove an item by index and return value
- `list.remove('value')` : deletes only the first occurrence of the value you specify.

- `list.sort()` : returns `None`. sorting a list in alphabetical order **(permanent)**
- `list.sort(reverse=True)` :sorting an list by reverse alphabetical order

- fucntion`sorted(iterable)` : returns list in particular order (original lists are not modified)
- `list.reverse()`: reverse the original order of a list.
- function `len(list)`: returns length of a list **off-by-one** 





## Error

index errors: when you ask for item that doesn't exist