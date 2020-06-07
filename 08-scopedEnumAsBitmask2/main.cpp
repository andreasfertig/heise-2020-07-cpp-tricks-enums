// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdint>
#include <type_traits>

enum class Permission : uint8_t
{
    Read = 0,
    Write,
    Execute,
};
template<typename T>
constexpr std::enable_if_t<std::is_enum_v<T>, T> operator|(T       lhs,
                                                           const T rhs)
{
    using underlying = std::underlying_type_t<T>;

    return static_cast<T>(static_cast<underlying>(lhs) |
                          static_cast<underlying>(rhs));
}

struct SomeOtherType
{
};

Permission readAndWrite{Permission::Read | Permission::Write};

SomeOtherType x;
SomeOtherType y;
//    SomeOtherType z = x | y;

enum class Direction : uint8_t
{
    Left = 0,
    Right,
    Forward,
    Backwards,
};

Direction drivingDirection{Direction::Left | Direction::Right};
int main() {}
