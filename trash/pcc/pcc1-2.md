#VARIABLES AND SIMPLE DATA TYPES

### What Really Happens When you Run Hello_world.py

```python
#Hello_world.py
print("Hello Python world!")
```

when the interpreter sees the word `print`, it prints to the screen whatever is inside the parenthesis.

### Variables

```python
message = "Hello Python world!"
print(message)

message = "Hello Python Crash Course world!"
print(message)
```

Every variable holds a value, which is the information associated with that variable. when Python interpreter processes the first line, it associates the text "Hello Python world!" with the variable `message` . When it reaches the second line, it prints the value associated with message to the screen.

- you can change the value of a variable in your program at any time, and Python will always keep track of its current value.

### Naming and using variables

Be sure to keep the following variable rules in mind

- Variable names can contain only letters, numbers, and underscores. They can start with a letter or an underscore, but not with a number.

- Spaces are not allowed in variable names, but underscores can be used to separate words in variable names.
- Avoid using Python keywords and function names as variable names
- Variable names should be short but descriptive. 
- be careful when using the lowercase letter l and the uppercase letter O.

**The Python variables you're using at this point should be lowercase. you won't get errors if you use uppercase letters, but it's a good idea to avoid using them for now**

### Avoiding Name Errors When Using Variables

```python
message = "Hello Python Crash Course reader!"
print(mesage)
```

`Traceback (most recent call last):
  File "pcc.py", line 2, in <module>
​    print(mesage)
NameError: name 'mesage' is not defined`

a name error usually means we either forgot to set a variable's value before using it, or we made a spelling mistake when entering the variable's name

**The best way to understand new programming concepts is to try using them in your programs. If you get stuck while working on an excercise in this book, try doing something else for a while. If you're still stuck, review the relevant part of that chapter. If you still need help, see the suggestions in appendix C.

- TIY2-1

- TIY2-2

### Strings

you can use both single quote, and double quote

```python
"This is a string."
'this is also a string.'
#This flexibility allows you to use quotes and apostrophes within your string
'i told my friend, "Python is my favorite language!"'
"The language 'Python' is blablah"
```

### Changing Case in a String with Methods

```python
#name.py
name = "ada lovelace"
print(name.title())
```

`Ada Lovelace`

- A *method*s an action that Python can perform on a piece of data. The dot (.) after `name` in `name.title()` tells Python to make the `title()` method act on the variable `name`. Every method is followed by a set of parenthesis, because methods often need additional information to do their work.

```python
name = "Ada Lovelace"
print(name.upper()) #ADA LOVELACE
print(name.lower()) #ada lovelace
```

The `lower()` method is particulary useful for storing data. Many times you won't want to trust the capitalization that your users provide, so you'll convert strings to lowercase before stroing them

### Combining or Concatenating Strings

```python
first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name

print(full_name)
```

```
ada lovelace
```

Python uses the plus symbol (+) to combine strings. This method of combining string is called *concatenation*. you can use *concatenation* to compose complete message using the information you've stored in variables.

```python
first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name

print("Hello, " + full_name.title() + "!")
```

```
Hello, Ada Lovelace!
```

You can use concatenation to compose a message and then store the entire message in a variable.

```python
first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name

message = "Hello, " + full_name.title() + "!"
print(message)
```

this code makes the final print statement much simpler.

### Adding Whitespace to string with Tabs Newlines

In programming, *whitespace* refers to any nonprinting character, such as spaces, tabs, and end-of-line symbols.

To add a tab to your text, use the charactor combination `\t`:

```python
>>> print("Python")
Python
>>> print("\tPython")
	Python
```

to add a newline in a string, use the character combination `\n`:

```python
>>> print("Languages:\n\tPython\n\tC\n\tJavaScript")
Languages:
	Python
	C
	JavaScript
```

### stripping Whitespace

Extra whitespace can be confusing in your programs. To programmers `'python'` and `'python	 '`look pretty much the same. but to a program, they are two different strings.



To ensure that no white space exists at end of string. Use below.

`rstrip()` for right end, `lstrip()` for left end, and `strip()` for both end.

```python
>>> favorite_language = '	python	'
>>> favorite_language.rstrip()
'	python'
>>> favorite_language.lstrip()
'python	   '
>>> favorite_language.strip()
'python'
```

