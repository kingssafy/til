from django.urls import path
from . import views

app_name = 'movies'
urlpatterns = [
    path('<int:movie_pk>/scores/<int:score_pk>/delete', views.delete_score, name="delete_score"),
    path('<int:movie_pk>/scores/new/', views.create_score, name="create_score"),
    path('<int:movie_pk>/delete', views.movie_delete, name="movie_delete"),
    path('<int:movie_pk>/', views.detail, name="detail"),
    path('', views.index, name="index"),
]
