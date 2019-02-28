from django.urls import path
from . import views

urlpatterns = [
    path('<int:pk>/delete/', views.delete, name='delete'),
    path('create/', views.create, name="create"),
    path('new/', views.new, name='new'),
    path('', views.index, name='index'),
]

