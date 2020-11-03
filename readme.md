## Purpose

The standard `std::optional` class comes with overhead.
Together with the payload it allocates memory for the bool variable to store the 
state: initialized or not. Therefore, the effective size of the `std::optional<T>`
variable is `sizeof(T) + sizeof(bool) + padding`. For example the size of
`std::optional<int>` is 8 bytes.

Given library implements the `std::optional` interface for cases when
memory layout is crusial and some magic value can be used to signal 
a NULL state. That helps eliminate the need of bool variable and removes padding.

## Sample

```cpp
#include <opt_value.h>
#include <iostream>

void foo(std::optional_int<int, -1> value)
{
    if(value) 
        std::cout << "value = " << *value << "\n";
    else
        std::cout << "value = NULL\n";
}

int main() {
    foo(1);
    foo(std::nullopt);
}

```
