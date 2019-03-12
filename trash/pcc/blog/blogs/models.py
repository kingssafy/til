from django.db import models

# Create your models here.

class BlogPost(models.Model):
    title = models.CharField(max_length=50)
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)
    def __str__(self):
        return self.title
