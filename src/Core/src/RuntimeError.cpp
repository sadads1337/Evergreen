#include <Core/RuntimeError.h>

namespace evergreen
{

RuntimeError::RuntimeError(const std::string & message)
	: runtime_error(message)
{
}

} // namespace evergreen