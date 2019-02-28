from django.shortcuts import render, redirect, HttpResponse
from .models import Article
# Create your views here.


def index(request):
    full = Article.objects.order_by('title')
    context = {"full": full}
    return render(request, 'boards/index.html', context)

def new(request):
    return render(request, 'boards/new.html')

def create(request):
    context = request.POST.dict()
    context.pop("csrfmiddlewaretoken")
    a = Article(**context)
    a.save()
    
    return redirect('/boards/')

def delete(reqeust, pk):
    Article.objects.get(pk=pk).delete()
    return redirect('/boards/')
