#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "visitor.h"
#include "list.h"
#include "alumni.h"
#include "Utils.h"
class VistorModle {
public:
	void run();
private:
	List<visitor>* visitor_list; // �ÿ��б�
	List<alumni>* alumni_list; // У���б�
	visitor current_visitor; // ��ǰ�ÿ�
};