---
title: python crash course 1-8: FUNCTIONS
date: 
methods: 
statements: return, from, import, as
functions: 
errors: 
keywords: def,
Operators: parameter, argument, return value, *,from module import *,
---





# FUNCTIONS

In this chapter you'll learn to write `functions`, which are named blocks of code that are designed to do one specific job. and you'll learn to store functions in spearate files called `modules` to help organize your main program files.


## Defining a Function.

```python
def greet_user():
    """Display a simple greeting.""" # this line called doc string. 
    					             # describes what the function does
    print("Hello!")                  # actual code in the body of this function 

greet_user()
```

`def`to inform Python that you're defining a function.The parentheses hold information. In this case, the name of function `greet_user()`, and it needs no information to do its job, so its parentheses are empty.(but parentheses are required).and definition ends in colon. and indented lines that follow `def greet_user():` make up the body of the function.

to `call` a function you wirte the name of function, followed by any necessary information in parentheses



### Passing Information to a Function.

Modified slightly, the function `greet_user()` can not only tell the user `Hello!` but also greet them by name.

```python
def greet_user(username): #parameter: username
    """Display a simple greeting."""
    print("Hello!, " + username.title() + "!")

greet_user('jesse')  #argument: 'jesse'
```

you enter `username` in the parentheses of the function's definition at `def greet_user()`. By adding `username`here you allow the function to accept any value of `username`you specify. 

Entering `greet_user('jesse')` calls `greet_user()` and gives the function the information it needs to execute the `print` statement. 



### Argument and Parameters

In the preceding `greet_user()` function, we defined `greet_user()` to require a value for the variable `username`. once we called the function and gave it the information, it printed the right greeting.

​	The variable `username`in the definition of `greet_user()` is an example of a `paremeter`, a piece of information the function needs to do its job. The value `'jesse'` in `greet_user('jesse')` is an example of an `argument`. An `argument` is a piece of information that is passed from a function call to a function.



TIY.8-1~8-2

## Passing Arguments

You can pass arguments to your functions in a number of ways. You can use `positional arguments`, which need to be in the same order the parameters were written; `keyword arguments`, wehere each argument consist of a variable name and a value; and lists and dictionaries of values.

We'll look at Each of these in turn



### Positional Arguments

When you call a function, Python must match each argument in the function call with a parameter in the function definition. The simplest way to do this is based on the order of the arguments provided. Values matched up this way is called `positional arguments`.

```python
#pets.py
def describe_pet(animal_type, pet_name):
    """Display information about a pet."""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet('hamster', 'harry') 
```

When we call `describe_pet()` we need to prove an animal type and a name, in that order.



### Multiple Function calls

```python
#pets.py
def describe_pet(animal_type, pet_name):
    """Display information about a pet."""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet('hamster', 'harry') 
describe_pet('dog', 'willie' )
```

Calling a function multiple times is a very efficient way to work. You also can use as many positional arguments as you need in your function.



### Order Matters in Positional Arguments

You can get unexpected result if you mix up the order of the arguments in a function call when using positional arguments:

```python
#pets.py
def describe_pet(animal_type, pet_name):
    """Display information about a pet."""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet('harry', 'hamster')
```

```bash
I have a harry.
My harry's name is Hamster.
```

check to make sure the order of the arguments in your function call matches the order of the parameters in the function's definition.


### Keyword Arguments

A `keyword argument` is a name-value pair that you pass to a function. You directly associate the name and the value within the argument. and they clarify the role of each value in the function call.

```python
#pets.py
def describe_pet(animal_type, pet_name):
    """Display information about a pet."""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

# The following two function calls are equivalent:
describe_pet(animal_type='hamster',pet_name='harry')
describe_pet(pet_name='harry',animal_type='hamster')
```

The function `describe_pet()` hasn't changed. But when we call the function, we explicitly tell Python which parameter each argument should be matched with. 

The order of keyword arguments doesn't matter because Python knows where each value should go.

**be sure to use the exact names of the parameters in the function's definition.**

### Default values

When writing a function, you can define a `default value` for each parameter.

If an argument for a parameter is not provided in the function call, it uses the parameter's default value.

```python
#pets.py
def describe_pet(pet_name, animal_type='dog'): # i define default value for
    """Display information about a pet."""     # animal_type as 'dog'
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet(pet_name='willie')
describe_pet('willie') # this is the same as upper one
```

```bash

I have a dog.
My dog's name is Willie.
```

