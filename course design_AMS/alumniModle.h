#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "alumni.h"
#include "list.h"
#include "Utils.h"
class alumniModle {
public:
	void run();
private:
	List<alumni>* alumni_list; // У���б�
	alumni current_alumni; // ��ǰУ��
};