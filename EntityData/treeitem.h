#pragma once
#include <QtCore>

template <class T>
struct TreeItem
{
	T node;
	TreeItem* parent;
	QList<TreeItem*> children;

	TreeItem() : parent(0) {}
	~TreeItem()
	{
		qDeleteAll(children);
	}
};

//  Ù–‘œÓ
struct ParamItem
{
	bool editable;
	QString name;
	QString mean;
	QString value;
	QString edit_hints_;
};