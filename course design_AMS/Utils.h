#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
class Utils {
public:
	//�����Ϊ��̬����������Ҫ���󼴿ɵ���
	//ѡ�����
	static int getChoice(int numberOfChoices);//��ȡ�û������ѡ��
	//������֤
	static std::string modifyPassword(std::string prePassword);//�޸����룬���������벢��֤,����Ϊԭ����;
	static std::string onlyNumberInput();//ֻ�����������ֵ�����
	static std::string pinyinInput();//ƴ�����룬ֻ����Ӣ�����룬�Զ�תСд��ĸ
	//�ַ�ת��
	//�ֶβ���
	static int serach_return_weight(const std::string& str, const std::string& key);//���ַ����в����Ӵ�������Ȩ��ֵ
};
