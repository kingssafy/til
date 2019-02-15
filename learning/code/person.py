"""
Record and process information about people.
Run this file directly to test its classes
"""

# Allow this file to be imported as well as run/tested
# Add methods to encapsulate operations for maintainability.
# Add __repr__ overload method for printing objects

from classtools import AttrDisplay

class Person(AttrDisplay):
    """Create and process person records"""
    def __init__(self, name, job=None, pay=0): #Constructor takes three arguments
        self.name = name                       # Fill out fields when created
        self.job = job                         # self is the new instance object
        self.pay = pay
    
    def lastName(self):
        return self.name.split()[-1]
    
    # @rangetest(percent=(0.0, 1.0)) # Use decorator to validate
    def giveRaise(self, percent):
        self.pay = int(self.pay * (1 + percent))

class Manager(Person): # Define a subclass of Person # inherit Person attrs
    """
    A customized Person with special requirements
    """
    def __init__(self, name, pay): # Redefine constructor
        Person.__init__(self, name, 'mgr', pay) # Run original with 'mgr'

    def giveRaise(self, percent, bonus=.10): # Redefine to customize
        # self.pay = int(self.pay * (1 + percent + bonus)) # Bad: cut and paste!
        Person.giveRaise(self, percent + bonus) # Good: augment original !!

if __name__ == '__main__':
    #when run for testing only
    #self-test code
    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job='dev', pay=100000)
    print(bob)
    print(sue)
    print(bob.lastName(), sue.lastName())
    sue.giveRaise(.10)
    print(sue)
    tom = Manager('Tom Jones', 50000) # job name not needed:# Make a manager: __init__
    tom.giveRaise(0.10) #Runs custom verison
    print(tom.lastName())#runs inherited Method
    print(tom)# runs inherited __repr__
    
