---
title: python crash course 1-7: USER INPUT AND WHILE LOOPS
date: 2018-12-30
methods: list.pop()
statements: break, continue,
functions: input(), input(prompt),int()
errors: 
keywords: str += str, %,
Operators: +=, %, modulor,
---

```python
prompt = "If you tell us who you are, we can personalize the message you see."
prompt += "\nWhat is your first name?" # you can use += too add more str
```

```python
a += 1 #is just short hand for a = a + 1
```





# USER INPUT AND WHILE LOOPS

In this chapter you'll learn how to accept user input. and you'll use Python's while loop to keep programs running as long as certain conditions remain true.



## How the `input()` Function Works

The `input()`function pauses your program and waits for the user to enter some text.

```python
message = input("Tell me something, and I will repeat it back to you: ")
# input() function takes one argument: the prompt, or instructions.
print(message)
# hi
```



### Writing Clear Prompts

Each time you use the `input()` function, you should induce a clear, easy-to-follow prompt.

```python
prompt = "If you tell us who you are, we can personalize the message you see."
prompt += "\nWhat is your first name? " # you can use += too add more str

name = input(prompt)
print("\nHello, " + name.title() + "!")
```

```bash
#prints
If you tell us who you are, we can personalize the message you see.
What is your first name? eric #space after the question mark for clarity

Hello, Eric!
```



### Using int() to Accept Numerical Input

`input()`function gets everything as `string type`

you can use `int()`function to convert string representation of a number to a numerical representation. 

```python
height = input("How tall are you, in inches? ")
height = int(height)

if height >= 36:   # if you omit the line hieght = int(height) this line will
    print("\nYou're tall enough to ride!") # occur type error.
else:
    print("\nYou'll be able to ride when you're a little older.")
```

when you use numerical input to do calculations and comparisons, be sure to convert the input value to a numerical representation first.



### The Modulo Operator

A useful tool for working with numerical information is the `modulo operator (%)`, which divides one number by another number and returns the ramainder.

The modulo operator doesn't tell you how many times one number fits into another.

When one number is divisible by another number, the remainder is 0, so the modulo operator always returns 0. you can use this fact to determine if a number is even or odd

```python
#even_or_odd.py
number = input("Enter a number, and I'll tell you if it's even or odd: ")
number = int(number)

if number % 2 == 0:
    print("\nThe number " + str(number) + " is even.")
else:
    print("\nThenumber " + str(number) + " is odd.")
```

```bash
Enter a number, and I'll tell you if it's even or odd: 42

The number 42 is even.
```



### Accepting input in Python 2.7

in Python 2.7 `raw_input()` instead of `input()`. `input()`in Python 2.7 interprets the user's input as Python code and attempts to run the input.



TIY.7-1~7-3



## Introducing while Loops

The `for` loop take s a collection of items and executes a block of code once for each item in the collection. In contrast, the `while`loop runs as long as, or `while`, a condition is `True`.

### The `while` Loop in Action

```python
current_number = 1
while current_number <= 5: #when current number reaches 6 the loop stops running
    print(current_number)
    current_number += 1
```

```bash
1
2
3
4
5
```



### Letting the User Choose When to Quit

This `while` loop runs as long as the value of `message` is not `'quit'`.

```python
prompt = "\nTell me something, and I will repeat it back to you:"
prompt += "\nEnter 'quit' to end the program. "

message = "" # we define message as empty string. so Python has something
while message != 'quit': # to check the first time it reaches the `while` line.
    message = input(prompt)
    
    if message != 'quit': # If user input 'quit' doesn't print anything.
    	print(message)
```



###Using a Flag

You can define one variable, c that determines whether or not the entire program is active.

This variable, called a `flag`, acts as a signal to the program.

```python
prompt = "\nTell me something, and I will repeat it back to you:"
prompt += "\nEnter 'quit' to end the program. "

active = True # active is your flag

while active:  # Check active is True or False
    message = input(prompt)
    
    if message == 'quit':
        active = False # set active to False if the user enters 'quit'
    else:
        print(message)
```

flag is useful in complicated frogram.  and it would be easy to add more test for events that sohould cause `active` to become `False`.



