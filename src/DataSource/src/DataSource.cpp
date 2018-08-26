#include "DataSource.h"

#include <Core/MoveOnly.h>
#include <Core/RuntimeError.h>
#include <iostream>

namespace evergreen
{

inline namespace
{

class DataSourceRuntimeError final
	: public RuntimeError
{
public:
	explicit DataSourceRuntimeError(const std::string & message)
		: RuntimeError(message)
	{
	}

	virtual ~DataSourceRuntimeError() override = default;
};

} // inline namespace

DataSource::~DataSource()
{
}

DataSource::DataSource(DataSourceParameters params) noexcept
	: params_(move_only(params))
{
	try
	{
		load_datasource_info();
	}
	catch(DataSourceRuntimeError & error)
	{
		// todo custom logging on qt
		std::cerr << error.what() << std::endl;
	}
}

void DataSource::load_datasource_info()
{
}

IDataSourcePtr create_data_source(const DataSourceParameters & params)
{
	return std::make_shared<DataSource>(params);
}

} // namespace evergreen