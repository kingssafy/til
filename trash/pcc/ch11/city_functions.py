#11-1, City, Country

def get_formatted_city(city, country, population=0):
    """returns formatted city, countryname"""
    return f'{city.title()}, {country.title()}' + (f' - {population}' if population else "")

