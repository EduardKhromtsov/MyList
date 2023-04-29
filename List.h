#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
private:
	template<typename T>
	class Node // Создаем вложенный класс для узлов односвязного списка.
	{
	public:
		Node* pNext;
		T data;

		Node(const T& data = T(), Node* pNext = nullptr) : pNext{ pNext }, data{ data }
		{
		}

	};

	Node<T>* pHead; // Указатель на самый первый элемент списка.
	int size; // Количество элементов односвязного списка.

public:
	List();

	~List();

	void push_back(const T& data);

	void push_front(const T& data);

	void insert(const T& data, const int index);

	void removeAt(const int index);

	void pop_front();

	void pop_back();

	void clear();

	int length() const;

	T& operator[](const int index);
};

template<typename T>
List<T>::List() : size{ 0 }, pHead{ nullptr } 
{
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(const T& data)
{
	if (pHead == nullptr)
		pHead = new Node<T>(data);
	else
	{
		Node<T>* pCurrent = this->pHead;

		while (pCurrent->pNext != nullptr)
			pCurrent = pCurrent->pNext;

		pCurrent->pNext = new Node<T>(data);
	}
	++size;
}

template<typename T>
void List<T>::push_front(const T& data)
{
	pHead = new Node<T>(data, pHead);

	++size;
}

template<typename T>
void List<T>::insert(const T& data, const int index)
{
	if (index == 0)
		push_front(data);
	else
	{
		Node<T>* pPrevious = this->pHead;

		for (int i = 0; i < index - 1; ++i)
			pPrevious = pPrevious->pNext;

		pPrevious->pNext = new Node<T>(data, pPrevious->pNext);

		++size;
	}
}

template<typename T>
void List<T>::removeAt(const int index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node<T>* pPrevious = this->pHead;

		for (int i = 0; i < index - 1; ++i)
			pPrevious = pPrevious->pNext;

		Node<T>* pToDelete = pPrevious->pNext;

		pPrevious->pNext = pToDelete->pNext;

		delete pToDelete;

		--size;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = pHead;

	pHead = pHead->pNext;

	delete temp;

	--size;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void List<T>::clear()
{
	while (size)
		pop_front();
}

template<typename T>
int List<T>::length() const
{
	return size;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* pCurrent = this->pHead;

	while (pCurrent != nullptr)
	{
		if (counter == index)
			return pCurrent->data;

		pCurrent = pCurrent->pNext;

		++counter;
	}
}

#endif 



