---
title: python crash course 1-6: DICTIONARIES
date: 2018-12-30
methods: dictionary.keys(), dictionary.items(), dictionary.values()
statements: del,
functions: sorted(),
errors: 
keywords: if a in dictionary.keys():, if a in dictionary.values():,
---

- Dictionaries are wrapped in braces{}

- `for key, value in dict.items():`

- sorted(dictionary.keys())

- set() function to make non repetitive list.

- how could i access the upper level of dictionary in a list 

  ```python
  sparky = {
      'kind': 'dog',
      'owner': 'oh',
  }
  draggy = {
      'kind': 'dragon',
      'owner': 'harry',
  }
  thunder = {
      'kind': 'lightning',
      'owner': 'thor',
  }
  
  pets = [sparky, draggy, thunder]
  
  for pet in pets:
      print(pet) # i want print a pets name in `for` loop
  ```


# DICTIONARIES

in this chapter you'll learn how to use Python's dictionaries, which allow you to connect pieces of related information.



## A Simple Dictionary

This simple dictionary stores information about a particular alien:

```python
alien_0 = {'color': 'green', 'points': 5}

print(alien_0['color']) # green
print(alien_0['points']) # 5
```



## Working with Dictionaries

A `dictionary` in Python is collection of `key-value`pairs. each `key`is connected to a `value`.  `key`'s value can be any object that you can create in Python.(list, str, int, float, or another dictionary)

```python
alien_0 = {'color': 'green', 'points': 5} # 'color' and 'points' are key
									      #to value 'green' and 5

print(alien_0['color']) # when you provide a key, Python returns 
						# the value associated with that key
print(alien_0['points']) 
```



### Accessing Values in a Dictionary

```python
alien_0 = {'color': 'green', 'points': 5}

new_points = alien_0['points'] # dictionary['key'] returns 'value' assosicated
							   # to that key
print(f"You just earned {new_points} points!")
```

To get the value associated with a key, give the name of the dictionary and then place the key inside a set of square bracket.



###Adding New Key-Value Pairs

Dictionaries are dynamic structures, and you can add new key-value pairs to a dictionary at any time.

```python
alien_0 = {'color': 'green', 'points': 5}

alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)
# {'color': 'green', 'points': 5, 'x_position': 0, 'y_position': 25}
# in-the-book it prints like
# {'color': 'green', 'points': 5, 'y_position': 25, 'x_position': 0}
# because python 3.6.+ 's dictionary insertion ordered!
# https://stackoverflow.com/questions/39980323/are-dictionaries-ordered-in-python-3-6
```

I say "insertion ordered" and not "ordered" since, with the existence of OrderedDict, "ordered" suggests further behavior that the `dict` object *doesn't provide*. OrderedDicts are reversible, provide order sensitive methods and, mainly, provide an order-sensive equality tests (`==`, `!=`). `dict`s currently don't offer any of those behaviors/methods.

### Starting with an Empty dictionary

To sart filling an empty dictionary, define a dictionary with an empty set of braces and then each key-value pair on its own line

```python
alien_0 = {}

alien_0['color'] = 'green' add 'key' : 'value' to alien_0
alien_0['points'] = 5

print(alien_0)
```

Typically, you'll use empty dictionaries when storing user-supplied data or you wirte the code that generates large number of key-value pairs automatically.



### Modifying Values in a Dictionary

To modify a value in a dictionary, give the name of the dictionary with the key in square brackets and then the new value you want associated with that key.

```python
alien_0 = {'color' : 'green'}
print(f"The alien is {alien_0['color']}.")

alien_0['color'] = 'yellow'
print(f"The alien is now {alien_0['color']}.")
```

more interesting example.

```python
alien_0 = {'x_position': 0, 'y_position': 25, 'speed': 'medium'}
print(f"Original x-position: {alien_0['x_position']}.")

# Move the alien to the right.
# Determine how far to move the alien based on its current speed.
if alien_0['speed'] == 'slow':
    x_increment = 1
elif alien_0['speed'] == 'medium':
    x_increment = 2
else:
    # This must be a fast alien
    x_increment = 3

# THe new position is the old position plus the increment.
alien_0['x_position'] = alien_0['x_position'] + x_increment

print(f"New x-position: {alien_0['x_position']}.")
# Original x-position: 0.
# New x-position: 2.
```



### Removing `Key-Value` Pairs.

you can use the `del` statement to completely remove a `key-value`pair. All `del` needs is the name of the dictionary and the key that you want to remove.

```python
alien_0 = {'color': 'green', 'points': 5}
print(alien_0)

del alien_0['points'] # tells Python to delete the key 'points' and its values
print(alien_0)
# {'color': 'green', 'points': 5}
# {'color': 'green'}
```

**be aware that the deleted key-value pair is removed permanently**



### A dictionary of Similar Objects

you can also use a dictionary to store one kind information about many objects.

```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', # <- Python doesn't care last comma.
}

print(favorite_languages)
print("Sarah's favorite language is " +      # here's how we break up 
     favorite_languages['sarah'].title() +   # a long print statement
     ".")
```

**It's good practice to include a comma after the last key-value pair as well, so you're ready to add a new key-value pair on the next line**



TIY.6-1~6-3

## Looping Through a Dictionary

You can loop through all of a dictionary's key-value pairs, through its keys, or through its values.



###Looping Through All Key-Value Pairs

