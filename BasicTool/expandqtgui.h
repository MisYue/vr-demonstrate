#ifndef EXPANDQTGUI_H
#define EXPANDQTGUI_H

#include "basictool_global.h"
#include <QtWidgets>

class BASICTOOL_EXPORT ExpandQtGui
{
public:
	ExpandQtGui();
	~ExpandQtGui();
	static void critical(QWidget* parent, const QString& title, const QString& text);
	static void information(QWidget* parent, const QString& title, const QString& text);
	static void warning(QWidget* parent, const QString& title, const QString& text);
	// ��������
	static QAction* createAction(const QString & text, const QObject * receiver, const char* method, QObject * parent=0, const QString & icon=QString());
	// ������ť
	static QPushButton* createPushButton(const QString & text, const QWidget * receiver, const char* method, QWidget * parent=0, const QString & icon=QString());
	// ѡ��Ի���
	static void selectDlg(const QStringList& items, QStringList& selected, QWidget* parent);
private:

};

#endif // EXPANDQTGUI_H
