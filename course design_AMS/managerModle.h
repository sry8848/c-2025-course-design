#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "manager.h"
#include "list.h"
#include "Utils.h"
#include "alumni_list.h"
class managerModle {
public:
	void run();
private:
	alumni_list alumni_list; // У���б�
	List<manager>* manager_list; 
	manager current_manager; 
};