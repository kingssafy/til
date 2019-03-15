from django.shortcuts import render, redirect
from .models import Board
from pprint import pprint
# Create your views here.

def index(request):
    pprint(request.META)
    pprint(request.method)
    articles = Board.objects.all()
    context = dict(articles=articles)
    return render(request, 'boards/index.html', context)

def new(request):
    if request.method == 'POST':
        context = request.POST
        board = {key:value for key, value in context.items() if key != 'csrfmiddlewaretoken'}
        board = Board(**board)
        board.save()
        return redirect('index')
    else:
        context = {}
        return render(request, 'boards/new.html', context)

def detail(request, pk):
    boards = Board.objects.all().get(pk=pk)
    return render(request, 'boards/detail.html', {'board': boards}) 

def edit(request, pk):
    getter = Board.objects.all().get(pk=pk)
    context = {"article": getter}
    return render(request, 'boards/edit.html', context)

def update(request, pk):
    getter = Board.objects.all().get(pk=pk)
    getter.title = request.POST.get("title")
    getter.content = request.POST.get("content")
    getter.save()
    return redirect('index')
def delete(request, pk):
    getter = Board.objects.all().get(pk=pk)
    getter.delete()
    return redirect('index')
