from django.shortcuts import render
from .models import BlogPost
from .forms import BlogForm
from django.http import HttpResponseRedirect
from django.urls import reverse
# Create your views here.
def index(request):
    posts = BlogPost.objects.order_by('-date_added')
    context = {'posts': posts}
    return render(request, 'blogs/index.html', context)

def add_post(request):
    """add a new post """
    if request.method != 'POST':
        # No data submitted; create blank form.
        form = BlogForm()
    else:
        # POST DATA SUBMITTED; process data.
        form = BlogForm(data=request.POST)
        if form.is_valid():
            new_post = form.save(commit=False)
            new_post.save()
            return HttpResponseRedirect(reverse('blogs:index'))
    
    context = {'form': form}
    return render(request, 'blogs/add_post.html', context)

def edit_post(request, post_id):
    """edit a post"""
    post = BlogPost.objects.get(id=post_id)
    if request.method != "POST":
        # No data submitted, create form with exist text.
        form = BlogForm(instance=post)
    else:
        # Post data submitted
        form = BlogForm(instance=post, data=request.POST)
        if form.is_valid():
            form.save()
            return HttpResponseRedirect(reverse('blogs:index'))
    context = {'post': post, 'post_id':post_id}
    return render(request, 'blogs/edit_post.html', context)
