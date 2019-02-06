page882
In our case, we can use this technique to invoke the default
`giveRaise`in Person, even though it's been redefined at the
`Manager` level. In some sense, we must call through `Person`
this way, because a `self.giveRaise()` would resolve again to
`Manager.giveRaise`, and so on and so forth recursively until
available memory is exhausted.
