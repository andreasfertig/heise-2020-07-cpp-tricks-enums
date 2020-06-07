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
struct enable_bitmask_operator_or : std::false_type
{
};

template<typename T>
constexpr std::enable_if_t<
    std::conjunction_v<std::is_enum<T>, enable_bitmask_operator_or<T>>,
    T>
operator|(T lhs, const T rhs)
{
    using underlying = std::underlying_type_t<T>;

    return static_cast<T>(static_cast<underlying>(lhs) |
                          static_cast<underlying>(rhs));
}

template<>
struct enable_bitmask_operator_or<Permission>
{
    static constexpr bool value = true;
};

int main()
{
    Permission readAndWrite{Permission::Read | Permission::Write};
}