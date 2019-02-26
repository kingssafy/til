https://stackoverflow.com/questions/744373/circular-or-cyclic-imports-in-python

There was a really good discussion on this over at [comp.lang.python](http://groups.google.com/group/comp.lang.python/browse_thread/thread/1d80a1c6db2b867c) last year. It answers your question pretty thoroughly.

> Imports are pretty straightforward really. Just remember the following:
>
> 'import' and 'from xxx import yyy' are executable statements. They execute when the running program reaches that line.
>
> If a module is not in sys.modules, then an import creates the new module entry in sys.modules and then executes the code in the module. It does not return control to the calling module until the execution has completed.
>
> If a module does exist in sys.modules then an import simply returns that module whether or not it has completed executing. That is the reason why cyclic imports may return modules which appear to be partly empty.
>
> Finally, the executing script runs in a module named __main__, importing the script under its own name will create a new module unrelated to __main__.
>
> Take that lot together and you shouldn't get any surprises when importing modules.




  ```python
#A.py
import B

def func():
    print(f"function A.py and my name is {__name__}")

print(f'top-level A.py & my name is {__name__}')

if __name__ == "__main__":
    print('A.py direct')
else: 
    print('A.py imported')
  ```

```python
#B.py
import A
def func():
    print(f"function B.py and my name is {__name__}")

print(f"top-level B.py & my name is {__name__}")
if __name__ == "__main__":
    print('B.py dirrct')
else:
    print('B.py imported')
```

```python
#python A.py
top-level A.py & my name is A
A.py imported
top-level B.py & my name is B
B.py imported
top-level A.py & my name is __main__
A.py direct
```

