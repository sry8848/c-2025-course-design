#pragma once//头文件保护，防止重复包含
#include "list.h"
#include "alumniFilter.h"
class alumni_list: public List<alumni>{
public:
	alumni_list();
	~alumni_list();
	void sort(bool (*Compare)(const alumni& val1, const alumni& val2));//插入排序，在原链表中插入排序
	void show()const;//分页展示
	void filter_show(const alumniFilter& filter)const;//筛选展示
	void show_allowChange();//允许修改的展示
	void filter_show_allowChange(const alumniFilter& alumniFilter);//允许修改的筛选展示
};
