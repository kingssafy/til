
class Person:
    def __init__(self, name, job=None, pay=0): #Constructor takes three arguments
        self.name = name                       # Fill out fields when created
        self.job = job                         # self is the new instance object
        self.pay = pay
    
    def lastName(self):
        return self.name.split()[-1]
    
    # @rangetest(percent=(0.0, 1.0)) # Use decorator to validate
    def giveRaise(self, percent):
        self.pay = int(self.pay * (1 + percent))

    def __repr__(self):
        return '[Person: %s, %s]' % (self.name, self.pay)

class Manager:
    def __init__(self, name, pay):
        self.person = Person(name, 'mgr', pay)
    def giveRaise(self, percent, bonus=.10):
        self.person.giveRaise(percent + bonus)
    def __getattr__(self, attr):
        return getattr(self.person, attr)
    def __repr__(self):
        return str(self.person) #Must overload again (in 3.x)


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
    print('--- All three---')
    for obj in (bob, sue, tom): #process objects generically
        obj.giveRaise(.10) # run this object's giveRaise
        print(obj) # run the common __repr__
    
