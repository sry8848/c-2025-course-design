#pragma once

// �Ȱ���alumni����������
#include "alumni.h"

// �ٰ�������alumni��ģ��
#include "List.h"

// ��������������
#include "alumniFilter.h"
class alumni_list{
public:
	alumni_list(){}
	//alumni_list(List<alumni>& alumniList_) :alumniList(alumniList_) {}
	void sort(bool (*Compare)(const alumni& val1, const alumni& val2));//����������ԭ�����в�������
	void show()const;//��ҳչʾ
	void filter_show(const alumniFilter& filter)const;//ɸѡչʾ
	void show_allowChange();//�����޸ĵ�չʾ
	void filter_show_allowChange(const alumniFilter& alumniFilter);//�����޸ĵ�ɸѡչʾ
	alumni_list search_form_line(const std::string& keyword) const;//�������ܣ�����һ���µ�alumni_list
private:
	List<alumni> alumniList;
};
