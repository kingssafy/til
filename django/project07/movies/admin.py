from django.contrib import admin
from .models import Genre, Movie, Score
# Register your models here.

class GenreAdmin(admin.ModelAdmin):
    list_display = ("name",)

class MovieAdmin(admin.ModelAdmin):
    list_display = ("title", "audience", "poster_url", "description")

class ScoreAdmin(admin.ModelAdmin):
    list_display = ("content", "score")

admin.site.register(Movie, MovieAdmin)
admin.site.register(Genre, GenreAdmin)
admin.site.register(Score, ScoreAdmin)
