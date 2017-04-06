#include "MainCtrlWnd.h"
#include "ViewerWidget.h"
#include "osg_tool.h"
#include "compass_hud.h"
#include <EntityData/entitydata.h>
#include <BasicTool/expandqtcore.h>
#include <osgViewer/viewer>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <QtXml>

MainCtrlWnd::MainCtrlWnd(void)
	: config_file_("./config.xml")
{
	setWindowTitle(ExpandQtCore::fromGBK("战斗部侵彻分析"));
	ViewerWidget* viewer_wgt = new ViewerWidget((osg::Node*)0);
	viewer_ = dynamic_cast<osgViewer::Viewer*>(viewer_wgt->getViewer());
	osg::Group* scene = new osg::Group;
	viewer_->setSceneData(scene);
	warhead_group_ = new osg::MatrixTransform;
	warhead_group_->setMatrix(osg::Matrix::scale(0.001, 0.001, 0.001)*osg::Matrix::translate(-10, 0, 2));
	warhead_group_->getOrCreateStateSet()->setMode(GL_RESCALE_NORMAL, osg::StateAttribute::ON);
	range_group_ = new osg::MatrixTransform;
	range_group_->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(90.0), osg::Vec3(1, 0, 0))*osg::Matrix::scale(0.01, 0.01, 0.01));
	scene->addChild(warhead_group_);
	scene->addChild(range_group_);
	scene->addChild(MakeGrid(kXY, 20, 0.5));

	CompassHud* hud = new CompassHud(viewer_);
	osg::Camera* camera = hud->CreateAxisHud(0, 0, 200, 200);
	scene->addChild(camera);
	setCentralWidget(viewer_wgt);
	ReadConfig();
	InitDockWarhead();
	InitDockRange();
}


MainCtrlWnd::~MainCtrlWnd(void)
{
	qDeleteAll(name_2_warhead_);
	qDeleteAll(name_2_range_);
}


