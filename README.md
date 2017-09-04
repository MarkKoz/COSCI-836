# CO SCI 836 - Assignment 2
**Course Title:** Introduction to Data Structures<br/>
**Section:** 15681<br/>
**Instructor:** Jeff Kent<br/>
**Semester:** Fall 2017 (2017-08-28 to 2017-12-17)<br/>
**Textbook:** [Dale, Nell, et al. _C++ Plus Data Structures_. 6th ed.](http://www.jblearning.com/catalog/9781284089189/) (ISBN-13: 978-1284089189)

### Tasks
Prompt the user to input a string of 20 characters at most. No input validation
is required. Validate the string to be a valid expression with the use of a
`Stack`. Once the whole expression is checked, notify the user of the validity
of the expression.

An expression is valid if:
* Characters only consist of `[`, `]`, `(`, `)`, `{`, and `}`.
* The right-most not-compared left character completes the pair for each right
character.

### Sample Outputs
##### Valid Expressions
```
Enter an expression: []{}()
It's a valid expression
```

```
Enter an expression: ()[{}]
It's a valid expression
```

##### Invalid Expression
```
Enter an expression: [({)}]
It's NOT a valid expression
```

### Stack Class
All class members must be `private` unless they need to be `public`.

##### Fields
| Declaration          | Description                                                 |
|----------------------|-------------------------------------------------------------|
| `int t`              | Index of last element of `container` that holds a value.    |
| `char container[21]` | The underlying container - holds the elements being pushed. |

##### Methods
| Declaration             | Description                                       |
|-------------------------|---------------------------------------------------|
| `void push(const char)` | Inserts an element at the top.                    |
| `void pop()`            | Removes the top element.                          |
| `char top()`            | Accesses the top element.                         |
| `bool empty()`          | Checks whether the underlying container is empty. |
| `bool full()`           | Checks whether the underlying container is full.  |

### Test.cpp
```cpp
#include <cstring>
#include <iostream>

#include "Stack.hpp"

bool isValid(Stack& stack, char* exp);

int main(void) {
    char exp[21];
    Stack stack;

    std::cout << "Enter an expression: ";
    std::cin >> expression;

    if (isValid(stack, exp)) {
        std::cout << "\nIt's a valid expression.";
    } else {
        std::cout << "\nIt's NOT a valid expression.";
    }
}

bool isValid(Stack& stack, char* exp) { }
```

### File Structure
Put the following files into a `ZIP` file:
```
Stack.cpp
Stack.hpp
Test.cpp
```

Original instructions can be found
[here](https://www.genghiskhent.com/jak/836/assignments/836a2.html) or on the
wiki.
