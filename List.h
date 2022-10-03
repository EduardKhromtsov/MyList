#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
public:
	List();

	void push_back(const T &Data);

	void pop_front();

	void clear();

	int GetSize() const;

	T& operator[] (const int kIndex);

private:
	template<typename T>
	class Node // Создаем вложенный класс для узлов односвязного списка.
	{
	public:
		Node *pNext;
		T Data;

		Node(const T &Data = T(), Node *pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
		}

	};
	Node<T> *pHead; // Указатель на самый первый элемент списка.
	int iSize; // Количество элементов односвязного списка.
};

#endif 



