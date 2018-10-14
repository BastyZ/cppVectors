# cppVectors
First homework of GPU computing course at fcfm, it's like a fast tutorial/training on c++

__c++17__ is used for this project.

## Running the homework: 
because I don't know how to run cpp code from a terminal, I'll recommend to open the project on CLion and run
it from there as I did.
I'm hope that in a short future I'll know more details, but it's my first time with cpp
 and CLion made it a lot easier 
on Linux.

## Comments
Tests run as a function on the main, anyway, in a future will be good to store it on a place where
a CI app were capable to run them. In the meantime, enjoy all the assert functions side-by-side.

There are 3 test, two for part 1 and one for part 2, for part 2 evaluates creating
 and adding things to the classes, with asserts where needed.

Templates are used as requested, idk if it's a good practice or not, so if you know a syntax checker or a
guide/documentation plase tell me.

Given that nothing is created with new, there is no destroy functions stablished, but you should be carefull
and avoid to fill your computer stack.

## Final thoughs

Working with c++ was a lot more fun that doing it with c, objects worked normally as in any modern language.
On the bad side I think I applied a lot of bad practices without knowing, there are some things la Clang-Tidy
that I do not undestand at the moment, and of course can be a problem of readability on the future, 
but I hope I'll be better with c++ with the days.

### About DCEL structure

With all the documentation provided I wasn't capable of undertanding the way of creating the mesh with
given vertexes, I strongly suppose that you have to know at least all the vertexes to start creating HalfEdges
but the algorithm to add HalfEdges and faces with pairs and that it's not clear to me yet, so 
in the test you can se I manually added the relations as all the objects needed were available.
