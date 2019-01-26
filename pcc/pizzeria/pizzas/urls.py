"""Defines URL patterns for pizzas"""

from django.conf.urls import url
from . import views

urlpatterns = [
        #homepage
        url(r'^$', views.index, name='index'),
        url(r'^pizzas/$', views.pizzas, name='pizzas'),
        url(r'^pizzas/(?P<pizza_id>\d+)/$', views.pizza, name='pizza')
        ]
