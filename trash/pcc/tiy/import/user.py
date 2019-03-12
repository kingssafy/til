class User():
    
    def __init__(self, first_name, last_name, age, sex):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.sex = sex
    
    def describe_user(self):
        print(f"\n ---user info ---")
        print(self.first_name)
        print(self.last_name)
        print(self.age)
        print(self.sex)
        
    def greet_user(self):
        print(f"Hello, {(self.first_name + ' '  + self.last_name).title()}!")

