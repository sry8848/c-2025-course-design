#pragma once

// 先包含alumni的完整定义
#include "alumni.h"

// 再包含依赖alumni的模板
#include "List.h"

// 最后包含其他依赖
#include "alumniFilter.h"
class alumni_list{
public:
	alumni_list(){}
	//alumni_list(List<alumni>& alumniList_) :alumniList(alumniList_) {}
	void sort(bool (*Compare)(const alumni& val1, const alumni& val2));//插入排序，在原链表中插入排序
	void show()const;//分页展示
	void filter_show(const alumniFilter& filter)const;//筛选展示
	void show_allowChange();//允许修改的展示
	void filter_show_allowChange(const alumniFilter& alumniFilter);//允许修改的筛选展示
	alumni_list search_form_line(const std::string& keyword) const;//搜索功能，返回一个新的alumni_list
private:
	List<alumni> alumniList;
};
