---
title: python crash course 1-4: working with lists
date: 2018-12-29
methods:
statements: indentation, for, in
functions: min(),max(),sum(),
errors: IndentationError: expected an indented block,

---

# WORKING WITH LISTS

in this chapter you'll learn how to *loop* through an entire list using just a few lines of code regardless of how long the list it is.

## Lopping Through an Entire List

When you want to do the same action with every item in a list, you can use Python's `for`  loop.

```python
magicians = ['alice', 'david', 'carolina']

for magician in magicians:
    print(magician)
#alice
#david
#carolina
```

## A Closer Look at Looping

```python
magicians = ['alice', 'david', 'carolina']

for magician in magicians: #this line tells Python to retrieve the first value from the list magicians and store it in the variable magician
    print(magician) #print current value of magician and returns to the first line of the loop because the list contains more values. 
#repeats until reaches the last value.
```

```python
#tip
for cat in cats:
for dog in dogs:
for item in list_of_items:
#this naming conventions can help you follow the action being done on each item within a `for` loop
```



## Doing More Work Within a for Loop



```python
magicians = ['alice', 'david', 'carolina']

for magician in magicians:
    print(magician.title() + ", that was a great trick!") 
    print("I can't wait to see your next trick, " + magician.title() + ".\n")
#every indented line following the line `for magician in magicians:` is considered `inside the loop` and each indented line is executed once for each value in the list.
```

## Doing Something After a for Loop



```python
magicians = ['alice', 'david', 'carolina']

for magician in magicians:
    print(magician.title() + ", that was a great trick!") 
    print("I can't wait to see your next trick, " + magician.title() + ".\n")

print("Thank you, everyone. That was a great magic show!")
#Any lines of code after the `for` loop that are not indented are executed once with out repetition after the `for` loop.
```

### Avoiding Indentation Errors

Python uses indentation to determine when one line of code is connected to the line above it.

- Forgetting to indent

  ```python
  magicians = ['alice', 'david', 'carolina']
  for magician in magicians:
  print(magician)
  ```

  ```bash
    File "pcc.py", line 3
      print(magician)
          ^
  IndentationError: expected an indented block
  ```



- Forgetting to Indent Additional Lines

  ```python
  magicians = ['alice', 'daivd', 'carolina']
  for magician in magicians:
      print(magician.title() + ", that was a great trick")
  print("I can't wait to see your next trick,")
  ```

  This is `logical error` if you want repeat once for each item in a list, you need to simply indent a line or group of lines.

- Indenting Unnecessarily

  ```python
  message = "Hello Python world!"
  	print(message)
  ```

  ```bash
    File "pcc.py", line 2
      print(message)
      ^
  IndentationError: unexpected indent
  ```

  we don't need to indent the print statement, because it doesn't `belong` to the line above it; hence, Python reports error

  you can avoid unexpected indentation error by indenting only when you have a specific reason to do so.

- Indenting Unnecessarily After the Loop

  ```python
  magicians = ['alice', 'david', 'carolina']
  
  for magician in magicians:
      print(magician.title() + ", that was a great trick!") 
      print("I can't wait to see your next trick, " + magician.title() + ".\n")
  
  	print("Thank you, everyone. That was a great magic show!") #look at this line
  ```

  `logical error`

  because last line is indented , it's printed once for each person in the list. you need to unindent that line. 

- Forgetting the colon

  The colon at the end of a for statement tells Python to interpret the next line as the start of a loop

  ```python
  magicians = ['alice', 'david', 'carolina']
  for magician in magicians
  	print(magician)
  ```

  ```bash
    File "pcc.py", line 2
      for magician in magicians
                              ^
  SyntaxError: invalid syntax
  ```

  you'll get syntax error

  this is easy error to fix, it's not always an easy error to find

TIY4.1~4.2

## Making Numerical Lists

Lists are ideal for storing  sets of numbers, and Python provides a number of tools to help you work efficiently with lists of numbers.



### Using the `range()` Function

Python's `range()` function makes it easy to generate a series of numbers.

```python
for value in range(1,5):
    print(value)
```

```bash
1
2
3
4
```

this code should print the numbers from 1 to 5 but deosn't print the number 5.  The `range()`function causes Python to start counting at the first value you give it, and it stops when it reaches the second value you provide. Because it stops at that second value, the output never contains the end value.

### Using `range()` to make a List of Numbers

if you want to make list of numbers, you can convert the result of `range()` directly into a list using the `list()` function.

```python
numbers = list(range(1,6)) #you list() function to make list of numbers conviniently.
print(numbers) # [1, 2, 3, 4, 5]

even_numbers = list(range(2, 11, 2))
print(even_numbers) # [2, 4, 6, 8, 10]
#range function starts with the value 2 and then adds 2 to that value. it adds 2 repeatedly until it reaches or passes the end value, 11
```

 

- using `range()` in `for`loops

```python
squares = []
for value in range(1, 11):
    square = value ** 2
    squares.append(square)
    
print(squares)

for value in range(1, 11):
    squares.append(value ** 2) #this works exactly the same 
```

**first you wirte code that you understand cleary, which does what you want it to do. then look for more efficient approaches as you review your code.**