Note that the order of the parameters in the function definition had to be changed. Because the default value makes it unnecessary to specify a type of animal as an argument, the only argument left in the function call is the pet's name. python still interprets this as a positional argument, so if the function is called with just a pet's name, that argument will match up with the first parameter listed in the function's definition.

Now anyone can calling `describe_pet()` for a dog can omit that information.

***When you use default values, any parameter with a default value needs to be listed after all the parameters that don't have default values. This allows Python to continue interpreting positional arguments correctly.***



### Equivalent Function Calls.

All of the following calls would work same in this function.

```python
def describe_pet(pet_name, animal_type='dog'):
    
# A dog named Willie.
describe_pet('willie')
describe_pet(pet_name='willie')

# A Hamster named Harry.
describe_pet('harry', 'hamster')
describe_pet(pet_name='harry', animal_type='hamster')
describe_pet(animal_type='hamster', pet_name='harry')
```

**It doesn't really matter which calling style you use. As long as your function calls produce the output you want, just use the style you find easiest to understand.



### Avoiding Argument Errors.

Unmatched arguments occur when you provide fewer or more arguments than a function needs to do its work.

```python
#pets.py
def describe_pet(animal_type, pet_name):
    """Display information about a pet."""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet()
```

```bash
Traceback (most recent call last):
  File "pcc.py", line 7, in <module> # the location of the problem
    describe_pet() # 2 the offending function call is written out for us to see
TypeError: describe_pet() missing 2 required positional arguments: 'animal_type' and 'pet_name' # 3 tell us the call is missing two arguments and names of those
```



TIY.8.3~8.5



## Return Values

A function can process some data and then return a value or set of values. The value the function returns is called `return value`

### Returning a Simple Value



```python
#formatted_name.py
def get_formatted_name(first_name, last_name):
    """Return a full name, neatly formatted"""
    full_name = first_name + " " + last_name
    return full_name.title() # The value full_name.title() return to the calling line

musician = get_formatted_name('jimi', 'hendrix')
print(musician)
```



### Returning an Dictionary

this is how you return an dictionary

```python
def make_album(name, title):
    return {'artist_name': name, 'album_title': title}

a = make_album('avril lavigne', 'smile')
print(a)
print(type(a))
# you also can use this
def make_album(name, title):
    person = {'artist_name': name, 'album_title': title}
    return person
```



### Making an Argument Optional

we make last_name into optional argument.

```python
#middlename.py
def get_formatted_name(first_name, last_name, middle_name=''): 
    												# make last argument into option
    """Return a full name, neatly formatted."""
    if middle_name:
        full_name = first_name + ' ' + middle_name + ' ' + last_name
    else:
        full_name = first_name + ' ' + last_name
    return full_name.title()

musician = get_formatted_name('jimi', 'hendrix')
print(musician)

musician = get_formatted_name('john', 'hooker', 'lee')
print(musician)
```

we have to make sure the middle name(optional argument) is the last argument passed so Python will match up the positional arguments correctly.

### Returning a Dictionary

A function can return any kind of value you need it to, including more complicated data structures like lists and dictionaries.

```python
#person.py
def build_person(first_name, last_name, age=''): #age is optional argument
    """Return a dictionary of information about a person."""
    person = {'first': first_name, 'last': last_name}
    if age:
        person['age'] = age
    return person

musician = build_person('jimi', 'hendrix')
print(musician)
```



### Using a Function with a `while` loop

You can use functions with all the Python structure you've learned so far in this book.D

following examples are using `while` loop.

```python
#greeter.py
def get_formatted_name(first_name, last_name):
    """Return a full name, neatly formatted"""
    full_name = first_name + " " + last_name
    return full_name.title()

# This is an infinite loop!
while True:
    print("\nPlease tell me your name!")
    print("(enter 'q' at any time to quit)")
    f_name = input("First name: ")
    if f_name == 'q':
        break
    l_name = input("Last name: ")
    if l_name == 'q':
        break

    formatted_name = get_formatted_name(f_name, l_name)
    print("\nHello, " + formatted_name + "!")
```



TIY.8-6~8-8



## Passing a List

You'll often find it useful to pass a list to a function.

When you pass a list to a function, the function gets direct acess to the contents of the list.

```python
#greet_users.py
def greet_users(names): #We def function especially so can deal with list.
    """Print a simple greeting to each user in the list."""
    for name in names:
        msg = "hello, " + name.title() + "!"
        print(msg)

usernames = ['hannah', 'ty', 'margot']
greet_users(usernames)
```



### Modifying a List in a Function

When you pass a list to a function, the function can modify the list. `Any changes made to the list inside the function's body are parmenent`

