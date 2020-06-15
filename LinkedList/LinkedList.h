#pragma once

#include <cstddef>

// ïîòîì ïîìåíÿåì íà øàáëîíû
using ValueType = double;

class LinkedList
{
	// êëàññ óçëà ñïèñêà
	// ïî ñâîåé ñóòè, ìîæåò ñîäåðæàòü ëþáûå äàííûå,
	// ìîæíî ðåàëèçîâàòü è àññîöèàòèâíûé ìàññèâ, ïðîñòî äîáàâèâ 
	// ïîëå ñ êëþ÷åì â óçåë è, ñ ó÷åòîì ýòîãî, ïîìåíÿòü ìåòîäû LinkedList 
	// (äîñòóï ïî êëþ÷ó, ïîèñê ïî êëþ÷ó è ò.ä.)
	struct Node {
		Node(const ValueType& value, Node* next = nullptr);
		~Node();

		void insertNext(const ValueType& value);
		void removeNext();

		ValueType value;
		Node* next;
	};

public:
	////
	LinkedList();
	LinkedList(const LinkedList& copyList);
	LinkedList& operator=(const LinkedList& copyList);

	LinkedList(LinkedList&& moveList) noexcept;
	LinkedList& operator=(LinkedList&& moveList) noexcept;

	~LinkedList();
	////

	// äîñòóï ê çíà÷åíèþ ýëåìåíòà ïî èíäåêñó
	ValueType& operator[](const size_t pos) const;
	// äîñòóï ê óçëó ïî èíäåêñó
	LinkedList::Node* getNode(const size_t pos) const;

	// âñòàâêà ýëåìåíòà ïî èíäåêñó, ñíà÷àëà èùåì, êóäà âñòàâëÿòü (Î(n)), ïîòîì âñòàâëÿåì (O(1))
	void insert(const size_t pos, const ValueType& value);
	// âñòàâêà ýëåìåíòà ïîñëå óçëà, (O(1))
	void insertAfterNode(Node* node, const ValueType& value);
	// âñòàâêà â êîíåö (Î(n))
	void pushBack(const ValueType& value);
	// âñòàâêà â íà÷àëî (Î(1))
	void pushFront(const ValueType& value);

	// óäàëåíèå
	void remove(const size_t pos);
	void removeNextNode(Node* node);
	void removeFront();
	void removeBack();

	// ïîèñê, Î(n)
	long long int findIndex(const ValueType& value) const;
	Node* findNode(const ValueType& value) const;

	// ðàçâîðîò ñïèñêà
	void reverse();						// èçìåíåíèå òåêóùåãî ñïèñêà
	LinkedList reverse() const;			// ïîë÷åíèå íîâîãî ñïèñêà (äëÿ êîíñòàíòíûõ îáúåêòîâ)
	LinkedList getReverseList() const;	// ÷òîáû íåêîíñòàíòíûé îáúåêò òîæå ìîã âîçâðàùàòü íîâûé ðàçâåðíóòûé ñïèñîê

	size_t size() const;
private:
	Node* _head;
	size_t	_size;

	void forceNodeDelete(Node* node);
};
