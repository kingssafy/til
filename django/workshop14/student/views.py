from django.shortcuts import render

# Create your views here.

students = [
        {"name": "hong gil dong",
         "age": 25},
        {"name": "park", "age":29},
    ]
teacher = "edujunho"

def info(request):
    
    students = [
            {"name": "hong gil dong",
             "age": 25},
            {"name": "park", "age":29},
        ]
    teacher = "edujunho"

    
    return render(request, 'info.html', {"students": students})

def student(request, key):
    
    students = [
            {"name": "hong gil dong",
             "age": 25},
            {"name": "park", "age":29},
        ]
    teacher = "edujunho"
    return render(request, 'student.html', {"students": students, "key" :key})
