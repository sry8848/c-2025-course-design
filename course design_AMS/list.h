#pragma once//ͷ�ļ���������ֹ�ظ�����
template<typename T>
class List {
protected:
	struct Node {//Node�ṹ���趨����Iterator��֮ǰ������ᱨ��
		T data;
		Node* next;
	};
	Node* head;
public:
	List();
	~List();
	void insert(const T& val);//ͷ�巨
	void erase(int num);//����Ԫ�ز�ɾ��
	bool empty()const;
	T operator[](int num);//����[]
	//������
	class Iterator {
	public:
		Iterator(Node* node) : current(node) {}
		T& operator* () { return current->data; }
		Iterator& operator++() { current = current->next; return (*this); }
		Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }
		bool operator!=(const Iterator& other) { return this->current != other.current; }
	private:
		Node* current;
	};
	Iterator begin() const{ return Iterator(head); }//��Ҫ������Iterator���⣬����ᱨ��
	Iterator end() const{ return Iterator(nullptr); }
};
