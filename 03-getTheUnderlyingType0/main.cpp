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

int main()
{
    Color cl{Color::Blue};
    using underlying = std::underlying_type_t<Color>;

    std::cout << "Enum value: " << +static_cast<underlying>(cl) << '\n';
}