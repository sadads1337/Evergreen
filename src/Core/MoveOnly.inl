#include "MoveOnly.h"

#include <iso646.h>

namespace evergreen
{

template<typename Type>
inline typename std::remove_reference<Type>::type && move_only(Type && value)
{
	static_assert(not std::is_const<typename std::remove_reference<Type>::type>::value, "value is const");
	return std::move(value);
}

} // namespace evergreen
