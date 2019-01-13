# VARIABLES AND SIMPLE DATA TYPES

## Variables

- *variables* : Every single variable holds a value, which is the information associated with that variable.
- note : you can change the value of a variable in your program at any time

Variable naming rules(follows snake_case )

```bash
Be sure to keep the following variable rules in mind

- Variable names can contain only letters, numbers, and underscores. They can start with a letter or an underscore, but not with a number.

- Spaces are not allowed in variable names, but underscores can be used to separate words in variable names.

- Avoid using Python keywords and function names as variable names

- Variable names should be short but descriptive. 

- be careful when using the lowercase letter l and the uppercase letter O.
```

## Strings

you can use both single, and double quote

> This Flexibility allows you to use quotes and apostrophes within your string

```python
'i told my friend, "Python is my favorite language!"'
"The language 'Python' is blablah"
```

## Methods

- `str.upper()`: make str uppercase
- `str.lower()`:make str lowercase
- `str.title()`: make str titlecase
- `str.isalpha()`: only Alphabets (True or False) no whitespaces.
- `str.isdecimal()`: #only 0~9(True)
- `str.isdigit()`: (Decimals, Subscripts, Superscripts)
-  `str.capitalize()`: capitalize first character
- `str.swapcase()`: switch capitalization
- `str.join(iterable)`:
- `str.replace(old,new,[count])`:

concatenation : plus symbol (+) to combine strings. 




### Making white spaces with in strings

too add a tab, use charactor combination `\t`

- newline : `\n`

## Numbers

Python treats numbers in several different ways, depending on how they are being used.

### Integers (no decimal point)

`+` add, `-` subtract, `*`Multiply, /`/`divide, `**`exponent, `%%` remainder



### Floats (number with decimal point)

- Caution

  ```python
  >>> 0.2 + 0.1
  0.30000000000000004
  >>> 3 * 0.1
  0.30000000000000004
  ```

### study tips for beginners:

The best way to understand new programming concepts is to try using them in your programs. If you get stuck while working on an excercise in this book, try doing something else for a while. If you're still stuck, review the relevant part of that chapter. If you still need help, see the suggestions in appendix C.