from django.contrib import admin

# Register your models here.
from meal_plans.models import Meal, Menu

admin.site.register(Meal)
admin.site.register(Menu)
