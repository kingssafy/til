import unittest
from city_functions import get_formatted_city

class TestC(unittest.TestCase):
    
    def test_city_country(self):
        formatted = get_formatted_city('paris','france')
        self.assertEqual(formatted, 'Paris, France')
    
    def test_city_country_population(self):
        formatted = get_formatted_city('paris', 'france', 1000)
        self.assertEqual(formatted, 'Paris, France - 1000')
unittest.main()
