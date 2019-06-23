# Mini Printf
This function is a printf like in one file according to the EPITECH's coding style

### Epitech Coding Style
2023

## Usage
`minif(str, ...);`

## Example
``` C
#include "minif.h"

int main(void)
{
    /* The function will return 20 as a size_t value */
    minif("Here is an int : %d\n", 42);
    return (0);
}
```

## Flags
- `%c` print `char` type vars
- `%i` print `int` type vars *and smaller values*
- `%d` print `int` type vars *and smaller values*
- `%u` print `unsigned int` type vars *and smaller values*
- `%s` print `char *` type vars *(print "(nul)" if pointer is NULL)*
- `%%` print `%` char

## Max Values
| Type               | Min value            | Max value            |
|--------------------|:--------------------:|:--------------------:|
| char               | -128                 | 127                  |
| unsigned char      | 0                    | 256                  |
| int                | -2147483648          | 2147483647           |
| unsigned int       | 0                    | 4294967295           |
| long long          | -9223372036854775808 | 9223372036854775807  |
| unsigned long long | 0                    | 18446744073709551615 |

## Author
- [theo.mazars@epitech.eu](https://github.com/theo-mazars)
- [timothee.couble@epitech.eu](https://github.com/Faroito)


*You can also star this repo to support my work*