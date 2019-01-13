# String





## Method

`.capitalize()` : 앞글자를 대문자 else lower() 로 만들어 반환합니다.

`.title()` : **어포스트로피나 공백을 이후**를 대문자로 만들어 반환합니다.

`.swapcase()` : upper to lower lower to upper

`.replace(old, new,count(optional))`

`.replace(old, new[, count])`if count <0 reversed

`.find(char)` return first index of char, if doesn't exist returns -1

`.index(x)`: return first index of char, if doesn't raise error

`.isalpha()` : 문자열이 오직 알파벳으로만 구성되어있으면 True (공백 포함 False)

- 문자열의 모든 문자가 10진 숫자문자일 때 True
  - `.isdecimal()` : (Only Decimal Numbers)
  - `.isdigit()` : (Decimals, Subscripts, Superscripts)
  - `.isnumeric()` : (Digits, Vulgar Fractions, Subscripts, Superscripts, Roman Numerals, Currency Numerators)

`.isspace()` : 모두 공백문자이면 True

`.isupper()` : 모두 대문자이면 True

`.istitle()` : 모든 문자열이 title 스타일 (단어마나 첫글자가 대문자) 이면 True

`.islower()` : 모두 소문자이면 True

`.split(separtaor=whitespacem, maxsplit=-1)`:문자열을 특정한 단위로 나누어 리스트로 반환합니다. maxsplit defines the maximum number of splits. -1 means nolimit

```python
# Splitting at ':'
grocery = 'Milk, Chicken, Bread'
print(grocery.split(':'))
['Milk, Chicken, Bread']
```

문자열 뒤집기

```python
str_test = 'Hello world from ssafy'
str_test = str_test[::-1]
print(str_test)
```

