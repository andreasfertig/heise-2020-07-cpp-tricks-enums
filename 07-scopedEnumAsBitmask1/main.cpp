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
T operator|(T lhs, const T rhs)
{
    static_assert(std::is_enum_v<T>, "Only enums are supported");

    using underlying = std::underlying_type_t<T>;

    return static_cast<T>(static_cast<underlying>(lhs) |
                          static_cast<underlying>(rhs));
}

int main()
{
    Permission readAndWrite{Permission::Read | Permission::Write};
}