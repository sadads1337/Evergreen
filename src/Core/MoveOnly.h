#pragma once

#include <type_traits>

namespace evergreen
{

template<typename Type>
typename std::remove_reference<Type>::type && move_only(Type && value);

} // namespace evergreen

#include "MoveOnly.inl"
