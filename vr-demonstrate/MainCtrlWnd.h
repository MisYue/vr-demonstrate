#pragma once
#include <QtWidgets>

class Warhead;
class TargetRange;
namespace osgViewer { class Viewer; }
namespace osg 
{
	class Group; 
	class MatrixTransform;
}

class MainCtrlWnd :
	public QMainWindow
{
	Q_OBJECT
public:
	MainCtrlWnd(void);
	~MainCtrlWnd(void);
	// º∆À„
	void Count(void);
public slots:
	void on_warhead_changed(int index);
	void on_range_changed(int index);
protected:
	QMap<QString, Warhead*> name_2_warhead_;
	QMap<QString, TargetRange*> name_2_range_;
	osgViewer::Viewer* viewer_;
	osg::MatrixTransform* warhead_group_;
	osg::MatrixTransform* range_group_;

	QString config_file_;
	QComboBox* warhead_combobox_;
	QComboBox* range_combobox_;

	void ReadConfig();
	void InitDockWarhead();
	void InitDockRange();
	void DrawWarhead();
	void DrawRange();

};

