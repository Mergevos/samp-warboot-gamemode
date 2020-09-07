# samp-warboot

[![sampctl](https://img.shields.io/badge/sampctl-samp--warboot-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-warboot)

Gamemode written by modern standards of Pawn language.

## Installation

Use: 
```git
git clone Mergevos/samp-warboot-gamemode
```

Simply run gamemode in three lines:
```bash
sampctl package ensure
sampctl package build
sampctl package run
```

# How to contribute.
 
## Variable Declaration
### Global
```c
// Global static variables have to be lower snake case.
// e.g
static 
    this_Variable;
// While new variables have to be upper snake case.
new 
    This_New;

```
### Local
```c
// We only accept this way of declaration

new 
    First,
    Second,
    Third;
```

### Functions

Functions must have prefix of module
All functions must use void tag if function doesn't return anything

```c
database_Connect() //if used as static 
Database_Connect() //if not
```
