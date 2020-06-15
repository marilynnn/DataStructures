#pragma once

#include <cstddef>

// ïîòîì ïîìåíÿåì íà øàáëîíû
using ValueType = double;

class DoubleLinkedList
{
	// êëàññ óçëà ñïèñêà
	// ïî ñâîåé ñóòè, ìîæåò ñîäåðæàòü ëþáûå äàííûå,
	// ìîæíî ðåàëèçîâàòü è àññîöèàòèâíûé ìàññèâ, ïðîñòî äîáàâèâ 
	// ïîëå ñ êëþ÷åì â óçåë è, ñ ó÷åòîì ýòîãî, ïîìåíÿòü ìåòîäû LinkedList 
	// (äîñòóï ïî êëþ÷ó, ïîèñê ïî êëþ÷ó è ò.ä.)
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

	// äîñòóï ê çíà÷åíèþ ýëåìåíòà ïî èíäåêñó
	ValueType& operator[](const size_t pos) const;
	// äîñòóï ê óçëó ïî èíäåêñó
	DoubleLinkedList::Node* getNode(const size_t pos) const;

	// âñòàâêà ýëåìåíòà ïî èíäåêñó, ñíà÷àëà èùåì, êóäà âñòàâëÿòü (Î(n)), ïîòîì âñòàâëÿåì (O(1))
	void insert(const size_t pos, const ValueType& value);
	// âñòàâêà ýëåìåíòà ïîñëå óçëà, (O(1))
	void insertBeforeNode(Node* node, const ValueType& value);
	// âñòàâêà ýëåìåíòà äî óçëà, (O(1))
    void insertAfterNode(Node* node, const ValueType& value);
	// âñòàâêà â êîíåö (Î(1))
	void pushBack(const ValueType& value);
	// âñòàâêà â íà÷àëî (Î(1))
	void pushFront(const ValueType& value);

	// óäàëåíèå
	void remove(const size_t pos);
	void removeNextNode(Node* node);
	void removePrevNode(Node* node);
	void removeFront();
	void removeBack();

	// ïîèñê, Î(n)
	long long int findIndex(const ValueType& value) const;
	Node* findNode(const ValueType& value) const;

	// ðàçâîðîò ñïèñêà
	void reverse();						// èçìåíåíèå òåêóùåãî ñïèñêà
	DoubleLinkedList reverse() const;			// ïîë÷åíèå íîâîãî ñïèñêà (äëÿ êîíñòàíòíûõ îáúåêòîâ)
	DoubleLinkedList getReverseList() const;	// ÷òîáû íåêîíñòàíòíûé îáúåêò òîæå ìîã âîçâðàùàòü íîâûé ðàçâåðíóòûé ñïèñîê

	size_t size() const;
private:
	Node* _head;
	Node* _tail;
	size_t	_size;

	void forceNodeDelete(Node* node);
};
