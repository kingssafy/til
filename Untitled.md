# Django

## Start a project and apps

```terminal
django-admin startporject projectname .
you must enter . at the end!!
```

```terminal
$ python manage.py startapp appname
```

```terminal
goto projectname folder edit settings.py
and add `appname` to installed app
```

and add models to use

goto app folder and edit models.py

```python
from django.db import models

# Create your models here
class Topic(models.Model):
    """Will retain topics like python, django"""
    text = models.CharField(max_length=50)
    date_added = models.DateTimeField(auto_now_add=True)
    def __str__(self):
        return self.text

class Entry(models.Model):
    """Entries for each topics"""
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)
    topic = models.ForeignKey('Topic', on_delete=models.CASCADE)
    
    class Meta:
        verbose_name_plural = "entries"
    def __str__(self):
        return self.text if len(self.text) < 50 else self.text[:50] + "..."
```



and do makemigrations

```terminal
$ python manage.py makemigrations appname
$ python manage.py migrate
```

and createsuperuser

```terminal
$ python manage.py createsuperuser
```

And goto app folder and edit admin.py after edit you can see topics and entires  fields at admin page!

```python
###admin.py
from django.contrib import admin
from .models import Entry, Topic
# Register your models here.
admin.site.register(Topic)
admin.site.register(Entry)
```



add some data at entries, topics



```html
<!-- appfolder/templates/appname/index.html -->
<p>
    indexpage
</p>
```

```python
#appfolder/views.py
from django.shortcuts import render

#create your views here

def index(request):
    return render(request, 'til/index.html')
```

touch appname/urls.py

```python
#APPNAME/urls.py

from django.conf.urls import url
from . import views

urlpatterns = [
    url(r'^$', views.index, name='index')
]
```

goto project mian folders urls.py

```python
from django.contrib import admin
from django.urls import path, include #include

urlpatterns = [
    path('admin/' admin.site.urls),
    path('', include(('til.urls', 'til'), namespace='til')) #first 'til' is appname
    
]
```

go localhost:8000 you will see indexpage



appname/views.py

```python
from django.shortcuts import render
from .models import Topic

def index(request):
    return render(request, 'til/index.html')

def topics(request):
    topics = Topic.objects.all()
    context = {"topics": topics}
    return render(request, 'til/topics.html', context)

def topic(request, topic_id):
    topic = Topic.objects.get(id=topic_id)
    entries = topic.entry_set.order_by('-date_added') # -date_added in quote!!!
    context = {"topic"= topic, "entries": entries}
    return render(request, 'til/topic.html', context)
```

appname/urls.py

```python
from django.conf.urls import url
from . import views

urlpatterns = [
    			url(r'^$', views.index, name='index'),
    			url(r'^topics/$', views.topics, name='topics'),
    			url(r'^topics/(?P<topic_id>\d+)/$', views.topic, name='topic'),    
    
]
```

templates/appname/base.html

```html
<a href="{% url 'til:index' %}"> home </a>
{% block content %} {% endblock content %}
```

index.html

```html
<!-- appfolder/templates/appname/index.html -->
<!DOCTYPE html>
<html>
    
    <head>
        
       {% extends 'til/base.html' %}
    </head>
    {% block content %}
    <p>
        indexpage
    </p>
	{% endblock content %}
</html>
```

Topics.html

```html
{% extends 'til/base.html' %}
{% block content %}
<ul>
    {% for topic in topics %}
    <li><a href="{% url 'til:topic' topic.id %}">{{ topic}}</a></li>
    {% empty %}
    <li> no topics are added yet</li>
    {% endfor %}
    
</ul>
{% endblock content %}
```

Topics.html

```html
{% extends 'til/base.html' %}
{% block content %}
	<p>
         {{ topic}}:
</p>
<ul>
    
  {% for entry in entries %}
    <li><p>
        {{ entry.text }}
        </p>
        <p>
            {{ entry.date_added|date:'M d, Y H:i' }}
        </p>
    	{% empty %}
        <li>
    There are no entries for this topic yet.</li>
    
    </li>
	{% endfor %}
</ul>
{% endblock content %}
```