from django.urls import path
from . import views

urlpatterns = [
    path('delete/<int:pk>/', views.delete, name="delete"),
    path('update/<int:pk>/', views.update, name="update"),
    path('edit/<int:pk>/', views.edit, name="edit"),
    path('detail/<int:pk>/', views.detail, name="detail"),
    path('new/', views.new, name="new"),
    path('', views.index, name="index"),
 ]
