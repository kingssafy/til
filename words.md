conform:
    This allows instances to conform to a function based API

gratuitous
the `__call__` may seem a bit gratuitous at first glance.

Obfuscate:
How (Not) to Obfuscate Your Python code


convoluted
there is a limit to emulating statements with expressions: you can't directly achieve an assignment statement's effect, for instance, though tools like the `setattr` built-in, the `__dict__` of namespaces, and methods that change mutable objects in place can sometime stand in, and functional programming techniques can take you deep in to the dark realm of convoluted expression

arcane
In general, simple is better than complex, explicit is better than implicit, and full statments are better than arcane expressions.

beneficiaries
`lambda`s are the main beneficiaries of nested function scope lookup(the E in the LEGB scope)


If neither truth method is defined, the object is vacuously considered true(though any potential implication for more meta physically inclined reader are strictly coincidental)

alas:
Alas, it's not nearly as dramatic as billed

demise:
object demise

reclaimed:
the _destructor_ method `__del__`, is run automatically when an instance's space is being reclaimed(i.e., at "garbage collection" time")

caveats:
The destructor method works as documented, but it has some well-known caveats and a few outright dark corners that make it somewhat rare to see in Python code

lingering
there may be lingering references to your objects

resolve
So what value does a function call resolve to?

glossing over
WE are intentionally glossing over these details.

trips people up
One detail about `this` variable that often trips people up is when you need to access it in a nested function.

contrived;
These examples are a bit contrived
