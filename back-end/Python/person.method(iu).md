person.method(iu)

==

iu.method()

```python
class Person:
    name = '고길동'   #이거 자동으로  self.name = 고길동 이렇게되네 개좋다
    def say_hello(self):
        print(f"Hello, I'm {self.name}.")
iu = Person()
iu.say_hello()
Person.say_hello(iu)
```



a = b

a represent address b represnt value





## Person.say_hello(iu) 이 방법으로 인스턴스 생성가능한가??

class PE

```python
class Person(): #__init__ 재귀적인거네!!
    def __init__(self[클래스호출], name, age=0):
        self.name = name
        self.age = age
        
그럼 이건 곧
class Person():
    name = arg.name
    age = arg.age
    이라는 class를 만들어서 인스턴스에 할당해주는건가용?
```

class Circle:
​    pi = 3.14 
​    def __init__(self, r, x=0, y=0):
​        self.r = r
​        self.x = x
​        self.y = y
​    

    def area(self):
        return (self.r**2)*Circle.pi  #클래스이름으로 pi가져온다 클래스젤위에있어서
    
    def circumference(self):
        return 2 * Circle.pi * self.r #여기서 Circle.pi는 장점이 하나만 Class circle에서
                            #pi를 변경해주면 전체 instance의 pi값 변경가능
# 클래스안에 인스턴스 다 나열가능한가용????

딕셔너리처럼 볼수있나요    