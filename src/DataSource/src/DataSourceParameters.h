#pragma once

#include <string>

namespace evergreen
{
	
struct DataSourceParameters final
{
	DataSourceParameters() = delete;

	//! Входной файл с данными
	const std::string source_filename;
	//! todo тут появятся еще параметры
};

} // namespace evergrenn