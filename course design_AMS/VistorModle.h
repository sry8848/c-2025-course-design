#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "visitor.h"
#include "list.h"
#include "alumni.h"
#include "Utils.h"
#include "alumni_list.h"
class VistorModle {
public:
	void run();
private:
	List<visitor>* visitor_list; // �ÿ��б�
	alumni_list alumni_list; // У���б�
	visitor current_visitor; // ��ǰ�ÿ�
};