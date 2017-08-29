# CO SCI 836 - Assignment 1
**Course Title:** Introduction to Data Structures<br/>
**Section:** 15681<br/>
**Instructor:** Jeff Kent<br/>
**Semester:** Fall 2017 (2017-08-28 to 2017-12-17)<br/>
**Textbook:** [Dale, Nell, et al. _C++ Plus Data Structures_. 6th ed.](http://www.jblearning.com/catalog/9781284089189/) (ISBN-13: 978-1284089189)

### Tasks
The user is prompted to enter a month, day and year. If the date is valid, then the `setDate` member function assigns the month, day, and year inputs to the `Date` instance. If the date is not valid, then the values `9`, `2`, and `2008` are assigned respectively to the `month`, `day`, and year member variables of the `Date` instance. The `printDate` function then outputs the `Date` instance in the format `m/d/yyy`.

A date is valid if:
* The month is between `1` and `12`.
* The day is between `1` and `31`.
    * It is not required to account for some months having `28` to `30` days.
* The year is between `1900` and `2008`.

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
| Declaration | Description                                                     |
|-------------|-----------------------------------------------------------------|
| `int month` | Number corresponding to month of year. (i.e. `1` to `12`)       |
| `int day`   | Number corresponding to day of month. (i.e. `1` to `28` to 31`) |
| `int year`  | Number corresponding to year.                                   |

##### Methods
| Declaration                   | Description                                                                                                                                    |
|-------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| `void setDate(int, int, int)` | Assigns the value of each parameter to the month, date and year member variables respectively unless the date is not valid (see next section). |
| `void printDate()`            | Outputs the date in the format `m/d/yyy`, such as `9/2/2008`.                                                                               |

### Entry Point Function
Do not modify the code except for replacing the comments with their respective method calls.

```cpp
#include <iostream>
#include "Date.h"

using namespace std;

int main() {
    Date d1;
    int m, d, y;

    cout << "Enter month, day and year separated by spaces: ";
    cin >> m >> d >> y;

    // call setDate
    // call printDate

    return 0;
}
```

### File Structure
Put the following files into a `ZIP` file:
```
Date.cpp
Date.h
Test.cpp
```

Original instructions can be found [here](https://www.genghiskhent.com/jak/836/assignments/836a1.html) or in `README.html`.
