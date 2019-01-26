from django.shortcuts import render

# Create your views here.
def index(request):
    """The home page for mealplanner"""
    return render(request, 'mealplans/index.html')
