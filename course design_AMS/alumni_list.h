#pragma once//ͷ�ļ���������ֹ�ظ�����
#include "list.h"
#include "alumniFilter.h"
class alumni_list: public List<alumni>{
public:
	alumni_list();
	~alumni_list();
	void sort(bool (*Compare)(const alumni& val1, const alumni& val2));//����������ԭ�����в�������
	void show()const;//��ҳչʾ
	void filter_show(const alumniFilter& filter)const;//ɸѡչʾ
	void show_allowChange();//�����޸ĵ�չʾ
	void filter_show_allowChange(const alumniFilter& alumniFilter);//�����޸ĵ�ɸѡչʾ
};
