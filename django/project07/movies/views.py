from django.shortcuts import render, redirect
from .models import *
# Create your views here.


def index(request):
    movies = Movie.objects.all()
    context = {
            "movies": movies,
            }
    return render(request, 'movies/index.html', context)

def detail(request, movie_pk):
    movie = Movie.objects.get(pk=movie_pk)
    scores = Score.objects.filter(movie=movie)
    context = {
            "movie": movie,
            "scores": scores,
            }

    return render(request, 'movies/detail.html', context)

def movie_delete(request, movie_pk):
    if request.method == "POST":
        movie = Movie.objects.get(pk=movie_pk)
        movie.delete()
        return redirect('movies:index')
    return redirect('movies:index')

def create_score(request, movie_pk):
    if request.method == "POST":
        movie = Movie.objects.get(pk=movie_pk)
        score = Score(movie = movie, content = request.POST.get("content"), score = request.POST.get("score"))
        score.save()
    return redirect('movies:detail', movie_pk)

def delete_score(request, movie_pk, score_pk):
    if request.method == "POST":
        score = Score.objects.get(pk=score_pk)
        score.delete()
    return redirect('movies:detail', movie_pk)
