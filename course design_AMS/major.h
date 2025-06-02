#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include <vector>
#include "Class.h"//����רҵ���ͷ�ļ�
class Major {
public:
	// ���캯������ʼ��רҵ���Ͱ༶�б�
	Major(const std::string& name) 
		: majorName(name){}

	// ��ȡרҵ��
	std::string getMajorName() const {
		return majorName;
	}

	// ��ȡ�༶�б�
	std::vector<Class>& getClassList() {//�������ã������޸�
		return ClassList;
	}

	// ����רҵ��
	void setMajorName(const std::string& name) {
		majorName = name;
	}


private:
	std::string majorName;
	std::vector<Class> ClassList;
};
