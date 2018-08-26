#pragma once
#include <memory>

namespace evergreen
{

// Типы
class IDataSource;
struct DataSourceParameters;

// Указатели
typedef std::shared_ptr<IDataSource> IDataSourcePtr;
typedef std::shared_ptr<DataSourceParameters> DataSourceParametersPtr;

} // namespace evergreen
