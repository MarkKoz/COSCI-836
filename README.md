# CO SCI 836 - Assignment 1
**Course Title:** Introduction to Data Structures<br/>
**Section:** 15681<br/>
**Instructor:** Jeff Kent<br/>
**Semester:** Fall 2017 (2017-08-28 to 2017-12-17)<br/>
**Textbook:** [Dale, Nell, et al. _C++ Plus Data Structures_. 6th ed.](http://www.jblearning.com/catalog/9781284089189/) (ISBN-13: 978-1284089189)

### Tasks
The user is prompted to enter a month, day and year. If the date is valid, then
the `set` member function assigns the month, day, and year inputs to the `Date`
instance. If the date is not valid, then the values `9`, `2`, and `2008` are
assigned respectively to the `month`, `day`, and year member variables of the
`Date` instance. The `print` function then outputs the `Date` instance in the
format `m/d/yyy`.

A date is valid if:
* The month is in the range \[1,12].
* The day is in the range \[1,31]
    * It is not required to account for some months having `28` to `30` days.
* The year is in the range \[1900,2008].

### Sample Outputs
##### Valid Date
```
Enter month, day and year separated by spaces: 9 17 1921
9/17/1921
```

##### Invalid Date
```
Enter month, day and year separated by spaces: 13 1 2000
9/2/2008
```

### Date Class
All class members must be `private` unless they need to be `public`.

##### Fields
| Declaration | Description                            |
|-------------|----------------------------------------|
| `int month` | Number corresponding to month of year. |
| `int day`   | Number corresponding to day of month.  |
| `int year`  | Number corresponding to year.          |

##### Methods
| Declaration               | Description                                                                                                                                    |
|---------------------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| `void set(int, int, int)` | Assigns the value of each parameter to the month, date and year member variables respectively unless the date is not valid (see next section). |
| `void print()`            | Outputs the date in the format `m/d/yyy`, such as `9/2/2008`.                                                                                  |

### Test.cpp
Do not modify the code except for replacing the comments with their respective
method calls.

```cpp
#include <iostream>

#include "Date.hpp"

int main() {
    Date d1;
    int m, d, y;

    std::cout << "Enter month, day and year separated by spaces: ";
    std::cin >> m >> d >> y;

    // Call Date.set.
    // Call Date.print.
}
```

### File Structure
Put the following files into a `ZIP` file:
```
Date.cpp
Date.hpp
Test.cpp
```

Original instructions can be found
[here](https://www.genghiskhent.com/jak/836/assignments/836a1.html) or on the
wiki.
