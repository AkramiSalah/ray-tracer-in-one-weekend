# Chapter 3

## Overview
a templated vec3<T> ADT for storing and manipulating 3 dimensional data.

## Justifications for choices made:
### templating:
- the author said to choose between float and double based on taste. i dont have any taste, i can barely program!
so i made it templated instead!

- this way i was also forced to delve deeper into meta programming, which i felt that the intro to Sys. prog. i took didnt really emphasize enough.

- also in the future i (maybe) want to dabble in my own custom numeric types, and itll be interesting to benchmark them using raytracing

### zero encapsulation:
the author opted for all public fields, so i copied that and then went
looking for a reason as to why. 

at first i thought private fields with getters would've caused poorer performance but they would have been inlined anyway, so thats not the reason.

the real reason: encapsulation protects invariants, and vec3
has none.
any combination of three T's  is a valid vector, so there's
nothing to protect. 


### little to no validation of argument/data:
asserts only. `vec3` is an internal primitive — we control every call site,
so assertions during development are sufficient. building with `-DNDEBUG`
eliminates them in release builds entirely.

### the hidden friend idiom
i stumbled on this while trying to avoid writing `template<typename T>` 
before every externally defined function. turns out it also has real benefits
as a side effect: operators only resolve for `vec3` types via ADL, and they
don't pollute the global namespace until actually needed.
