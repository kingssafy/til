# USER INPUT AND WHILE LOOPS

use Python's while loop to keep programs running as long as certain conditions remain true.

## How the `input()` Function Works

The `input()` function get user input as string.

you can use `int()`function to get numerical input

`modulo operator (%)` returns the remainder.

use `raw_input()` 



# while loops

`for` loop execute once for each item in the collection

`while` loop run as long as , or `while`, a condition is `True`

```python
current_number = 1
while current_number <= 5:
    print(current_nubmer)
    current_number += 1
```

input kill code in while loop

```python
while message != 'quit': # to check the first time it reaches the `while` line.
    message = input(prompt)
    
    if message != 'quit': # If user input 'quit' doesn't print anything.
    	print(message)
```

using a flag

```python
active = True # active is your flag

while active:  # Check active is True or False
    message = input(prompt)
    
    if message == 'quit':
        active = False # set active to False if the user enters 'quit'
    else:
        print(message)
```

Using break to exit a loop

to exit a loop immediately without running any remaning code in the loop use!! `break`



Using continue in a Loop

you can use `continue` statement to return to the beginning of the loop base on the result of a conditional test.



### LIST

#### Moving items from one list to another

use while

```python
while lista: #while lista returns True if an element is in the list
    listb.append(lista.pop())  
```



Remove all instances of specific values from a list

```python
while 'cat' in pets:
    pets.remove('cat')
```



## filling a dictionary with user input

```python
responses = {}

while True:
    name = input()
    response = input()
    
    responses[name] = response
```