// 计算
void MainCtrlWnd::Count(void)
{
	// 计算弹道线
	// 求弹道线与靶板交点
	// 求爆炸时间
	// 对有交点的靶板求侵彻剩余速度和深度
}
void MainCtrlWnd::on_warhead_changed(int index)
{
	if(-1 != index)
	{
		Warhead* warhead = name_2_warhead_.value(warhead_combobox_->currentText(), 0);
		Q_ASSERT(warhead);
		warhead_group_->removeChildren(0, warhead_group_->getNumChildren());
		osg::Node* node = osgDB::readNodeFile(warhead->get_model_file().toStdString());
		warhead_group_->addChild(node);
	}

}
void MainCtrlWnd::on_range_changed(int index)
{
	if(-1 != index)
	{

		TargetRange* range = name_2_range_.value(range_combobox_->currentText(), 0);
		Q_ASSERT(range);
		osg::Node* node = osgDB::readNodeFile(range->get_model_file().toStdString());
		range_group_->addChild(node);
		//osg::Vec2 size = range->get_size();
		//double x = 0;
		//for(int i=0, n=range->GetNumCards(); i<n; ++i)
		//{
		//	TargetCard* card = range->GetCard(i);
		//	x += card->space + size[0]/2;
		//	osg::Box* box = 
		//	card->xyz = osg::Vec3();
		//	card->size = osg::Vec3(size, card->mt/1000.0);

		//}
	}

}
TreeParamItem* CreateParamItem(QDomElement& element, TreeParamItem* parent)
{
	QString name = element.attribute("name");
	QString mean = element.attribute("mean");
	QString value = element.attribute("value");
	bool editable = element.attribute("editable", "true").toLower() == "true";
	QString edit_hints = element.attribute("edit_hints");
	TreeParamItem* param_item = new TreeParamItem;
	param_item->node.name = name;
	param_item->node.mean = mean;
	param_item->node.value = value;
	if(parent)
	{
		editable = editable && parent->node.editable;
		if(edit_hints.isEmpty())
			edit_hints = parent->node.edit_hints_; 
		parent->children.append(param_item);
		param_item->parent = parent;
	}
	param_item->node.edit_hints_ = edit_hints;
	param_item->node.editable = editable;

	for(QDomElement child_element = element.firstChildElement("property");
		!child_element.isNull();
		child_element = child_element.nextSiblingElement("property"))
	{
		CreateParamItem(child_element, param_item);
	}
	return param_item;
}
QWidget* CreateWarheadParamWgt(TreeParamItem* param_item)
{
	QWidget* wgt = 0;
	if(param_item->children.size() == 0)
	{
		wgt = new QWidget;
		QHBoxLayout* layout = new QHBoxLayout(wgt);
		layout->setContentsMargins(0, 0, 0, 0);
		QLabel* label = new QLabel(param_item->node.mean);
		label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		QLineEdit* editer = new QLineEdit(param_item->node.value);
		editer->setEnabled(false);
		layout->addWidget(label);
		layout->addWidget(editer);
	}
	else
	{
		if(param_item->parent)
			wgt = new QGroupBox(param_item->node.mean);
		else
			wgt = new QWidget;
		QVBoxLayout* layout = new QVBoxLayout(wgt);
		//layout->setContentsMargins(0, 0, 0, 0);
		foreach(TreeParamItem* child_param_item, param_item->children)
			layout->addWidget(CreateWarheadParamWgt(child_param_item));
	}
	return wgt;
}
QHBoxLayout* CreateHBoxLayout(const QString& label_text, const QString& value)
{
	QHBoxLayout* layout = new QHBoxLayout;
	QLabel* label = new QLabel(label_text);
	label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	layout->addWidget(label);
	QLineEdit* editer = new QLineEdit(value);
	editer->setEnabled(false);
	layout->addWidget(editer);
	return layout;
}
QWidget* CreateRangeWgt(TargetRange* range)
{
	QWidget* wgt = new QWidget;
	QVBoxLayout* layout = new QVBoxLayout(wgt);
	osg::Vec2 size = range->get_size();
	layout->addLayout(CreateHBoxLayout(ExpandQtCore::fromGBK("靶板长(m)"), QString::number(size[0])));
	layout->addLayout(CreateHBoxLayout(ExpandQtCore::fromGBK("靶板宽(m)"), QString::number(size[1])));
	layout->addLayout(CreateHBoxLayout(ExpandQtCore::fromGBK("靶板材料"), range->get_material()));
	layout->addLayout(CreateHBoxLayout(ExpandQtCore::fromGBK("靶板密度(kg/m^3)"), QString::number(range->get_material_density())));
	layout->addLayout(CreateHBoxLayout(ExpandQtCore::fromGBK("靶板与地面夹角(°)"), QString::number(range->get_included_angle())));
	for(int i=0, n=range->GetNumCards(); i<n; ++i)
	{
		TargetCard* card = range->GetCard(i);
		QGroupBox* group_box = new QGroupBox(ExpandQtCore::fromGBK("靶板%1").arg(i+1));
		QVBoxLayout* v_layout = new QVBoxLayout(group_box);
		v_layout->addLayout(CreateHBoxLayout(ExpandQtCore::fromGBK("厚度(mm)"), QString::number(card->mt*1000)));
		v_layout->addLayout(CreateHBoxLayout(ExpandQtCore::fromGBK("与上一靶板间隔(m)"), QString::number(card->space)));
		layout->addWidget(group_box);
	}
	return wgt;
}
void MainCtrlWnd::ReadConfig()
{
	QDomDocument doc("mydocument");
	QFile file(config_file_);
	if (!file.open(QIODevice::ReadOnly))
		return;
	if (!doc.setContent(&file)) {
		file.close();
		return;
	}
	file.close();
	QDomElement root = doc.documentElement();
	QDomElement warheads = root.firstChildElement("warheads");
	for(QDomElement warhead_element = warheads.firstChildElement("warhead");
		!warhead_element.isNull();
		warhead_element = warhead_element.nextSiblingElement("warhead"))
	{
		Warhead* warhead = new Warhead;
		QString name = warhead_element.attribute("name");
		warhead->set_name(name);
		warhead->set_model_file(warhead_element.attribute("model"));
		name_2_warhead_.insert(name, warhead);
		warhead->set_root_param_item(CreateParamItem(warhead_element.firstChildElement("property"), 0));
	}
	QDomElement ranges = root.firstChildElement("target_ranges");
	for(QDomElement range_element = ranges.firstChildElement("range");
		!range_element.isNull();
		range_element = range_element.nextSiblingElement("range"))
	{
		TargetRange* range = new TargetRange;
		QString name = range_element.attribute("name");
		range->set_name(name);
		range->set_model_file(range_element.attribute("model"));
		double inclued_angle = range_element.attribute("included_angle").toDouble();
		double length = range_element.attribute("length").toDouble();
		double width = range_element.attribute("width").toDouble();
		double space = range_element.attribute("space").toDouble();
		double mt = range_element.attribute("mt").toDouble(); // mm
		range->set_size(osg::Vec2(length, width));
		range->set_material(range_element.attribute("material"));
		range->set_material_density(range_element.attribute("material_density").toDouble());
		range->set_included_angle(inclued_angle);
		for(QDomElement plate_element = range_element.firstChildElement("plate");
			!plate_element.isNull();
			plate_element = plate_element.nextSiblingElement("plate"))
		{
			QString _space = plate_element.attribute("space");
			if(!_space.isEmpty())
				space = _space.toDouble();
			QString _mt = plate_element.attribute("mt");
			if(!_mt.isEmpty())
				mt = _mt.toDouble();
			TargetCard* card = new TargetCard;
			card->space = range->GetNumCards() > 0 ? space : 0;
			card->tilt_angle = inclued_angle;
			card->mt = mt/1000.0;
			range->AddCard(card);
		}
		name_2_range_.insert(name, range);
	}
}

