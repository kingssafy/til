#35.Write a Python program to sort Counter by value.
#input {'Math': 81, 'Physics': 83, 'Chemistry': 87}
#ouput [('Chemistry', 87), ('Physics', 83), ('Math', 81)]


a = {'Math': 81, 'Physics': 83, 'Chemistry': 87}
def sort_by_value(dictionary):
    a = sorted([(value, key) for key, value in dictionary.items()], reverse=True)
    return 
print(sort_by_value(a))
