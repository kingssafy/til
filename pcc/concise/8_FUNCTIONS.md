# Functions

- Function : blocks of code that are designed to do one specific job

- `module`: Python files which have functions!

- Sometimes you'll want to prevent a function from modifying a list.

  you can address this issue by passing the `function a copy of the list` `when you call a function

  ```python
  print_models(unprinted_designs[:], completed_models)
  ```


- defining a function

```python
def function_name(parameters):
    """docstring"""# describes what the function does
    # function body(actual code in this function)
    
    return value  #function returns value to where the function called. 
				  # you can return any type of value!! in any forms you want

#call function
function_name(argument)
```

to `call` a function you write the name of function, followed by any necessary information in parentheses

### Passing Arguments

- Positional Arguments: the order of the arguments provided
- Keyword Argument: A `keyword argument` is a`parameter-argument` pair that you pass to a function. 

**be sure to use the exact names of the parameters in the function's definition.**

- ##### you can pass any type of argument you want!(list, dict, int, str ***)

## parameter configs

- #### you can define a `default value` for each parameter

```python
def funtion(parameter, parameter2=defaultvalue):
```

***When you use default values, any parameter with a default value needs to be listed after all the parameters that don't have default values. This allows Python to continue interpreting positional arguments correctly.***

- #### you can make an argument optional

  ```python
  def function_name(parameter, parameter2=''):
      if parameter2:
          do(if arg for parameter2 passed)
      else:
          do(if arg for parameter2 notpassed)
  ```


- ### Passing an Arbitrary Number of Arguments

  ```python
  def function_name(*args)
  ```

  `aste*risk` in the parameter name `*args` tells python to make an empty tuple called `args` and pack whatever values it receives into this tuple

- ### Mixing Positional and arbitrary arguments.

  **arbitrary number of arguments must be placed last in the function definition**.

- ### Using Arbitrary Keyword Arguments

  ```python
  def function_name(first, second, **args):
  ```

  Python to create an empty dictionary called user_info and pack whatever name-value pairs it receives into this dictionary


