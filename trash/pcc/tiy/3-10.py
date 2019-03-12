#Every Function and Method
girls = ['hairy', 'skinny', 'french', 'deutch', 'burst']

print(girls[0]) # you can access any element in a list by index!
#index off-by-zero !
print(girls) #prints its original list

girls[1] = 'fatty'
print(girls) # you can modify elements in a list

#addings
girls.append('skinny') #use list.append(element) to add an element to end of the list
print(girls)

girls.insert(1, 'sexy') #use list.insert(index, element) to add an element to index
print(girls)
#removings
del girls[0] #use del statement to remove items by index
print(girls)

print(girls.pop()) #with no args list.pop() method will return last element and delete it from the list
            #you can pass specific index to pop() method to pop what you want 
print(girls)

girls.remove('deutch') #list.remove(value) method  you can remove an element from a list by value!
print(girls)

#organizing a list

print(sorted(girls)) #temporarily alphabetical order 

print(sorted(girls,reverse=True)) #temporarily reverse alphabetical order

print(girls) #its original order

girls.reverse() #reverse of its original order
print(girls)

girls.sort() # list.sort() method will permanenetly change list in alphabetical order(when all the list is in lowercase. it's complicated
#when you come across with mixed list)
print(girls)
girls.sort(reverse=True) # reverse alphabetical order
print(girls)

#length of list
print(len(girls)) #off-by-one