you could you `for` loop and `dict.items()`method.

```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', # <- Python doesn't care last comma.
}

for name, language in favorite_languages.items(): # dict.items() method returns
    								#key,value of dict in insertion order
    print(name.title() + "'s favorite language is " +
    language.title())
# Jen's favorite language is Python
# Sarah's favorite language is C
# Edward's favorite language is Ruby
# Phil's favorite language is Python
    
print(favorite_languages.items())
# dict_items([('jen', 'python'), ('sarah', 'c'), ('edward', 'ruby'), ('phil', 'python')])
```



### Looping Through All the Keys in a dictionary

The `dict.keys()`method is useful when you don't need to work with all of the values in a dictionary.

```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', # <- Python doesn't care last comma.
}

for name in favorite_languages.keys():
    print(name.title())
# for name in favorite_languages: # this code works just like upper one 
#     print(name.title())         # but better use keys() method, it's easier to read.
```



```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', # <- Python doesn't care last comma.
}

friends = ['phil', 'sarah']
for name in favorite_languages.keys():
    print(name.title())

    if name in friends: 
        print(" Hi " + name.title() +
        ", I see your favorite language is " +
        favorite_languages[name].title() + "!") # use name to find associated value
```



you can also use the `keys()`method to find out if a particular person was polled.

```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', 
}

if 'erin' not in favorite_languages.keys(): #WOW
    print("Erin, please take our poll")
```

### Looping Through a dictionary's Key in Order

You can use the `sorted()` function to get a copy of the `keys` in order.

```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', 
}

for name in sorted(favorite_languages.keys()):
    print(name.title() + ", thank you for taking the poll")
```



### Looping Through All Values in a Dictionary

you can use the `values()` method to return a list of values with out any keys.

```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', 
}

print("The following languages have been mentioned:")
for language in set(favorite_languages.values()): # use set() function when 
    print(language.title())                       # you want to pull out unique values
```

- you can use set() function to make non repetitive list.
- a set is similar to a list except that each item in the set must be unique and has no order.

TIY.6-4~6-6

## Nesting

Sometimes you'll want to store a set of dictionaries in a list or a list of items as a value in a dictionary. This is called `nesting`.



### A List of Dictionaries

manage a fleet of dictionaries. one way is to make a list of dictionaries

```python
alien_0 = {'color': 'green', 'points': 5}
alien_1 = {'color': 'yellow', 'points': 10}
alien_2 = {'color': 'red', 'points': 15}

aliens = [alien_0, alien_1, alien_2]

for alien in aliens:
    print(alien)

# {'color': 'green', 'points': 5}
# {'color': 'yellow', 'points': 10}
# {'color': 'red', 'points': 15}
```



Here's how we deal with dictionaries which are in the list.

```python
aliens = []

for alien_number in range(30):
    new_alien = {'color': 'green', 'points': 5, 'speed': 'slow'}
    aliens.append(new_alien)

# Change first 3 aliens into yellow if it's green, into red if it's yellow
for alien in aliens[:3]:
    if alien['color'] == 'green':
        alien['color'] = 'yellow'
        alien['speed'] = 'medium'
        alien['points'] = 10
    elif alien['color'] == 'yellow':
        alien['color'] = 'red'
        alien['speed'] = 'fast'
        alien['points'] =15

for alien in aliens[:5]:
    print(alien)
print("...")

print("Total number of aliens: " + str(len(aliens)))
```





### A List in a Dictionary

you can nest a list inside a dictionary any time you want.

```python
# Store information about a pizza being ordered.
pizza = {
    'crust': 'thick',
    'toppings': ['mushrooms', 'extra cheese']  # nest list inside the dictionary.
}

# Summarize the order.
print("You ordered a " + pizza['crust'] + "-crust pizza " +
    "with the following toppings:")
for topping in pizza['toppings']: # access list in the dictionary.
    print("\t" + topping)
    
# You ordered a thick-crust pizza with the following toppings:
#         mushrooms
#         extra cheese
```

multiple lists in a dictionary.

```python
favorite_languages = {
    'jen': ['python', 'ruby'],
    'sarah': ['c'],
    'edward': ['ruby', 'go'],
    'phil': ['python', 'haskel'],
}

for name, languages in favorite_languages.items():
    if len(languages) == 1:
        print(f"\n{name.title()}'s favorite language is {languages[0].title()}.")
    else:
        print("\n" + name.title() + "'s favorite languages are:")
        for language in languages:
            print("\t" + language.title())
```

**you should not nest list and dictionaries too deeply. If you're nesting items much deeper than what you see in the preceding examples or you're working with someone else's code with significant levels of nesting, most likely a simpler way to solve the problem exists.**



### A dictionary in a Dictionary

You can nest a dictionary inside another dictionary, but your code can get complicated quickly when you do.



```python
users = {
    'aeinstein': {
        'first': 'albert',
        'last': 'einstein',
        'location': 'princeton',
    },
    'mcurie': {
        'first': 'marie',
        'last': 'curie',
        'location': 'paris',
    }
}

for username, user_info in users.items():
    print("\nUsername: " + username)
    full_name = user_info['first'] + " " + user_info['last']
    location = user_info['location']

    print("\tFull name: " + full_name.title())
    print("\tLocation: " + location.title())
```

**notice that the structure of each user's dictionary is identical. this structure makes nested dictionaries easier to work with.**



TIY.6-7~6-12

