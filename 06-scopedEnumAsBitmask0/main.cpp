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
Permission operator|(Permission lhs, const Permission rhs)
{
    using underlying = std::underlying_type_t<Permission>;

    return static_cast<Permission>(static_cast<underlying>(lhs) |
                                   static_cast<underlying>(rhs));
}

Permission readAndWrite{Permission::Read | Permission::Write};
int main() {}
