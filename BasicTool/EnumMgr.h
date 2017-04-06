#pragma once
#include "basictool_global.h"
#include <QtCore>

class BASICTOOL_EXPORT EnumMgr
{
public:
	static EnumMgr& instance()
	{
		static EnumMgr s_instance;
		return s_instance;
	}
	~EnumMgr(void);
	// ö�������Ƿ����
	template <class T>
	bool IsExist()
	{
		std::string type = typeid(T).name();
		return type_2_info_.contains(type);
	}
	// ����ö��
	template <class T>
	void AddEnum(const T& value, const QString& name)
	{
		std::string type = typeid(T).name();
		type_2_info_[type].insert(value, name);
	}

	// ��ȡö�ٵ�ֵ
	template <class T>
	T GetEnumValue(const QString& name) const
	{
		std::string type = typeid(T).name();
		const EnumInfo& enum_info = type_2_info_.value(type);
		return static_cast<T>(enum_info.key(name, 0));
	}

	// ��ȡö�ٵ�����
	template <class T>
	QString GetEnumName(const T& value) const
	{
		std::string type = typeid(T).name();
		const EnumInfo& enum_info = type_2_info_.value(type);
		return enum_info.value(value);
	}

	// ��ȡö�����͵���������
	template <class T>
	QStringList GetNames() const 
	{ 
		std::string type = typeid(T).name();
		const EnumInfo& enum_info = type_2_info_.value(type);
		return enum_info.values();
	}

private:
	EnumMgr(void);
	typedef QMap<int, QString> EnumInfo;
	QMap<std::string, EnumInfo> type_2_info_;

};

