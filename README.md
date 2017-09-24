# CO SCI 836 - Assignment 3
**Course Title:** Introduction to Data Structures<br/>
**Section:** 15681<br/>
**Instructor:** Jeff Kent<br/>
**Semester:** Fall 2017 (2017-08-28 to 2017-12-17)<br/>
**Textbook:** [Dale, Nell, et al. _C++ Plus Data Structures_. 6th ed.](http://www.jblearning.com/catalog/9781284089189/) (ISBN-13: 978-1284089189)

### Tasks


### Sample Outputs
##### Empty Queues
```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 3
No passengers
```

```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 2
No passengers to delete
```

##### Booking Passengers
```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 1
Enter name: Ivan
Booking Ivan on flight
```

```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 3
Booked Passengers
=================
Jeff
Mikhail
Ivan
No passengers on waiting list
```

##### Waiting List
```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 1
Enter name: Waiter
Sorry. Plane fully booked. Adding Waiter to waiting list
```

```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 3
Booked Passengers
=================
Jeff
Mikhail
Ivan
Waiting list
=================
Waiter
```

##### Adding from Waiting List
```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 2
Removing Jeff from booked passengers
Adding Waiter from waiting list
```

```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 3
Booked Passengers
=================
Mikhail
Ivan
Waiter
No passengers on waiting list
```

##### Full Queues
```
Menu
========
1. Add Passenger
2. Delete Passenger
3. Show Passengers
4. Exit
Enter choice: 1
Sorry. Plane and waiting list fully booked. Try later
```

### Queue Class
All class members must be `private` unless they need to be `public`.

##### Fields
| Declaration | Description                                                                 |
|-------------|-----------------------------------------------------------------------------|
| `int front` | Index _before_ the first element of `c` that holds a value.                 |
| `int back`  | Index of the last element of `c` that holds a value.                        |
| `T c`       | The underlying container - holds elements being enqueued.                     |

##### Methods
| Declaration    | Description                                                                                             |
|----------------|---------------------------------------------------------------------------------------------------------|
| `void Queue()` | Constructs an empty queue. Initializes `front` and `back` and, optionally, initialises elements in `c`. |
| `void push(T)` | Inserts an element at the end.                                                                          |
| `void pop()`   | Removes the first element.                                                                              |
| `T getFront()` | Accesses the first element.                                                                             |
| `bool empty()` | Returns `true` if the queue is empty i.e. no element in `c` holds a value; returns `false` otherwise.   |
| `bool full()`  | Returns `true` if the queue is full i.e. every element in `c` holds a value; returns `false` otherwise. |

### Test.cpp
```cpp
#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

enum choice {
    BOOKED,
    WAITING
};

const int LINES = 2;

int showMenu();

void addPassenger(CQueue*);

void deletePassenger(CQueue*);

void showPassengers(CQueue*);

int main() {
    CQueue qPassengers[LINES];
    int x;
    do {
        x = showMenu();
        switch (x) {
            case 1:
                addPassenger(qPassengers);
                break;
            case 2:
                deletePassenger(qPassengers);
                break;
            case 3:
                showPassengers(qPassengers);
                break;
        }
    } while (x != 4);

    return 0;
}

int showMenu() {
    int select;

    cout << "Menu\n";
    cout << "========\n";
    cout << "1. Add Passenger\n";
    cout << "2. Delete Passenger\n";
    cout << "3. Show Passengers\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> select;

    return select;
}

// To do: implement addPassenger, deletePassenger and showPassengers
```

### File Structure
Put the following files into a `ZIP` file:
```
Queue.cpp
Queue.hpp
Test.cpp
```

Original instructions can be found
[here](https://www.genghiskhent.com/jak/836/assignments/836a3.html) or on the
wiki.
