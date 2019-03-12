# Cars

def car(manu, model, **car_info):
    car = {}
    car['manufacturer'] = manu
    car['model'] = model
    for key, value in car_info.items():
        car[key] = value
    return car

audi = car('audi', 'a3', colour = 'black', kind = 'sedan', tire = '19inches')
print(audi)