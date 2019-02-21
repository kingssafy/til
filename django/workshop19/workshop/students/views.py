from django.shortcuts import render, redirect
from .models import Student
# Create your views here.

def index(request):
    context = {"students": Student.objects.all()}
    return render(request, 'students/index.html', context)

def new(request):
    return render(request, 'students/new.html')

def create(request):
    student = Student()
    for key, value in request.POST.dict().items():
        if key != 'csrfmiddlewaretoken':
            setattr(student, key, value)
    student.save()
    return redirect('/students/')

def edit(request, pk):
    student = Student.objects.get(pk=pk)
    context = dict(student=student) 
    return render(request, 'students/edit.html', context) 

def update(request, pk):
    student = Student.objects.get(pk=pk)
    for key, value in request.POST.dict().items():
        if key != 'csrfmiddlewaretoken':
            setattr(student, key, value)
    student.save()
    return redirect('/students/')

def delete(request, pk):
    student = Student.objects.get(pk=pk)
    student.delete()

    return redirect('/students/')
