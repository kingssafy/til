from django.db import models

# Create your models here.

class Meal(models.Model):
    """Breakfast, lunch, dinner..."""
    text = models.CharField(max_length=50)
    date_added = models.DateTimeField(auto_now_add=True)
    def __str__(self):
        return self.text

class Menu(models.Model):
    """Menues"""
    Menu = models.ForeignKey(Meal, on_delete=models.CASCADE)
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)

    class Meta:
        verbose_name_plural = "Menues"

    def __str__(self):
        """return a string representation of the model"""
        return self.text
