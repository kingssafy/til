from django.db import models

# Create your models here.
class Movie(models.Model):
    title = models.CharField(max_length=100)
    audience = models.IntegerField()
    genre = models.CharField(max_length=100)
    score = models.FloatField()
    poster_url = models.TextField()
    description = models.TextField()
    def __str__(self):
        return f"{self.title}: {self.description[:10]}..."
