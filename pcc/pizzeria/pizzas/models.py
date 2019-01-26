from django.db import models

# Create your models here.
class Pizza(models.Model):
    """Set of Pizzas"""
    name = models.CharField(max_length=50)

    def __str__(self):
        return self.name

class Topping(models.Model):
    """Topping"""
    pizza = models.ForeignKey(Pizza, on_delete=models.CASCADE)
    name = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)

    class Meta:
        verbose_name_plural = 'toppings'

    def __str__(self):
        """return pizza and topping"""
        return self.name
