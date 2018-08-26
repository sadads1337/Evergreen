#pragma once

#include <memory>

#include <Types.h>

namespace evergreen
{

struct DataSourceParameters;

class IDataSource
{
public:
	virtual ~IDataSource() = default;
};

//! Читаем и создаем datasource из файла
//! \param params параметры с которыми конструируем datasource
IDataSourcePtr create_data_source(const DataSourceParameters & params);

} // namespace evergreen