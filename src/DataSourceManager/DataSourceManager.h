#pragma once

#include <Types.h>

#include <vector>


namespace evergreen
{

//! Управляет временем жизни источников данных
class DataSourceManager
{
public:
	struct DataSourceItem final
	{
		//! Источник данных
		IDataSourcePtr data_source;
		//! todo: Пайплайн загрузки

		DataSourceItem() = delete;
	};

public:
	DataSourceManager() = default;
	~DataSourceManager() = default;

	void add_data_source(const IDataSourcePtr & data_source);
	void remove_data_source(const IDataSourcePtr & data_source);

private:
	using DataSourceContainer = std::vector<DataSourceItem>;

private:
	DataSourceContainer data_source_items_;
};

} // namespace evergreen