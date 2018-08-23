#pragma once

#include <string>

#include <QMainWindow>

namespace evergreen
{

class MainWindow final
	: public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(const std::string & title);
	virtual ~MainWindow();
private:
	const std::string window_title_;
};

} // namespace evergreen
