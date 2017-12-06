# CO SCI 836 - Assignment 3
**Course Title:** Introduction to Data Structures<br/>
**Section:** 15681<br/>
**Instructor:** Jeff Kent<br/>
**Semester:** Fall 2017 (2017-08-28 to 2017-12-17)<br/>
**Textbook:** [Dale, Nell, et al. _C++ Plus Data Structures_. 6th ed.](http://www.jblearning.com/catalog/9781284089189/) (ISBN-13: 978-1284089189)

### Tasks
Create a custom queue container - a container which enforces first in first out
(FIFO) behaviour.

Create a program which can manage flight bookings for an airline. Use two
`Queue`s - a primary for booked passengers and a secondary for a waiting list.
Users should be able to add, remove, and list all passengers. It is only needed
to keep track of each passenger's name.

Each `Queue` is to have a capacity of 3 passengers. If the capacity of the
primary `Queue`  is reached, newly added passengers are to be added to the
secondary `Queue`. If both are full, then an error message is to be displayed
indicating this.

Passengers should be moved from the secondary `Queue` to the primary one
whenever space is made i.e. a passenger is removed from the primary `Queue`.

See the wiki for details on
[implementation requirements](https://github.com/MarkKoz/COSCI-836/wiki/Module-4-—-Queue)
and [sample outputs](https://github.com/MarkKoz/COSCI-836/wiki/Assignment-3-—-Code-&-Outputs#sample-output).

### File Structure
Put the following files into a `ZIP` file:
```
CQueue.cpp
CQueue.h
Test.cpp
```

Original instructions can be found
[here](https://www.genghiskhent.com/jak/836/assignments/836a3.html) or on the
[wiki](https://github.com/MarkKoz/COSCI-836/wiki/Assignment-3).
