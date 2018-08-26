#pragma once

#include <DataSource/IDataSource.h>

#include "DataSourceParameters.h"

namespace evergreen
{

class DataSource final
	: public IDataSource
{
public: // IDataSource
	virtual ~DataSource() override;

public:
	explicit DataSource(DataSourceParameters params) noexcept;

private:
	void load_datasource_info();
private:
	const DataSourceParameters params_;
};

} // namespace evergreen