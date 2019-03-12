---
title: python crash course 1-3: introducing lists
date: 2018-12-29
methods:list[], list.append(), list.insert(), list.pop(), list.remove(), list.reverse(), list.sort(), list.sort(reverse=True)
statements: del list[],
functions: sorted(),sorted(list, reverse=True), len()
---





# INTRODUCING LISTS

Lists allow you to store sets of information in one place, whether you have just a few items or millions of items.

## What Is A List?

A list is a collection of items in a particular order. It's good idea to make the name of your list plural, such as `letters`, `digits`, or `names`. In Python, square brackets([]) indicate a list, and individual elements in the list are separated by commas. 

```python
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles)
```

```
['trek', 'cannondale', 'redline', 'specialized']
```



### Accessing Elements In a List

Lists are ordered collections, so you can access any element in a list by telling Python the position, or `index`, of the item desired.

```python
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[0])
```

```
trek
```

can be used like this

```python
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[0].title) #returns Trek
```

### Index Positions Start at 0, Not 1

Python considers the first item in a list to be at position 0, not position 1.

**If you're reciving unexpected results, determine whether you are making a simple off-by-one error.**

- Python has a special syntax for accessing the last element in a list. By asking for the item at index `-1`, Python always returns the last item in the list

- ```python
  bicycles = ['trek', 'cannondale', 'redline', 'specialized']
  print(bicycles[-1])
  ```

The index` -2` returns the second item from the end of the list, and so on.

### Using Individual Values from a List

```python
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
message = "My first bicycle was a " + bicycles[0].title() + "."

print(message)
```

```
My first bicycle was a Trek.
```



## Changing, Adding, and Removing Elements

Most lists you create will be dynamic, meaning you'll build a list and then add and remove elements from it as your program runs its course.

### Modifying Elements in a List

The syntax for modifying an element is similar to the syntax for accessing an element in a list. 

How would we change the value of this first item?

```python
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles) # ['honda', 'yamaha', 'suzuki']

motorcycles[0] = 'ducati'
print(motorcycles) # ['ducati', 'yamaha', 'suzuki']
```

You can change the value of any item in a list. not just first item.



### Adding Elements to a List

Python provides several ways to add new data to existing lists.

- Appending Elements to the End of a List

  When you append an item to a list, the new element is added to the end of the list.

  ```python
  motorcycles = ['honda', 'yamaha', 'suzuki']
  print(motorcycles) # ['honda', 'yamaha', 'suzuki']
  
  motorcycles.append('ducati')
  print(motorcycles) # ['honda', 'yamaha', 'suzuki', 'ducati']
  ```

  the `append()` method adds `'ducati'`to the end of the list without affecting any of other elements in the list.

  and the `append()`method makes it easy to build lists dynamically.

  ```python
  motorcycles = []
  motorcycles.append('honda')
  motorcycles.append('yamaha')
  motorcycles.append('suzuki')
  
  print(motorcycles)
  #['honda', 'yamaha', 'suzuki']
  ```

  building lists this way is very common, because you often won't know the data your user want to store in a program until after the program is running.

- Inserting Elements into a List

  You can add a new element at any position in your list by using the `insert()` method

  ```python
  motorcycles = ['honda', 'yamaha', 'suzuki']
  
  motorcycles.insert(0, 'ducati')
  print(motorcycles)
  #['ducati', 'honda', 'yamaha', 'suzuki']
  ```

  The `insert()` method opens a space at position 0 and store the value `'Ducati'` at that location. This operation shifts every other value in the list one position to the right.

### Removing Elements from a List

you'll want to remove an item or a set of items from a list.

- Removing an Item Using the del Statement

  If you know the position of the item you want to remove from a list, you can use `del` statement.

  ```python
  motorcycles = ['honda', 'yamaha', 'suzuki']
  print(motorcycles)
  
  del motorcycles[0]
  print(motorcycles)
  ```

  you can no longer acces the value that was removed from the list after the `del` statement is used

- Removing an Item using the `pop()` method.

  Sometimes you'll want to use the value of an item after you remove it from a list. For example, you might want to get the x and y position of an alien that was just shot down, so you can draw an explosion at that position. In a web application, you might want to remove a user from a list of active members and then add that user to a list of inactive members.

  ```python
  motorcycles = ['honda', 'yamaha', 'suzuki']
  print(motorcycles) #['honda', 'yamaha', 'suzuki']
  
  popped_motorcycle = motorcycles.pop() #returns 'suzuki'
  print(motorcycles) # ['honda', 'yamaha']
  print(popped_motorcycle) # suzuki
  ```