followings are without using functions.

```python
# Start with some designs that need to be printed
unprinted_designs = ['iphone case', 'robot pendant', 'dodecahedron']
completed_models = []

# Simulate printing each design, until non are left.
# Move each design to completed_models after printing
while unprinted_designs:
    current_design = unprinted_designs.pop()
    # Simulate creating a 3D print from the design.
    print("Printing model: " + current_design)
    completed_models.append(current_design)

#Display all completed models.
print('\nTHE FOLLOWING MODELS HAVE BEEN PRINTED: ')
for completed_model in completed_models:
    print(completed_model)
```

convert into functions and function calls.

```python
def print_models(unprinted_designs, completed_models):
    # Simulate printing each design, until non are left.
    # Move each design to completed_models after printing
    while unprinted_designs:
        current_design = unprinted_designs.pop()
        # Simulate creating a 3D print from the design.
        print("Printing model: " + current_design)
        completed_models.append(current_design)
def show_completed_models(completed_models):
    #Display all completed models.
    print('\nTHE FOLLOWING MODELS HAVE BEEN PRINTED: ')
    for completed_model in completed_models:
        print(completed_model)

# Start with some designs that need to be printed
unprinted_designs = ['iphone case', 'robot pendant', 'dodecahedron']
completed_models = []

print_models(unprinted_designs, completed_models)
print(unprinted_designs)
```

```python
Printing model: dodecahedron
Printing model: robot pendant
Printing model: iphone case

THE FOLLOWING MODELS HAVE BEEN PRINTED:
dodecahedron
robot pendant
iphone case
```

This example also demonstrates the idea that every function should have one specific job.





### Preventing a Function from Modifying a List

Sometimes you'll want to prevent a function from modifying a list.

you can address this issue by passing the `function a copy of the list` `when you call a function`, not the original. Any changes the function makes to the list will affect only the copy, leaving the original list intact.

for example:

```python
function_name[:]
print_models(unprinted_designs[:], completed_models)
```



TIY.8-9~8-11



## Passing an Arbitrary Number of Arguments

Python allows a function to collect an arbitrary number of arguments from the calling statement.

```python
# pizza.py
def make_pizza(*toppings):
        """Print the list of toppings that have been requested."""
        print(toppings)

make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')
```

```python
('pepperoni',)
('mushrooms', 'green peppers', 'extra cheese')
```

The `asterisk` in the parameter name `*toppings` tells Python to make an empty tuple called `toppings` and pack whatever values it receives into this tuple.

**Note that Python packs the arguments in to a tuple, even if the function receives only one value**

Now we can replace the `print` statement with a loop that runs through the list of toppings and describes the pizza being ordered.

```python
# pizza.py
def make_pizza(*toppings):
        """Summarize the pizza we are about to make."""
        print("\nMaking a pizza with the following toppings:")
        for topping in toppings:
                print(f"\t- {topping}")

make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')
```



### Mixing Positional and arbitrary arguments.

If you want a function to accept several different kinds of arguments, the parameter that accepts an **arbitrary number of arguments must be placed last in the function definition**. Python matches positional and keyword arguments first and then collects any remaining arguments in the final parameter.

```python
# pizza.py
def make_pizza(size, *toppings):
        """Summarize the pizza we are about to make."""
        message = "\nMaking a " + str(size)
        message += "-inch pizza with the following toppings:"
        print(message)
        for topping in toppings:
                print(f"\t- {topping}")

make_pizza(16, 'pepperoni')
make_pizza(20, 'mushrooms', 'green peppers', 'extra cheese')
```

```bash

Making a 16-inch pizza with the following toppings:
        - pepperoni

Making a 20-inch pizza with the following toppings:
        - mushrooms
        - green peppers
        - extra cheese
```



### Using Arbitrary Keyword Arguments

you can write functions that accept as many key-value pairs as the calling statement provides. following example always takes in a first and last name, but it accepts an arbitrary number of keyword arguments as well.

```python
def build_profile(first, last, **user_info):
        """build a dictionary containing every thing we know  about a user."""
        profile ={}
        profile['first_name'] = first
        profile['last_name'] = last
        for key, value in user_info.items():
                profile[key] = value
        return profile

user_profile = build_profile('albert', 'einstein', location='princeton', field='physics') #note that we don't put quote in name such as location, field
print(user_profile)
```

The definition of `build_profile()` expects a first and last name, and then it allows the user to pass in as many `name-value` pairs as they want. The `double asterisk` before the parameter `**user_info` cause Python to create an empty dictionary called user_info and pack whatever name-value pairs it receives into this dictionary.

