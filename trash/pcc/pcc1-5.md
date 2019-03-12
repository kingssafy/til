---
title: python crash course 1-5: IF STATEMENTS
date: 2018-12-30
methods:
statements: and, or, if, ==, >, <, !=, >=, <=, in, not
functions: 
errors: 
keywords: in, and, or, not
---

- string.lower() doesn't change its original value

- Checking That a List Is Not Empty by `if list`  when list is empty it will return False

# IF STATEMENTS

Python's `if` statement allows you to examine the current state of a program and respond appropriately to that state.  you'll learn to write conditional tests, which allow you to check any condition of interest. 

## A Simple Example

The following short example shows how `if` tests let you respond to special situations correctly.

```python
cars = ['audi', 'bmw', 'subaru', 'toyota']

for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())
#Audi
#BMW
#Subaru
#Toyota
```

## Conditional Tests

at the heart of every if statement is an expression taht can be evaluated as `True` or `False` and is called `conditional test`.

### Checking for Equality

```python
>>> car = 'audi'
>>> car == 'audi'
True
>>> car == 'bmw'
False
```

single equal sign: set the value of car equal to 'audi'

double equal sign: Is the value of car euqal to 'bmw'?

### Ignoring Case When Checking for Equality

```python
>>> car = 'Audi'
>>> car == 'audi'
False #because Testing for equality is case sensitive
>>> car.lower() == 'audi' #this way ignore case
True
>>> car
'Audi'
```

### Checking for inequality

When you want to determine whether two values are not equal, you can combine an exclamation point and an equal sign (!=). The exclamation point represents `not`, as it does in many programming languages.

```python
requested_topping = 'mushrooms'

if requested_topping != 'anchovies':
    print("hold the anchovies!") #hold the anchovies!
```

The `if` line compares the value of `requested_topping` to the value `'anchovies'`. If these two values do not match, Python returns True and executes the code following the if statement.



### Numerical comparisons

```python
>>> age = 19
>>> age == 19
True
>>> age != 19
False
>>> age < 21
True
>>> age <= 21
True
>>> age > 21
False
>>> age >= 21
False
```



### Checking Multiple Conditions

You may want to check multiple conditions at the same time. The keywords `and` and `or` can help you in these situations.

- Using `and`to Check Multiple Conditions

  use the keyword `and` , if each test passes, the overall expression evalutes to `True`. If either test fails or if both tests fail, the expression evaluates to `False`

  ```python
  >>> age_0 = 22
  >>> age_1 = 18
  >>> age_0 >= 21 and age_1 >= 21
  False # first test passes but the last one fails
  >>> age_1 = 21
  >>> age_0 >= 21 and age_1 >= 21
  True # both tests pass
  # To improve readability you can use parentheses
  # (age_0 >= 21) and (age_1 >= 21)
  ```

- Using `or`to Check Multiple Conditions

  `or` expression fails only when both individual tests fail.

  ```python
  >>> age_0 = 22
  >>> age_1 = 18
  >>> age_0 >= 21 or age_1 >= 21
  True # first one passes, last one fails
  >>> age_0 = 18
  >>> age_0 >= 21 or age_1 >= 21
  False #both tests fail
  ```



### Checking Whether a Value is in a List

Sometimes it's important to check whether a list contains a certain value before taking an action.

To find out whether a particular value is already in a list, use the keyword `in`

```python
>>> requested_toppings = ['mushrooms', 'onions', 'pineapple']
>>> 'mushrooms' in requested_toppings
True
>>> 'pepperoni' in requested_toppings
False
```



### Checking Whether a Value is Not in a List

You can use the keyword `not` in this situation.

```python
banned_users = ['andrew', 'carolina', 'david']
user = 'marie'

if user not in banned_users:
    print(user.title() + ", you can post a response if you wish.")
# Marie, you can post a response if you wish.
```



### Boolean Expressions

a `boolean expression` is just another name for a conditional test. A boolean value is either `True` or `False`, just like the value of a conditional expression after it has been evaluated.

```python
game_active = True
can_edit = False
```

Boolean values prive an efficient way to tack the state of a program or a particular condition that is important in your program.



TIY5-1~5-2

## If Statements

When you understand conditional tests, you can start writing `if` statements.

### Simple `if` Statements

```python
if conditional_test:
    do somthing
```

you can put any conditional test in the first line and just about any action in the indented block following the test.

### `if-else` Statements

the `else` statement allows you to define an action or set of actions that are executed when the conditional test fails.(returns False)

