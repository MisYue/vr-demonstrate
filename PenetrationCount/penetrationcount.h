//***************************************
//	����ʱ��:	2017:3:28   14:08
//	�ļ�����: 	penetrationcount.h
//	�ļ�����:	��Ⱥ��
//	
//	����˵��:	�ֳ������ඨ��
//***************************************

#ifndef PENETRATIONCOUNT_H
#define PENETRATIONCOUNT_H

#include "penetrationcount_global.h"

// ���嵯��ĩ������
// ���岿������
// ����Ŀ������
// ����ս��������
// �ɵ���ĩ��ƫ����λ�ü��㵯����
// �ɵ����߼�����������Ľ����
// ��ÿ���н����Ĳ��������˶���������ʱ�䣬��ʱ���ۻ���������ʱ�䣬���ڽ���֮ǰ��ը����¼��ըʱ�䣬λ�ã���̬
// ��û�г�������ʱ�䣬���Ƿ�ᴩ
// �����ܹᴩ����ս�������ڰ��б�ը�����ֳ���ȣ���¼ʱ�䣬λ�ã���̬
// ���ᴩ����ʣ���ٶȣ���¼ʱ�䣬����㣬��̬
// 

// �ֳ��������
struct PCP
{
	double iv; // ���� m/s
	double wm; // ���� kg
	double wd; // Բ����ֱ�� m
	double bt; // �а��� m
	double ca; // ��ͷ�Ž� ��
	PCP()
		: iv(0), wm(0), wd(0), bt(0), ca(0)
	{

	}
};

// ��ͷ���ֳ��������
struct PCPOval : public PCP
{
	double oria;	// ���ε�����ϵ��A,һ��Ϊ2400, ��ս����������ϺͰа�����й�
	PCPOval()
		: oria(0)
	{

	}
};

// ��ͷ���ֳ��������
struct PCPSharp : public PCP
{
	double ctik; // ��ͷ��ʵ��ϵ��K
	double cfpd; // ��׶�ε�ƽ������ֱ��,m
	double chc; // ��ͷ����׶��,��
	double md; // �а�����ܶ�,kg/m^3
	PCPSharp()
		: ctik(0), cfpd(0), chc(0), md(0)
	{

	}
};
class PENETRATIONCOUNT_EXPORT PenetrationCount
{
public:
	PenetrationCount();
	~PenetrationCount();
	// ��ͷ���ֳ���ȼ�ʣ���ٶȼ���
	// pcp:�ֳ��������
	// vr:ʣ���ٶ�
	// pd:�ֳ����
	bool CountOval(const PCPOval& pcp, double& vr, double& pd);

	// ��ͷ���ֳ���ȼ�ʣ���ٶȼ���
	// pcp:�ֳ��������
	// vr:ʣ���ٶ�
	// pd:�ֳ����
	bool CountSharp(const PCPSharp& pcp, double& vr, double& pd);
private:

};

#endif // PENETRATIONCOUNT_H