```bash
{'first_name': 'albert', 'last_name': 'einstein',
'location': 'princeton', 'field': 'physics'}
```



TIY.8-12~8-14

## Storing Your Functions in Modules

Tou can store your functions in a separate file called a `module` and them `import` that module into your main program. An `import` statement tells Python to make the code in a mmodule available in the currently running program.



### Importing an Entire Module

a `module` is a file ending in `.py` that contains the code you want to import in to your program.

To make module, we'll remove everything from the file `pizza.py` except the function `make_pizza()`:

```python
# pizza.py
def make_pizza(*toppings):
        """Summarize the pizza we are about to make."""
        print("\nMaking a pizza with the following toppings:")
        for topping in toppings:
                print(f"\t- {topping}")
```

now we'll make a separate file called `making_pizzas.py` in the same directory as `pizza.py`

```python
#making_pizzas.py
import pizza

pizza.make_pizza(16, 'pepperoni')
pizza.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
```

```python
Making a pizza with the following toppings:
        - 16
        - pepperoni

Making a pizza with the following toppings:
        - 12
        - mushrooms
        - green peppers
        - extra cheese
```

to call function from an imported module, enter the name of the module you imported, `pizza`, followed by the name of the function, `make_pizza()`, separated by a dot.



if you use this kind of `import` statement to import an entire module named `module_name.py`, each function in the module is available through the following syntax:

```bash
module_name.function_name()
```



### Importing Specific Functions

You can also import a specific function from a module. Here's the general syntax for this approach:

```bash
from module_name import function_name
```

or you can import as many as you want from a module by separating each function's name with a comma:

```bash
from module_name import function_0, function_1, function_2
```

The `making_pizza.py` example would look like this if we want to import just the function we're going to use.

```python
from pizza import make_pizza

make_pizza(16, 'pepperoni') # before : pizza.make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
```

With this syntax, you don't need to use the dot notation when you call a function. Becuase we've explicitly imported the function `make_pizza()` in the `import` statement, we can call it by name when we use the function.





### Using as to Give a Function an Alias

If the name of a function you're importing might conflict with an existing in your program or if the function name is long, you can use a short, unique `alias` - an alternate name similar to a nickname for the function. The `as` keyword renames a function using the alias you provide.

```python
from pizza import make_pizza as mp

mp(16, 'pepperoni')
mp(12, 'mushrooms', 'green peppers', 'extra cheese')
```

The general syntax for providing an alias is:

```bash
from module_name import function_name as fn
```



### Using as to Give a Module an Alias

You can also provide an alias for module name. 

Calling `p.make_pizza()` is more concise than calling `pizza.make_pizza()`:

```python
import pizza as p

p.make_pizza(16, 'pepperoni')
p.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
```

The general syntax for this approach is:

```bash
import module_name as mn
```



### Importing All Functions in a Module(Do Not Use)

You can tell Python import every function in a module by using the asterisk(*) operator:

```python
from pizza import *

make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
```

The asterisk in the `import` statement tells Python to copy every function from the module `pizza` into this program file. Because every function is imported, you can call each function by name without using the dot notation. However, it's best not to use this approach when you're working with larger modules that you didn't write. if module has a function name that matches an existing name in your project, you can get some unexpected results. Python may see several functions or variables with the same name, and instead of importing all fucntions separately, it will overwrite the functions.

The best approach is to import the function or functions you want, or import the entire module and use the dot notation. This leads to clear code that's easy to read and understand. 

I include this section so you'll recognize `import` statements like the following when you see them in other people's code:

```bash
from module_name import *
```



## Styling Functions

- Function, Module names should have descriptive names. these names should use lowercase letters and underscores.
- Every function should have a comment that explains concisely what the function does. This comment should appear immediately after the function definition and use docstring format.
- in a well-documented function, other programmers can use the function by reading only the description in the docstring
- If you specify a default value for a parameter, no spaces should be used on either side of the equal sign:

```python
def function_name(parameter_0, parameter_1='default value')
```

- the same convention should be used for keyword arguments in function calls:

```python
function_name(value_0, parameter_1='value')
```

- limit lines of code to 79characters

- if a set of parameters cause a function's definition to be longer than 79characters

  then press enter and tab twice

```python
def function_name(
		parameter_0, parameter_1, parameter_2,
		parameter_3, parameter_4, parameter_5):
    function body
```

- if your program or module has more than one function, you can separate each by two balnk lines to makeit easier to see
- All `import` statement should be written at the beginning of a file.

TIY.8-15~8-17