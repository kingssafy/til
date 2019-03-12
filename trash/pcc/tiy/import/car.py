#car.py
"""A class that can be used to represent a car."""
class Car():
    """A simple attempt to represent a car."""
    
    def __init__(self, make, model, year):
        """Initialize attributes to describe a car."""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
        
    def get_descriptive_name(self):
        """Return a neatly formatted descriptive name."""
        self.long_name = str(self.year) + ' ' + self.make + ' ' + self.model
        return self.long_name.title()

    def read_odometer(self):  
        """Print a statement showing the car's mileage."""
        print("This car has " + str(self.odometer_reading) + " miles on it.")
        
    def update_odometer(self, mileage):    
        """Set the odometer reading to the given value."""
        self.odometer_reading = mileage
