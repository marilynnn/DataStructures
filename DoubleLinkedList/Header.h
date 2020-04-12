#pragma once


// ����� �������� �� �������
using ValueType = double;

class DoubleLinkedList
{
	// ����� ���� ������
	// �� ����� ����, ����� ��������� ����� ������,
	// ����� ����������� � ������������� ������, ������ ������� 
	// ���� � ������ � ���� �, � ������ �����, �������� ������ LinkedList 
	// (������ �� �����, ����� �� ����� � �.�.)
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

	// ������ � �������� �������� �� �������
	ValueType& operator[](const size_t pos) const;
	// ������ � ���� �� �������
	DoubleLinkedList::Node* getNode(const size_t pos) const;

	// ������� �������� �� �������, ������� ����, ���� ��������� (�(n)), ����� ��������� (O(1))
	void insert(const size_t pos, const ValueType& value);
	// ������� �������� ����� ����, (O(1))
	void insertBeforeNode(Node* node, const ValueType& value);
	// ������� �������� �� ����, (O(1))
    void insertAfterNode(Node* node, const ValueType& value);
	// ������� � ����� (�(1))
	void pushBack(const ValueType& value);
	// ������� � ������ (�(1))
	void pushFront(const ValueType& value);

	// ��������
	void remove(const size_t pos);
	void removeNextNode(Node* node);
	void removePrevNode(Node* node);
	void removeFront();
	void removeBack();

	// �����, �(n)
	long long int findIndex(const ValueType& value) const;
	Node* findNode(const ValueType& value) const;

	// �������� ������
	void reverse();						// ��������� �������� ������
	DoubleLinkedList reverse() const;			// �������� ������ ������ (��� ����������� ��������)
	DoubleLinkedList getReverseList() const;	// ����� ������������� ������ ���� ��� ���������� ����� ����������� ������

	size_t size() const;
private:
	Node* _head;
	Node* _tail;
	size_t	_size;

	void forceNodeDelete(Node* node);
};
