
#include <iostream>

// Реализация односвязного списка

template<typename T>
class List
{
public:
	List();

	void push_back(T Data);

	int GetSize() const;

	T& operator[] (const int kIndex);
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

	lst.push_back(10);

	lst.push_back(20);

	std::cout << lst[2] << "\n";

	lst[2] = 300;

	std::cout << lst[2] << "\n";

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
	else
	{
		Node<T> *pCurrent = this->pHead;

		while (pCurrent->pNext != nullptr)
			pCurrent = pCurrent->pNext;

		pCurrent->pNext = new Node<T>(Data);
	}
	++iSize;
}

template<typename T>
int List<T>::GetSize() const
{
	return iSize;
}

template<typename T>
T& List<T>::operator[](const int kIndex)
{
	int iCounter = 0;

	Node<T> *pCurrent = this->pHead;

	while (pCurrent != nullptr)
	{
		if (iCounter == kIndex)
			return pCurrent->Data;

		pCurrent = pCurrent->pNext;

		++iCounter;
	}
}

