#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "visitor.h"
#include "myList.h"
#include "alumni.h"
#include "Utils.h"
#include "alumni_list.h"
class VisitorModle {
public:
	VisitorModle(alumni_list current_alumni_list_,visitor current_visitor_);
	void run();
private:
	alumni_list current_alumni_list; // У���б�,ע�����һ����Ҫ������ͬ����
	visitor current_visitor; // ��ǰ�ÿ�
};