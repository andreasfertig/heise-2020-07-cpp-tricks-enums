// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdint>
#include <iostream>
#include <type_traits>

enum class Color : uint8_t
{
    Red,
    Green,
    Blue
};
template<typename T>
auto GetUnderlyingValue(const T& value)
{
    static_assert(std::is_enum<T>::value, "Only enums allowed as T");

    using underlying = std::underlying_type_t<T>;

    return static_cast<underlying>(value);
}

int main()
{
    Color cl{Color::Blue};

    std::cout << "Enum value: " << +GetUnderlyingValue(cl) << '\n';
}