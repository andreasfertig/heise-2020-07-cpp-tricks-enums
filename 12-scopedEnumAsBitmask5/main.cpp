// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdint>
#include <type_traits>
template<typename T>
std::enable_if_t<
    std::conjunction_v<std::is_enum<T>,
                       std::is_same<bool,
                                    decltype(enable_bitmask_operator_or(
                                        std::declval<T>()))>>,
    T>
operator|(T lhs, const T rhs)
{
    using underlying = std::underlying_type_t<T>;

    return static_cast<T>(static_cast<underlying>(lhs) |
                          static_cast<underlying>(rhs));
}

namespace Filesystem {
    enum class Permission : uint8_t
    {
        Read = 0,
        Write,
        Execute,
    };

    constexpr bool enable_bitmask_operator_or(Permission&&);
}  // namespace Filesystem

int main()
{
    using Filesystem::Permission;
    Permission readAndWrite{Permission::Read | Permission::Write};
}