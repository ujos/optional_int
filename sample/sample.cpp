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
    std::cout << "sizeof(std::optional<int>) = " << sizeof(std::optional<int>) << "\n";
    std::cout << "sizeof(std::optional_int) = " << sizeof(std::optional_int<int, -1>) << "\n";

    foo(1);
    foo(std::nullopt);
}
