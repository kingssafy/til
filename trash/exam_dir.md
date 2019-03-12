시험dir

아래가 궁금하다

```python
class Person():
    population = 0
    abc = 1
    def __init__(self, name):
        self.name = name
        Person.population += 1
    def greeting(self):
        print(f"{self.name} 입니다. 반가워요")
        
kim = Person("eric")
print(kim.population)
del Person
class Person():
    population = 55
    abc = 1
    def __init__(self, name):
        self.name = name
        Person.population += 1
    def greeting(self):
        print(f"{self.name} 입니다. 반가워요")
cath = Person('erine')
print(cath.population)
errr = Person('err')
print(kim.population)
print(cath.population)
```

나의 가설 >>클래스 호출될때 클래스자체 개체를 메모리에 넣음 그리고 Person()은 그 개체를 참조하는 주소를 담고있고  del하면 Person() 주소지만 삭제하고 그 개체는 남아있음

# 상속할때도 이렇게되는지 한번 체크해보자 꼭



class Person():
    population = 0
    abc = 1
    def __init__(self, name):
        self.name = name
        Person.population += 1
    def greeting(self):
        print(f"{self.name} 입니다. 반가워요")
        
kim = Person("eric")
print(kim.population)
del Person
class Person():
    population = 55
    abc = 1
    def __init__(self, name):
        self.name = name
        Person.population += 1
    def greeting(self):
        print(f"{self.name} 입니다. 반가워요")
cath = Person('erine')
print(cath.population)
errr = Person('err')
print(kim.population)
print(cath.population)



```python
연산자 오버라이딩은 연산자 앞에있는 함수를 호출함
# 사람과 사람을 더하면, 나이의 합을 반환하도록 만들어봅시다.
class Person():
    population = 0
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
        Person.population += 1
    
    def greeting(self):
        print(f'{self.name}입니다. 반가워요.')
        
    def __add__(self, other):
        return f'나이 합은 {self.age + other.age}'
    
    def __sub__(self, other):
        return f'나이 차는 {self.age - other.age}'
    
class Animal():
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def __add__(self, other):
        return f'동물나이의합은 {self.age + other.age}'
    
p1 = Person("아저씨", 40)
p2 = Animal("청소년", 18)

p2 + p1 #'동물나이의합은 58'
p1 + p2 # '나이 합은 58'

    
    
```

