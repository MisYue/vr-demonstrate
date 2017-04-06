#pragma once
#include "basictool_global.h"
#include <QtCore>

class BASICTOOL_EXPORT Config
{
public:
	Config(void);
	virtual ~Config(void);
	Config(const QString& file_name);
	// ���������ļ�
	void SetConfigFile(const QString& file_name);
	// ��������
	bool SaveConfig(void);
	// ��ȡ����
	QString GetConfigData(const QString& key) const;
	// ��������
	void SetConfigData(const QString& key, const QString& data);
private:
	QMap<QString, QString> key_2_data_;
	QString file_name_;
protected:
	// ��ȡ����
	void ReadConfig(void);
private:
	// ������
	void ParserLine(const QByteArray& line);
};

