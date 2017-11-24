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

See the [wiki](https://github.com/MarkKoz/COSCI-836/wiki/Module-3-—-Stack) for
details on implementation requirements.

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

### File Structure
Put the following files into a `ZIP` file:
```
CStack.cpp
CStack.h
Test.cpp
```

Original instructions can be found
[here](https://www.genghiskhent.com/jak/836/assignments/836a2.html) or on the
[wiki](https://github.com/MarkKoz/COSCI-836/wiki/Assignment-2).