- Popping Items from any Position in a List

  You can actually use `pop()`to remove an item in a list at any position by including the index of the item you want to remove in parentheses.

  ```python
  motorcycles = ['honda', 'yamaha', 'suzuki']
  
  first_owned = motorcycles.pop(0)
  print('The first motorcycle i owned was a ' + first_owned.title() + '.')
  #The first motorcycle i owned was a Honda.
  ```

  **use `del` statement: when you want to delet ena item from a list and not use that item in anyway**

  **use `pop()` method: when you wanna use an item as you remove it**

- Removing an Item By Value

  if you only know the value of the item you want to remove, you can use the `remove()` method.

  ```python
  motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
  print(motorcycles)#['honda', 'yamaha', 'suzuki', 'ducati']
  
  too_expensive = 'ducati'
  motorcycles.remove(too_expensive)
  print(motorcycles)#['honda', 'yamaha', 'suzuki']
  print("\nA " + too_expensive.title() + " is too expensive for me.")
  #
  #A Ducati is too expensive for me
  ```

**The  `remove()` method deletes only the first occurence of the value you specify.** If there's a possibility the value appears more than once in the list, you'll need to use a loop to determine if all occurences of the value have been removed. You'll learn how to do this in Chapter 7.

**tiy3.4~3.7**


## Organizing a List

Python provides a number of different ways to organize your lists.

### Sorting a List *Permanently* with the `sort()` method

python's `sort()` method makes it relatively easy to sort a list. **let's assume that all values in the list are lowercase.**

```python
cars = ['bmw', 'audi','toyota', 'subaru']
cars.sort()
print(cars)
```

```python
['audi', 'bmw', 'subaru', 'toyota'] #and we can't never revert to the original order
```

you can also sort this list in reverse alphabetical order by passing the argument `reverse=True` to the `sort()` method.

```python
cars = ['bmw', 'audi','toyota', 'subaru']
cars.sort(reverse=True)
print(cars)
# ['toyota', 'subaru', 'bmw', 'audi'] #again the order of the list is permanently changed
```



### Sorting a List Temporarily with the `sorted()` Function

The sorted() function lets you display your list in a particular order but doesn't affect the actual order of the list.

```python
cars = ['bmw', 'audi','toyota', 'subaru']

print("Here is the original list:")
print(cars) # ['bmw', 'audi', 'toyota', 'subaru']

print("\nHere is the sorted list:")
print(sorted(cars)) # ['audi', 'bmw', 'subaru', 'toyota']

print("\nHere is the original list again:")
print(cars) # ['bmw', 'audi', 'toyota', 'subaru']
```

```python
# `reverse=True` option can be accepted
cars = ['bmw', 'audi','toyota', 'subaru']

print(sorted(cars,reverse=True)) # ['toyota', 'subaru', 'bmw', 'audi']
```

**Sorting a list alphabetically is a bit more complicated when all the values are not in lower case. **



### Printing a List in Reverse Order

To reverse the original order of a list, you can use the `reverse()` method.

```python
cars = ['bmw', 'audi','toyota', 'subaru']
print(cars) # ['bmw', 'audi','toyota', 'subaru']

cars.reverse()
print(cars) # ['subaru', 'toyota', 'audi', 'bmw']
```

Notice that reverse() doesn't sort backward alphabetically, it simply reverses the order of the list.



### Finding the Length of a list

You can quickly find the length of a list by using the `len()` function.

```python
>>> cars = ['bmw', 'audi','toyota', 'subaru']
>>> len(cars)
4
```

**Python counts the items in a list starting with one, so you shouldn't run into any off-by-one errors when determining length of a list**



TIY3.8~3.10



## Avoding Index Errors When Working with Lists

when you ask for item that doesn't exitst it will occur index Errors

**If an index error occurs and you can't figure out how to resolve it, try printing your list or just printing the length of your list. Your list might look much different than you thought it did, especially if it has been managed dynamically by your program. Seeing the actual list, or the exact number of items in your list, can help you sort out such logical errors.