#pragma once//ͷ�ļ���������ֹ�ظ�����
template<typename T>
class List {
public:
	List();
	~List();
	void insert(const T& val);//ͷ�巨
	void erase(int num);//����Ԫ�ز�ɾ��
	bool empty();
	T operator[](int num);//����[]
private:
	T* head;
	struct Node{
		T data;
		T* next;
	};
};