void MainCtrlWnd::InitDockWarhead()
{
	QDockWidget* dock = new QDockWidget;
	dock->setFloating(false);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
	dock->setWindowTitle(ExpandQtCore::fromGBK("战斗部"));
	QWidget* wgt = new QWidget;
	dock->setWidget(wgt);
	QVBoxLayout* layout = new QVBoxLayout(wgt);
	QHBoxLayout* h_layout = new QHBoxLayout;
	QLabel* label = new QLabel(ExpandQtCore::fromGBK("战斗部选择"));
	warhead_combobox_ = new QComboBox;
	warhead_combobox_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	warhead_combobox_->addItems(name_2_warhead_.keys());
	h_layout->addWidget(label);
	h_layout->addWidget(warhead_combobox_);
	QScrollArea* scroll_wgt = new QScrollArea;
	scroll_wgt->setWidgetResizable(true);
	QWidget* scroll_content_wgt = new QWidget;
	QVBoxLayout* scroll_layout = new QVBoxLayout(scroll_content_wgt);
	QStackedWidget* stacked_wgt = new QStackedWidget;
	scroll_layout->addWidget(stacked_wgt);
	scroll_layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Expanding));
	scroll_wgt->setWidget(scroll_content_wgt);
	foreach(Warhead* warhead, name_2_warhead_.values())
	{
		stacked_wgt->addWidget(CreateWarheadParamWgt(warhead->get_root_param_item()));
	}
	layout->addLayout(h_layout);
	layout->addWidget(scroll_wgt);
	connect(warhead_combobox_, SIGNAL(currentIndexChanged(int)), stacked_wgt, SLOT(setCurrentIndex(int)));
	connect(warhead_combobox_, SIGNAL(currentIndexChanged(int)), stacked_wgt, SLOT(on_warhead_changed(int)));
	on_warhead_changed(warhead_combobox_->currentIndex());
}
void MainCtrlWnd::InitDockRange()
{
	QDockWidget* dock = new QDockWidget;
	dock->setFloating(false);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
	dock->setWindowTitle(ExpandQtCore::fromGBK("布靶方案"));
	QWidget* wgt = new QWidget;
	dock->setWidget(wgt);
	QVBoxLayout* layout = new QVBoxLayout(wgt);
	QHBoxLayout* h_layout = new QHBoxLayout;
	QLabel* label = new QLabel(ExpandQtCore::fromGBK("布靶方案选择"));
	range_combobox_ = new QComboBox;
	range_combobox_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	range_combobox_->addItems(name_2_range_.keys());
	h_layout->addWidget(label);
	h_layout->addWidget(range_combobox_);
	QScrollArea* scroll_wgt = new QScrollArea;
	scroll_wgt->setWidgetResizable(true);
	QWidget* scroll_content_wgt = new QWidget;
	QVBoxLayout* scroll_layout = new QVBoxLayout(scroll_content_wgt);
	QStackedWidget* stacked_wgt = new QStackedWidget;
	scroll_layout->addWidget(stacked_wgt);
	scroll_layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Expanding));
	scroll_wgt->setWidget(scroll_content_wgt);
	foreach(TargetRange* range, name_2_range_.values())
	{
		stacked_wgt->addWidget(CreateRangeWgt(range));
	}
	layout->addLayout(h_layout);
	layout->addWidget(scroll_wgt);
	connect(range_combobox_, SIGNAL(currentIndexChanged(int)), stacked_wgt, SLOT(setCurrentIndex(int)));
	connect(range_combobox_, SIGNAL(currentIndexChanged(int)), stacked_wgt, SLOT(on_range_changed(int)));
	on_range_changed(range_combobox_->currentIndex());
}


