
#include <iostream>

// Реализация односвязного списка.

template<typename T>
class List
{
public:
	List();

	void push_back(T Data);
private:
	template<typename T>
	class Node // Создаем вложенный класс для узлов односвязного списка.
	{
	public:
		Node *pNext;
		T Data;

		Node(T Data = T(), Node *pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
		}

	};
	Node<T> *pHead; // Указатель на самый первый элемент списка.
	int iSize; // Количество элементов односвязного списка.
};

int main()
{
	List<int> lst;
	
	lst.push_back(5);
}

template<typename T>
List<T>::List()
{
	iSize = 0;
	pHead = nullptr;
}

template<typename T>
void List<T>::push_back(T Data)
{
	if (pHead == nullptr)
		pHead = new Node<T>(Data);
}

