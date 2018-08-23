
#include <QApplication>
#include <TestAppLib/MainWindow.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	evergreen::MainWindow window{ "TestApp" };
	window.show();
	return app.exec();
}