#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "alumni.h"
#include "list.h"
#include "Utils.h"
#include "alumni_list.h"
class alumniModle {
public:
	alumniModle(alumni_list current_alumni_list_, alumni current_alumni_);
	void run();
private:
	alumni_list current_alumni_list; // У���б�,ע�����һ����Ҫ������ͬ����
	alumni current_alumni; // ��ǰ�ÿ�
};