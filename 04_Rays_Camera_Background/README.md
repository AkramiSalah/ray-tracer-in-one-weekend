# Chapter 4

## The realisation about templates:
i was starting to get annoyed by the need to go `template<typename T>` for everything even tho T is chosen once and thats it.
after thinking about it i realised..
i was taught how to use a hammer, so everything looked like a nail.
in reality templates were a bad fit for me.

ill remind you, these are the justifications i made for why i chose templating in chapter 3:

### templating:
- the author said to choose between float and double based on taste. i dont have any taste, i can barely program!
so i made it templated instead!

- this way i was also forced to delve deeper into meta programming, which i felt that the intro to Sys. prog. i took didnt really emphasize enough.

- also in the future i (maybe) want to dabble in my own custom numeric types, and itll be interesting to benchmark them using raytracing


all of these reasons except for the middle one are solved by `using Float = double` for now and changing it in the future to whatever type i wanted..
and when it comes to the middle reason, just going template<typename T> before everything isnt really teaching me anything anyway!

which is why i refactored my code to not use templates anymore.


## Design choices made:

### renderer -> camera -> viewport model:
i went for a composition model instead of following the author and dumping all the code in the main loop.
as a result i feel like my code is clearer, and more understandable. if in the future i want to implement rays in another way i can and nothing will brake.
if i want my camera to have the ability to move and not stay fixed (as in moving from picture rendering to video rendering) i can do that.
it also feels natural.

### the downsides:
* more code
* more files
* more boilerplate


## the key takeaway:
it is not the first time ive made this mistake.
i remember receiving simple python assignment that reads a logfile and changes the database according to the log, as in replay the log.
as a result i started working on an ORM, for abesloutley no reason more than that i wanted my main to look clean,
i wanted all the checks to be abstracted away the the type ctors,
so baiscally i created a strong typeing system inside python FOR ABSELOUTLEY NO REASON AT ALL!!
why did i do that?
because i thought itd be clean, and because i could.

it is good to be able to do that, but its exremly wasteful to do that when its not needed.
this is a huge problem i struggle with.
i want my code to be clean, i want to show off what i can do.
so i end up wasting so much time when in reality i could have made it simple, less clean yes, but it would work anyway, and a competent programmer would understand it in the same amount of time or maybe less.
so i end up not only not achieving my goal, but wasting time.

i truely wonder, maybe this is what im doing here, am i repeating the same mistakes?
maybe i should just follow the author and dump it all in my main.

but maybe this doesnt matter,
the goal was to read the book, follow along, but try to make better design choices.

# Possible TODOs:
[] answer the question: was this a waste of time? should i have dumped all the code in the main like the author? am i over engineering for no reason again?

[] leverage parallel computation of pixel colors in the render fucntion to squeeze out more performance

[] find out how to run the parallalized render function on the GPU instead of the CPU (without using OPENGL and its shaders.)

# Observations:

out of order exec might be useful in the render function,
but the ppm format requires sequential writing, so either find a format where parallel writing is easy
or write to a pixel array/matrix/vector in parallel and then write to the file sequentially.