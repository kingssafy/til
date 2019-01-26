from django.db import models

# Create your models here.
class Topic(models.Model):
    """Will retain topics like python, django"""
    text = models.CharField(max_length=50)
    date_added = models.DateTimeField(auto_now_add=True)
    def __str__(self):
        return self.text

class Entry(models.Model):
    """Entry for each topic"""
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)
    topic = models.ForeignKey('Topic', on_delete=models.CASCADE)
    
    class Meta:
        verbose_name_plural = "entries"

    def __str__(self):
        return self.text if len(self.text) < 50 else self.text[:50] + "..."
