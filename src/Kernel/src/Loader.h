#pragma once

namespace evergreen
{

//! Загрузчик, точка входа в поток загрузки
class Loader final
{
public:
	Loader() = default;
	~Loader() = default;

	void run() noexcept;
};

} // namespace evergreen