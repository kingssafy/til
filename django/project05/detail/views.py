from django.shortcuts import render

# Create your views here.


def index(request):
    return render(request, 'detail/index.html')

def qna(request):
    return render(request, 'detail/qna.html')

def mypage(request):
    return render(request, 'detail/mypage.html')

def signup(request):
    return render(request, 'detail/signup.html')

def not_found(request, not_found):
    context = {"not_found": not_found}
    return render(request, 'detail/index.html', context)
