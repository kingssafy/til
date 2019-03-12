def city_country(city, country):
    return city.title() + ", " + country.title()

a = city_country('seoul', 'korea')
b = city_country('new york','usa')
c = city_country('berlin', 'deutchland')
print(a)
print(b)
print(c)