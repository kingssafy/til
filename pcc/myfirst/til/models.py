from django.db import models

# Create your models here.
class Topic(models.Model):
    """topics like python, javascript"""
    text = models.CharField(max_length=50)
    date_added = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.text

class Entry(models.Model):
    """entry for topic"""
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)

    class Meta:
        verbose_name_plural = "entries"
    
    def __str__(self):
        return self.text if len(self.text) < 50 else self.text[:50] + "..."
