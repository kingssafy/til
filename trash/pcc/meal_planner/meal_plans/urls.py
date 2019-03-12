"""Defines URL patterns for meal_plans"""
from django.urls import path
from . import views

urlpatterns = [
        # Homepage
       path('', views.index) 

        ]