in the real world, these stripping functions are used most often to clean up user input before it's stored in a program.

### avoiding Syntax Errors with String

```python
message = 'One of Python's strength is its diverse community.'
print(message)
```

You'll see the following output:

```bash
  File "pcc.py", line 1
    message = 'one of Python's strength is its diverse community.'
                             ^
SyntaxError: invalid syntax
```

This *syntax error* indicates that the interpreter doesn't recognize something in the code as valid Python code.

**Your editor's syntax highlighting feature should help you spot some syntax errors quickly as you write your programs. If you see Python code highlighted as if it's English or English highlighted as if it's Python code, you probably have a mismatched quotation mark somewhere in your file.**

### Printing in Python2

```bash
>>> python2.7
>>> print "Hello Python 2.7 world!"
Hello Python 2.7 world!
```

Parentheses are not need around the phrase you want to print in Python 2.

* TIY2-3~2.7

## Numbers

Python treats numbers in several different ways, depending on how they are being used.

###Integers

You can add `+`, subtract `-`, multiply `*`, and divide `\` integers in Python.

and python uses two multiplication symbols to represent exponents

Python supports the order of operations too, so you can use multiple operations in one expression. You can also use parentheses to modify the order of operations.

```bash
>>> 2 + 3
5
>>> 3 - 2
1
>>> 2 * 3
6
>>> 3 / 2
1.5
>>> 3 ** 3
27
>>> 2 + 3 * 4
14
>>> (2 + 3) * 4
20
```

### Floats

Python calls any number with a decimal point a float.

for the most part, you can use decimals without worrying about how they behave. but be aware that you can sometimes get an arbitrary number of decimal places in your answer:

```bash
>>> 0.2 + 0.1
0.30000000000000004
>>> 3 * 0.1
0.30000000000000004
```

This happens in all languages and is of little concern. Python tries to find a way to represent the result as precisely as possible, which is sometimes difficult given how computers have to represent numbers internally. just ignore the extra decimal places for now; you'll learn ways to deal with the extra places when you need to in the projects in *PartII*.

### Avoiding Type Errors with the str() Function

```python
age = 23
message = "Happy " + age + "rd Birthday!"

print(message)
```

this code generates an error

```bash
Traceback (most recent call last):
  File "pcc.py", line 2, in <module>
    message = "Happy " + age + "rd Birthday!"
TypeError: must be str, not int
```

This is a `type error`. It means Python can't recognize the kind of information you're using.

```python
age = 23
message = "Happy " + str(age) + "rd Birthday!"

print(message)
```

Python now knows that you want to convert the numerical value 23 to a string.

### Integers in Python 2

```bash
>>> python 2.7
>>> 3 / 2
1
```

note that the result is not a rounded integer; the remainder is simply omitted. 

​	To avoid this behavior in Python2, make sure that at least one of the numbers is a float. By doing so, the result will be a float as well:

```bash
>>> 3 / 2
1
>>> 3.0 / 2.0
1.5
>>> 3 / 2.0
1.5
>>> 3.0 / 2
1.5
```

- TIY2-8~2-9

## Comments

As your programs become longer and more complicated, you should add notes within your programs that describe your overall approach to the problem you're solving

### How Do You Write Comments

In python, the hash mark `#` indicates a comment. Anything following a hash mark in your code is ignored by the Python interpreter.

```python
# Say Hello to everyone.
print("Hello Python people!")
```

```
Hello Python People!
```

### What Kind of Comments Should You Write

The main reason to write comments is to explain what your code is supposed to do and how you are make it work.



### The Zen of Python

The Zen of Python, by Tim Peters

Beautiful is better than ugly.
Explicit is better than implicit.
Simple is better than complex.
Complex is better than complicated.
Flat is better than nested.
Sparse is better than dense.
Readability counts.
Special cases aren't special enough to break the rules.
Although practicality beats purity.
Errors should never pass silently.
Unless explicitly silenced.
In the face of ambiguity, refuse the temptation to guess.
There should be one-- and preferably only one --obvious way to do it.
Although that way may not be obvious at first unless you're Dutch.
Now is better than never.
Although never is often better than *right* now.
If the implementation is hard to explain, it's a bad idea.
If the implementation is easy to explain, it may be a good idea.
Namespaces are one honking great idea -- let's do more of those!

