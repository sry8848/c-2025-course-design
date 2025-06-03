#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include <vector>
#include "major.h"//����רҵ���ͷ�ļ�
class Department {
public:
	//���캯������ʼ��ϵ����רҵ�б�
	Department(const std::string& name) 
		: departmentName(name){}

	//��ȡϵ��
	std::string getDepartmentName() const {
		return departmentName;
	}

	//��ȡרҵ�б�
	std::vector<Major>& getMajorList() {
		return majorList;
	}

	//����ϵ��
	void setDepartmentName(const std::string& name) {
		departmentName = name;
	}

private:
	std::string departmentName;
	std::vector<Major> majorList;
}; 
