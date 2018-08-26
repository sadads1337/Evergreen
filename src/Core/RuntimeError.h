#pragma once

#include <string>

namespace evergreen
{

class RuntimeError
	: public std::runtime_error
{
public:
	explicit RuntimeError(const std::string & message);
	virtual ~RuntimeError() = 0;
};

} // namespace evergreen