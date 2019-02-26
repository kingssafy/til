from django.contrib import admin
from .models import Movie

# Register your models here.
class MovieAdmin(admin.ModelAdmin):
    list_dispaly = ('title', 'audience', 'genre', 'score', 'poster_url', 'description')

admin.site.register(Movie, MovieAdmin)
