# Great Magicians
def show_magicians(magicians):
    for magician in magicians:
        print(magician.title())

magicians = ['david copperfield', 'john johns']
show_magicians(magicians)

def make_great(magicians):
    templist = []
    for magician in magicians:
        great = "Great" + " " + magician
        templist.append(great)
    return templist[:]

magicians = make_great(magicians)
show_magicians(magicians)