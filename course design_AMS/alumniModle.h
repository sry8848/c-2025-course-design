#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "alumni.h"
#include "list.h"
#include "Utils.h"
#include "alumni_list.h"
class alumniModle {
public:
	void run();
private:
	alumni_list alumni_list; // У���б�
	alumni current_alumni; // ��ǰУ��
};