### Simple Statistics with a List of Numbers

A few Python functions are specific to lists of numbers.

```python
digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
min(digits) #return 0
max(digits) # return 9
sum(digits) # return 45
```

### List Comprehensions

list comprehensions are not always presented to beginners, but i have included them here because you'll most likely see them as soon as you start looking at other people's code.

```python
squares = [value ** 2 for value in range(1,11)]
print(squares) # [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```

To use this syntax, begin with descriptive name for the list, such as `squares`

Next, open a square brackets and define the expression for the values you want to store in the new list.

Then, wirte a `for` loop to generate the numbers you want to feed into the expression.

it takes practice to write your own list comprehensions.

TIY4-3~4-9

## Working with Part of a List

You can work with a specific group of items in a list, which Python calls a `slice`

### Slicing a List

To make a slice, you specify the index of the first and last elements you want to work with. as with the `range()` function, Python stops one item before the second index you specify.

```python
players = ['charlie', 'martina', 'michael', 'florence', 'eli']

print(players[0:3]) # ['charlie', 'martina', 'michael']

print(players[1:4]) # ['martina', 'michael', 'florence'] slice second, third, fourth

print(players[:4]) # ['charlie', 'martina', 'michael', 'florence'] if you omit the first index, Python automatically starts your slice at the beginning of the list

print(players[2:]) # ['michael', 'florence', 'eli'] Python returns all items from index 2 through the end of the list

print(players[-2:]) # ['florence', 'eli'] returns last two players of the list.
```

### Looping Through a Slice

You can use a slice in a `for` loop if you want to loop through a subset of the elements in a list.

```python
players = ['charlie', 'martina', 'michael', 'florence', 'eli']

print("Here are the first three players on my team:")
for player in players[:3]:
    print(player.title())
#Here are the first three players on my team:
#Charlie
#Martina
#Michael
```

### Copying a List

To copy a list, you can make a slice that includes the entire original list by omitting the first index and the second index `[:]`. This tells Python to make a slice that starts at the first item and ends with the last item, producing a copy of the entire list.

```python
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]
# This doesn't work:
#friend_foods = my_foods

my_foods.append('cannoli') #to prove that we actually have two separate lists
friend_foods.append('ice cream')

print("My favorite foods are:")
print(my_foods)

print("\nMy friend's favorite foods are:")
print(friend_foods)

#My favorite foods are:
#['pizza', 'falafel', 'carrot cake', 'cannoli']
#
#My friend's favorite foods are:
#['pizza', 'falafel', 'carrot cake', 'ice cream']
```

**if Instead of storing a copy of `my_foods` in `friend_foods`, we set `friend_foods = my_food`. This syntax actually tells Python to connect the new variable `friend_foods` to the list that is already contained in `my_foods`, so now both variables point to the same list. as a result, when we add `'cannoli'`to my_foods, it will also appear in `friend_foods`. Likewise `'ice cream'` will appear in both lists, even though it appears to be added only to `friend_foods`.**

- Don't worry about the details in this example for now. Basically, if you're trying to work with a copy of a list and you see unexpected behavior, make sure you are copying the list using a slice, as we in the first example.

TIY4-10~4-12

## Tuples

Sometimes you'll want to create a list of items that cannot change. Tuples allow you to do just that.**Python refers to value that cannot change as `immutable`, and immutable list is called a `tuple`**

### Defining a Tuple, Looping Through All values in a Tuple

A tuple looks just like a list except you use parentheses instead of square brackets.

```python
dimensions = (200, 50)
print(dimensions[0]) # 200
print(dimensions[1]) # 50

dimensions[0] = 250 #this will cause 'TypeError' because we're trying to alter a tuple, which can't be done to that type of object, Python tells us we can't assign a new value to an item in a tuple
for dimension in dimensions: # you can Lopping Through all values in a tuple just like list
    print(dimension) 
```

### Writing over a Tuple

Altough you can't modify a tuple, you can assign a new value to a variable that holds a tuple.

```python
dimensions = (200, 50)
print("original dimensions:")
for dimension in dimensions:
    print(dimension)
    
dimensions = (400, 100)
print("\nModified dimensions:")
for dimension in dimensions:
    print(dimension)

#original dimensions:
#200
#50
#
#Modified dimensions:
#400
#100
```

Python doesn't raise any errors this time, because overwriting a variable is valid.

**use tuple when you want to store a set of values that should not be changed through-out the life of a program**



TIY4-13

## Styling Your code

if you're hoping to become a professional programmer at some point, you should begin following these guidelines as soon as possible to develop good habits.

### pep8

Python Enhancement Proposal(PEP): there's a style guide

Indentation: four spaces per indentation level.

### Line Length

Many Python programmers recommend that each line should be less than 80 characters

and comments less than 72 characters

### Blank Lines

To group parts of your program visually, use blank lines.

TIY4-14~4-15

```python
#TIY4-14
#look through the original PEP8 style guide at https://python.org/dev/peps/pep-0008/
```

```python
#TIY4-15
#use four spaces for each indentation level.
#use less than 80characters on each line.
#don't use blank lines excessively.
```

