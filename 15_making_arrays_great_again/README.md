# Making Arrays Great Again

We have now talked about pointers, arrays, structs and dynamic memory
management. This example will bring these concepts together and show how they
can be used as a whole.

The idea is to build a *wrapper* around arrays which provides more safety. It
should prevent you from accessing the array out-of-bounds and provide some
convenience functions.

The approach will be quite *object-oriented* and is more a proof-of-concept
than a real-world solution. Of course using the wrapper yield a performance
overhead, hence doing things directly will be faster. In practise, as a C
programmer you are expected to do memory management correctly without such
helpers.

We'll reuse this example later on when we talk about modules, multiple source
files and how modules are supposed to go together. Another common example is
building a simple data-structure like a linked-list and this will be done at a
later point in time, for now I'd like to keep it simple without talking about
data-structures.

## Exercise

After you have read and understood this code, you can try and enhance this
wrapper by adding functions for dynamically growing / shrinking the array.
