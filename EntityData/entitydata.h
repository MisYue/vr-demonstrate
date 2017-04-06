#ifndef ENTITYDATA_H
#define ENTITYDATA_H

#include "entitydata_global.h"
#include "treeitem.h"
#include <osg/Vec2>
#include <osg/Vec3>
#include <QtCore>

// ĩ�˵���
struct TerminalTrajectory
{
	osg::Vec3 xyz;
	osg::Vec3 hpr;
	double v;
};

// ����������
struct TriangleMeshFace
{
	osg::Vec3 a;
	osg::Vec3 b;
	osg::Vec3 c;
	osg::Vec3 n;
};
// �а�
struct TargetCard
{
	//int id;	//���
	double space; // ��� m
	double mt; // ��� m
	double tilt_angle;	// ��б�Ƕȣ�����X��
	QVector<TriangleMeshFace> meshes; // ������
	TargetCard() : space(0), mt(0)
	{
		meshes.resize(12);
	}
};

// ս����
typedef TreeItem<ParamItem> TreeParamItem;
class ENTITYDATA_EXPORT Warhead
{
public:
	Warhead() : root_param_item_(0) {}
	~Warhead()
	{
		if(root_param_item_)
			delete root_param_item_;
	}
	void set_name(const QString& name) { name_ = name; }
	QString get_name() const { return name_; }

	void set_model_file(const QString& model_file) { model_file_ = model_file; }
	QString get_model_file() const { return model_file_; }

	void SetPropertyValue(const QString& name, const QString& value) 
	{ 
		TreeParamItem* item = property_2_value_.value(name, 0);
		if(item)
			item->node.value = value;
	}
	QString GetPropertyValue(const QString& name) const 
	{ 
		TreeParamItem* item = property_2_value_.value(name, 0);
		if(item)
			return item->node.value;
		return QString();
	}
	void set_root_param_item(TreeParamItem* item) { root_param_item_ = item; }
	TreeParamItem* get_root_param_item() { return root_param_item_; }
	TerminalTrajectory get_tetr() const { return tetr_; }
	void set_tetr(const TerminalTrajectory& tetr) { tetr_ = tetr; }

	void ResetPropertyQueryStructure();
protected:
	QMap<QString, TreeParamItem*> property_2_value_;
	TreeParamItem* root_param_item_;
	TerminalTrajectory tetr_;
	QString name_;
	QString model_file_;
};

// �г�
class ENTITYDATA_EXPORT TargetRange
{
public:
	~TargetRange()
	{
		qDeleteAll(cards_);
	}
	void set_name(const QString& name) { name_ = name; }
	QString get_name() const { return name_; }

	void set_model_file(const QString& model_file) { model_file_ = model_file; }
	QString get_model_file() const { return model_file_; }

	void set_material(const QString& material) { material_ = material; }
	QString get_material() const { return material_; }

	void set_material_density(double density) { material_density_ = density; }
	double get_material_density() const { return material_density_; }

	void set_size(const osg::Vec2& size) { size_ = size; }
	osg::Vec2 get_size() const { return size_; }

	void set_included_angle(double angle) { included_angle_ = angle; }
	double get_included_angle() const { return included_angle_; }

	void AddCard(TargetCard* card) 
	{
		if(card)
		{
			if(!cards_.contains(card))
				cards_.append(card);
		}
	}
	void RemoveCard(TargetCard* card)
	{
		if(card)
		{
			int count = cards_.removeAll(card);
			if(count > 0)
				delete card;
		}
	}
	int GetNumCards() const { return cards_.size(); }
	TargetCard* GetCard(int index)
	{
		if(0 <= index && index < cards_.size())
			return cards_.at(index);
		return 0;
	}

	void Meshing();
protected:
	QString name_;
	QString model_file_;
	QString material_;
	double material_density_; // kg/m^3
	double included_angle_; // �����н� ��
	osg::Vec2 size_; // ���ȺͿ�� m
	QList<TargetCard*> cards_;
};

class ENTITYDATA_EXPORT EntityData
{
public:
	EntityData();
	~EntityData();

private:

};

#endif // ENTITYDATA_H
