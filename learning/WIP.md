Reference(X)
looks for the name X in the current local scope, then any and all enclosing functions then the current global scope, then the built-in scope, epr the LEGB rule. Enclosing classes are not searched:
class names are fetched as object attributes instead.
