#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include <vector>
class Class {
public:
	Class(std::string classNumber_ = "0000") : ClassNumber(classNumber_) {} // Ĭ�ϰ༶��Ϊ"0000"
	void setClassNumber(const std::string& num) {
		ClassNumber = num;
	}
	std::string getClassNumber() const { return ClassNumber; }
private:
	std::string ClassNumber;
};
