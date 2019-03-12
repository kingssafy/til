from django.shortcuts import render
from pizzas.models import Pizza
# Create your views here.
def index(request):
    """The homepage for pizzeria"""
    return render(request, 'pizzas/index.html')
def pizzas(request):
    """Pizzas"""
    pizzas = Pizza.objects.order_by()
    context = {'pizzas': pizzas}
    return render(request, 'pizzas/pizzas.html', context)

def pizza(request, pizza_id):
    """toppigns = a pizza"""
    pizza = Pizza.objects.get(id=pizza_id)
    toppings = pizza.topping_set.order_by()
    context = {'pizza': pizza, 'toppings': toppings}
    return render(request, 'pizzas/pizza.html', context)
