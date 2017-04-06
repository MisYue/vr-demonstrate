#include "MainCtrlWnd.h"
#include <BasicTool/expandqtcore.h>
#include <QtWidgets>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
#if QT_VERSION < 0x050000
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
#endif
	QTranslator translator;
	translator.load("qt_zh_CN.qm");
	a.installTranslator(&translator);
	QFile file(":/root/css");
	file.open(QFile::ReadOnly);
	QString styleSheet = ExpandQtCore::fromGBK(file.readAll().data());
	a.setStyleSheet(styleSheet);
	MainCtrlWnd w;
	w.setGeometry(200, 200, 800, 600);
	w.show();
	return a.exec();
}
