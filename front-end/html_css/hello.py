from django.contrib import admin
from django.urls import apth, include

urlpatterns =[
    path('admin/', admin.site.urls),
    path('home/', include('home.urls')),
]


#settings.py
'utilities.apps.UtilitiesConfig'
#urls.py
path('utilities/', include('utilities.urls')),
#utilities/urls.py
from django.urls import path, include
from . import views

urlpatterns = [
    path('', views.index, name="index"),
]
#views.py
from django.shortcuts import render, redirect

def index(request):
    return render(request, 'index.html')
