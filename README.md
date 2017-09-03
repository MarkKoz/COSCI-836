# CO SCI 836 - Assignment 2
**Course Title:** Introduction to Data Structures<br/>
**Section:** 15681<br/>
**Instructor:** Jeff Kent<br/>
**Semester:** Fall 2017 (2017-08-28 to 2017-12-17)<br/>
**Textbook:** [Dale, Nell, et al. _C++ Plus Data Structures_. 6th ed.](http://www.jblearning.com/catalog/9781284089189/) (ISBN-13: 978-1284089189)

### Tasks
Prompt the user to input a string of 20 characters at most. No input validation
is required. Validate the string to be a valid expression, pushing one valid
character at a time onto a `CStack`. Once the whole expression is checked,
notify the user of the validity of the expression.

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

### CStack Class
All class members must be `private` unless they need to be `public`.

##### Fields
| Declaration     | Description                                                         |
|-----------------|---------------------------------------------------------------------|
| `int topVal`    | Index of the last element of array that holds a value in the stack. |
| `char data[21]` | Holds values being pushed onto the stack.                           |

##### Methods
| Declaration             | Description                                                                                                   |
|-------------------------|---------------------------------------------------------------------------------------------------------------|
| `void push(const char)` | Adds a character to the top of the stack                                                                      |
| `void pop()`            | Removes the top-most item from the stack.                                                                     |
| `char top()`            | Returns the value of `topVal`.                                                                                |
| `bool isEmpty()`        | Returns `true` if the stack is empty i.e. no element in the array holds a value; returns `false` otherwise.   |
| `bool isFull()`         | Returns `true` if the stack is full i.e. every element in the array holds a value; returns `false` otherwise. |

### Entry Point Function
```cpp
#include <cstring>
#include <iostream>

#include "CStack.h"

using namespace std;

bool isValidExpression(CStack&, char*);

int main(void) {
    char expression[21];

    cout << "Enter an expression: ";
    cin >> expression;

    CStack stack1;

    if (isValidExpression(stack1, expression)) {
        cout << "\nIt's a valid expression";
    } else {
        cout << "\nIt's NOT a valid expression";
    }

    return 0;
}

bool isValidExpression (CStack& stackA, char* strExp) {

}
```

### File Structure
Put the following files into a `ZIP` file:
```
CStack.cpp
CStack.h
Test.cpp
```

Original instructions can be found [here](https://www.genghiskhent.com/jak/836/assignments/836a2.html) or in `README.html` and `README2.html`.
