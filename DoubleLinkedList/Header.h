#pragma once


// потом помен€ем на шаблоны
using ValueType = double;

class DoubleLinkedList
{
	// класс узла списка
	// по своей сути, может содержать любые данные,
	// можно реализовать и ассоциативный массив, просто добавив 
	// поле с ключем в узел и, с учетом этого, помен€ть методы LinkedList 
	// (доступ по ключу, поиск по ключу и т.д.)
	struct Node {

		Node(const ValueType& value, Node* prev = nullptr, Node* next = nullptr);
		~Node();
		void insertPrev(const ValueType& value);
		void insertNext(const ValueType& value);
		void removePrev();
		void removeNext();

		ValueType value;
		Node* prev;
		Node* next;
	};

public:
	////
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& copyList);
	DoubleLinkedList& operator=(const DoubleLinkedList& copyList);

	DoubleLinkedList(DoubleLinkedList&& moveList) noexcept;
	DoubleLinkedList& operator=(DoubleLinkedList&& moveList) noexcept;

	~DoubleLinkedList();
	////

	// доступ к значению элемента по индексу
	ValueType& operator[](const size_t pos) const;
	// доступ к узлу по индексу
	DoubleLinkedList::Node* getNode(const size_t pos) const;

	// вставка элемента по индексу, сначала ищем, куда вставл€ть (ќ(n)), потом вставл€ем (O(1))
	void insert(const size_t pos, const ValueType& value);
	// вставка элемента после узла, (O(1))
	void insertBeforeNode(Node* node, const ValueType& value);
	// вставка элемента до узла, (O(1))
    void insertAfterNode(Node* node, const ValueType& value);
	// вставка в конец (ќ(1))
	void pushBack(const ValueType& value);
	// вставка в начало (ќ(1))
	void pushFront(const ValueType& value);

	// удаление
	void remove(const size_t pos);
	void removeNextNode(Node* node);
	void removePrevNode(Node* node);
	void removeFront();
	void removeBack();

	// поиск, ќ(n)
	long long int findIndex(const ValueType& value) const;
	Node* findNode(const ValueType& value) const;

	// разворот списка
	void reverse();						// изменение текущего списка
	DoubleLinkedList reverse() const;			// полчение нового списка (дл€ константных объектов)
	DoubleLinkedList getReverseList() const;	// чтобы неконстантный объект тоже мог возвращать новый развернутый список

	size_t size() const;
private:
	Node* _head;
	Node* _tail;
	size_t	_size;

	void forceNodeDelete(Node* node);
};
