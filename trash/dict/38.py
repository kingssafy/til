a = {'key1': 1, 'key2': 3, 'key3': 2}
b = {'key1': 1, 'key2': 2}

def inter_dict(a, b):
  result = {}
  for key, value in a.items():
    if b.get(key) == value:
      result[key] = value
  return result
  
print(inter_dict(a, b))
