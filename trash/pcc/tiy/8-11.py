## Great Magicians
templist = []
magicians = ['david copperfield', 'john johns']
great_magicians = []

def show_magicians(magicians):
    for magician in magicians:
        print(magician.title())

def make_great(magicians):
    while magicians:
        great_magicians.append("Great" + " " + magicians.pop())

show_magicians(magicians)
make_great(magicians[:])
show_magicians(magicians)
print(great_magicians)