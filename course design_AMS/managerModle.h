#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "manager.h"
#include "list.h"
#include "Utils.h"
class managerModle {
public:
	void run();
private:
	List<manager>* manager_list; 
	manager current_manager; 
};