### Using break to Exit a Loop

To exit a `while` loop immediately without running any remaining code in the loop, regardless of the results of any conditional test, use the `break` statement.

A loop that starts with `while True` will run forever unless it reaches a `break` statement.

```python
prompt = "\nPlease enter the name of a city you have visited"
prompt += "\n(Enter 'quit' when you are finished.) "

while True:
    city = input(prompt)

    if city == 'quit':
        break # break statement cause Python to exit the loop
    else:
        print("i'd love to go to " + city.title() + "!")
```

**You can use the `break` statement in any of Python's loops. For example, you could use `break`to quit a for loop that's working through a list or a dictionary**



### Using continue in a Loop

you can use `continue` statement to return to the beginning of the loop base on the result of a conditional test.

- Loop that counts from 1 to 10 but prints only the `odd numbers` in that range.

```python
#counting.py
current_number = 0
while current_number < 10:
    current_number += 1
    if current_number % 2 == 0: #if statement catches if current number is even
        continue				# and return to beginning of while loop
    
    print(current_number)
```



### Avoiding Infinite Loops

Every while loop needs a way to stop running

```python
x = 1
while x <= 5:
    print(x)
    x += 1
#this counting loop should count from 1 to 5
#but following one runs forever

x = 1
while x <= 5:
    print(x)
```

Make sure at least one part of the program can make the loop's condition `False` or cause it to reach a `break` statement.

TIY.7-4~7-7

##Using a `while` Loop with Lists and Dictionaries.

a `for` loop effective for looping through a list. But you shouldn't modify a list inside a `for`loop. because Python will have trouble.

- To modify a list as you work through it, use a `while` loop.

Usins `while` loops with lists and dictionaries aloows you to collect, store, and organize lots of input to examine and report on later.



### Moving Items from One List to Another

you can use `while` loop here.

```python
#confirmed_users.py
# Start with user that need to be verified.
# and an empty list to hold confirmed users.
unconfirmed_users = ['alice', 'brian', 'candace']
confirmed_users = []

# Verify each user until there are no more unconfirmed users.
# Move each verified user into the list of confirmed users. list.pop() is used.
while unconfirmed_users: # if list is not empty, returns True
    current_user = unconfirmed_users.pop()

    print("Verifying user: " + current_user.title())
    confirmed_users.append(current_user)
# Display all confirmed users.
print("\nThe following users have been confirmed:")
for confirmed_user in confirmed_users:
    print(confirmed_user.title())
```



### Removing All Instances of Specific Values from a List

`list.remove()`method removes only once in the list.

what if you want to remove all instance of a value from a list.

```python
#pets.py
pets = ['dog', 'cat', 'dog', 'goldfish', 'cat', 'rabbit', 'cat']
print(pets)

while 'cat' in pets:
    pets.remove('cat')
    
print(pets)
```

```bash
['dog', 'cat', 'dog', 'goldfish', 'cat', 'rabbit', 'cat']
['dog', 'dog', 'goldfish', 'rabbit']
```



### Filling a Dictionary with User Input

We'll store the data we gather in a dictionary, because we want to connect each response with a particular user

```python
#mountain_poll.py
responses = {}

# Set a flag to indicate that polling is active.
polling_active = True

while polling_active:
    # Prompt for the person's name and reponse.
    name = input("\nWhat is your name? ")
    response = input("Which mountain would you like to climb someday? ")

    # Store the response in the dictionary:
    responses[name] = response

    # Find out if anyone else is going to take the poll.
    repeat = input("Would you like to let another person respond? (yes/no) ")
    if repeat == 'no':
        polling_active = False

# Polling is complete. Show the results.
print("\n--- Poll Results ---")
for name, response in responses.items():
    print(name.title() + " would like to climb " + response + ".")
```

```bash
What is your name? hi
Which mountain would you like to climb someday? gjgj
Would you like to let another person respond? (yes/no)

What is your name? bye
Which mountain would you like to climb someday? gjopeo
Would you like to let another person respond? (yes/no) no

--- Poll Results ---
Hi would like to climb gjgj.
Bye would like to climb gjopeo.
```



TIY.7-8~7-10

* 7-9 is interesting