#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "manager.h"
#include "myList.h"
#include "Utils.h"
#include "visitor.h"
#include "alumni_list.h"
class managerModle {
public:
	managerModle(alumni_list current_alumni_list_, manager current_manager_);
	void run();
private:
	List<visitor> current_visitor_list;
	List<manager> current_manager_list;
	alumni_list current_alumni_list; // У���б�,ע�����һ����Ҫ������ͬ����
	manager current_manager; // ��ǰ�ÿ�
};