```python
age = 17
if age >= 18: #returns False
    print("You are old enough to vote!")
    print("Have you registered to vote yet?")
else: #so following lines are executed
    print("Sorry, you are too young to vote")
    print("Please register to vote as soon as you turn 18!")
```

In a simple `if-else` chain like this, one of the two actions will always be executed.



### The `if-elif-else` Chain

Often, you'll need to test more than two possible situations, and to evaluate these you can use Python's `if-elif-else` syntax.

It runs each conditional test in order until one passes. When a test passes, the code following that test is executed and Python skips the rest of the tests.

```python
age = 12
if age < 4:
    print("Your admission cost is $0.")
elif age < 18: #test passes , execute following codes and skip the rest of the tests
    print("Your admission cost is $5.") 
else:
    print("Your admission cost is $10.")
# Your admission cost is $5.
```

concise

```python
age = 12
if age < 4:
    price = 0
elif age < 18: 
    price = 5
else:
    price = 10

print("Your admission cost is $" + str(price) + ".")
```

`if-elif-else` chain imsply determines the admission price.  revised code is easier to modify.

To change the text of the output message, you'd need to change only one `print` statement rather than three separate `print` statements.



### Using Multiple `elif` Blocks

You can use as many `elif` blocks in your code as you like.

```python
age = 12
if age < 4:
    price = 0
elif age < 18: 
    price = 5
elif age < 65:
    price = 10
else:
    price = 5

print("Your admission cost is $" + str(price) + ".")
```



### Omitting the else Block

Python does not require an else block at the end of an `if-elif` chain.

```python
age = 12
if age < 4:
    price = 0
elif age < 18: 
    price = 5
elif age < 65:
    price = 10
elif age >= 65:
    price = 5

print("Your admission cost is $" + str(price) + ".")
```

The `else` block is a catchall statement. It matches any condition that wasn't matched by a specific `if` or `elif` test, and that can sometimes include invalid or even malicious data. consider using a final `elif` block and omit the `else` block, if you can.



### Testing Multiple conditions

The `if-elif-else` chain is powerful, but it only appropriate to use when you just need one tset to pass. However, sometimes it's important to check all of the conditions of interest.

```python
requested_toppings = ['mushrooms', 'extra cheese']

if 'mushrooms' in requested_toppings:
    print("Adding mushrooms")
if 'peperoni' in requested_toppings:
    print("Adding peperoni")
if 'extra cheese' in requested_toppings:
    print("Adding extra cheese")

print("\nFinished making Your Pizza")
# Becuase every condition in this example is evaluated, both mushrooms and 
# extra cheese are added to the pizza.
# Adding mushrooms
# Adding extra cheese
#
# Finished making Your Pizza
```

- Summary: if you want only one block of code to run, use an `if-elif-else` chain. if more than one block of code needs to run, use a series of `if` statements.

TIY.5-3~5-6

## Using `if`Statements with Lists

You can do some interesting work when you combine lists and `if` statements.



### Checking for Speical Items.

```python
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping == 'green peppers': #key part of this codes
        print("Sorry, we are out of green peppers right now.")
    else:
        print("Adding " + requested_topping + ".")

print("\nFinished making your pizza!")

# Adding mushrooms.
# Sorry, we are out of green peppers right now.
# Adding extra cheese.
#
# Finished making your pizza!
```



### Checking That a List Is Not Empty

if list contains at least one item, will return True. if empty, return False. in `if` statmenet.

```python
requested_toppings = []

if requested_toppings: #because list is empty it returns False
    for requested_topping in requested_toppings:
        print("Adding " + requested_topping + ".")
    print("\nFinished making your pizza!")
else:
    print("Are you sure you want a plain pizza?")
    
# Are you sure you want a plain pizza?
```

### Using Multiple lists

```python
available_toppings = ['mushrooms', 'olives', 'green peppers', 'pepperoni', 
                      'pineapple', 'extra cheese']
requested_toppings = ['mushrooms', 'french fries', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping in available_toppings:
        print(f"Adding {requested_topping}.")
    else:
        print(f"Sorry, we don't have {requested_topping}.")

print("\nFinished making your pizza!")
# Adding mushrooms.
# Sorry, we don't have french fries.
# Adding extra cheese.
#
# Finished making your pizza!
```



TIY.5-8~5-11.

## Styling Your if Statements

```python
if age < 4:
#is better than
if age<4:
```

TIY.5-12~5-13