## 내가잘푼문제

> 몇개의 숫자가 주어지면, 사용되지 않은 숫자를 프린트하세요.

> 예시
>
> - unused_digits(12, 34, 56, 78) # "09"
> - unused_digits(2015, 8, 26) # "3479"

> 유의
>
> - 결과값은 정렬되어야 합니다.
> - 

# 여기에 코드를 작성하세요
```python
def unused_digits(*args):
     return "".join([i for i in '0123456789' if i not in "".join(map(str,args))])

```



