#include "Header.h"

#include <cassert>

DoubleLinkedList::Node::Node(const ValueType& value, Node* prev, Node* next)
{
	this->value = value;
	this->prev = prev;
	this->next = next;
}

DoubleLinkedList::Node::~Node()
{
	// ничего не удаляем, т.к. агрегация
}

void  DoubleLinkedList::Node::insertPrev(const ValueType& value) {
	Node* newNode = new Node(value, this->prev, this);
	this->prev = newNode;
}

void DoubleLinkedList::Node::insertNext(const ValueType& value)
{
	Node* newNode = new Node(value, this, this->next);
	this->next = newNode;
}

void DoubleLinkedList::Node::removePrev()
{
	Node* removeNode = this->prev;
	Node* newPrev = removeNode->prev;
	newPrev->next = this;
	delete removeNode;
	this->prev = newPrev;
}

void DoubleLinkedList::Node::removeNext()
{
	Node* removeNode = this->next;
	Node* newNext = removeNode->next;
	newNext->prev = this;
	delete removeNode;
	this->next = newNext;
}


DoubleLinkedList::DoubleLinkedList()
	: _head(nullptr), _size(0), _tail(nullptr)
{

}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& copyList)
{
	if (this == &copyList) {
		return *this;
	}
	forceNodeDelete(_head);							
	DoubleLinkedList* bufList = new DoubleLinkedList(copyList);

	this->_size = bufList->_size;
	this->_head = bufList->_head;
	this->_tail = bufList->_tail;

	return *this;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& copyList)
{
	this->_size = copyList._size;
	if (this->_size == 0) {
		this->_head = nullptr;
		this->_tail = nullptr;
		return;
	}

	this->_head = new Node(copyList._head->value);

	Node* currentNode = this->_head;
	Node* currentCopyNode = copyList._head;

	while (currentCopyNode->next) {
		currentCopyNode = currentCopyNode->next;
		currentNode->next = new Node(currentCopyNode->value, currentCopyNode); 
		currentNode = currentNode->next;
	}
	this->_tail = currentNode;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& moveList) noexcept
{
	this->_size = moveList._size;
	this->_head = moveList._head;
	this->_tail = moveList._tail;

	moveList._size = 0;
	moveList._head = nullptr;
	moveList._tail = nullptr;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& moveList) noexcept
{
	if (this == &moveList) {
		return *this;
	}
	forceNodeDelete(_head);
	this->_size = moveList._size;
	this->_head = moveList._head;
	this->_tail = moveList._tail;

	moveList._size = 0;
	moveList._head = nullptr;
	moveList._tail = nullptr;

	return *this;
}

DoubleLinkedList::~DoubleLinkedList()
{
	forceNodeDelete(_head);
	_size = 0;
}

ValueType& DoubleLinkedList::operator[](const size_t pos) const
{
	return getNode(pos)->value;
}

DoubleLinkedList::Node* DoubleLinkedList::getNode(const size_t pos) const
{
	if (pos < 0) {
		assert(pos < 0);
	}
	else if (pos >= this->_size) {
		assert(pos >= this->_size);
	}

	Node* bufNode = this->_head;
	for (size_t i = 0; i < pos; ++i) {
		bufNode = bufNode->next;
	}

	return bufNode;
}

void DoubleLinkedList::insert(const size_t pos, const ValueType& value)
{
	if (pos < 0) {
		assert(pos < 0);
	}
	else if (pos > this->_size) {
		assert(pos > this->_size);
	}

	if (pos == 0) {
		pushFront(value);
	}
	else {
		Node* bufNode = this->_head;
		for (size_t i = 0; i < pos - 1; ++i) {
			bufNode = bufNode->next;
		}
		Node* newNode = new Node(value, bufNode, bufNode->next);
		bufNode->next = newNode;
		if (pos == _size) {
			_tail = newNode;
		}
		
		++_size;
	}
}

void DoubleLinkedList::insertBeforeNode(Node* node, const ValueType& value)
{
	Node* newNode = new Node(value, node->prev, node);
	node->prev = newNode;
	if (newNode->prev == nullptr) {
		_head = newNode;
	}
	++_size;
	
}

void DoubleLinkedList::insertAfterNode(Node* node, const ValueType& value)
{
	Node* newNode = new Node(value, node, node->next);
	node->next = newNode;
	if (newNode->next == nullptr) {
		_tail = newNode;
	}
	++_size;
}

void DoubleLinkedList::pushBack(const ValueType& value)
{
	if (_size == 0) {
		pushFront(value);
		return;
	}
	insert(_size, value);
}

void DoubleLinkedList::pushFront(const ValueType& value)
{
	Node* newHead = new Node(value, nullptr, _head);
	if (_head != nullptr) {
		_head->prev = newHead;
		_head = newHead;
	}
	else {
		_head = newHead;
		_tail = newHead;
	}
	++_size;
}

void DoubleLinkedList::remove(const size_t pos)
{
	if (pos < 0) {
		assert(pos < 0);
	}
	else if (pos > this->_size-1) {
		assert (pos > this->_size-1);//исправить в односвязном! +
	}

	if (pos == 0) {
		Node* bufNode = _head;
		_head = _head->next;
		delete bufNode;
		_size--;
	}
	if (pos == _size-1) {
		Node* bufNode = _tail;
		_tail = _tail->prev;
		delete bufNode;
		_size--;
	}

	else {
		Node* prevNode = this->_head;
		for (size_t i = 0; i < pos - 1; ++i) {
			prevNode = prevNode->next;
		}
		Node* removeNode = prevNode->next;
		Node* newNext = removeNode->next;
		delete removeNode;
		newNext->prev = prevNode;
		prevNode->next = newNext;

		_size--;
	}
}

void DoubleLinkedList::removeNextNode(Node* node)
{										
	if (node == _tail) {
		return;
	}
		Node* removeNode = node->next;
		Node* newNext = removeNode->next;
		if (newNext == nullptr) {
			_tail = node;
		}
		delete removeNode;
		node->next = newNext;
		newNext->prev = node;
		_size--;
	
}

void DoubleLinkedList::removePrevNode(Node* node)
{						
	if (node != _head) {
		return;
	}
		Node* removeNode = node->prev;
		Node* newPrev = removeNode->prev;
		if (newPrev == nullptr) {
			node = _head;
		}
		delete removeNode;
		node->prev = newPrev;
		newPrev->next = node;
		_size--;

	
	
}

void DoubleLinkedList::removeFront() {
	remove(0);
}

void DoubleLinkedList::removeBack() {
	remove(this->_size - 1);
}


long long int DoubleLinkedList::findIndex(const ValueType& value) const
{
	Node* bufNode = _head;
	for (size_t index = 0; index < _size - 1; index++) {
		if (bufNode->value == value) {
			return index;
		}
		bufNode = bufNode->next;
	}
	return -1; // если элемент со значением value не существует
}

DoubleLinkedList::Node* DoubleLinkedList::findNode(const ValueType& value) const
{
	Node* bufNode = _head;
	for (size_t index = 0; index < _size - 1; index++) {
		if (bufNode->value == value) {
			return bufNode;
		}
		bufNode = bufNode->next;
	}
	return nullptr;
}

void DoubleLinkedList::reverse()
{
	Node* currentNode = _tail;
	_tail = _head;
	_head = currentNode;
	Node* bufNode = nullptr;

	while (currentNode != nullptr) {
		bufNode = currentNode->prev;
		currentNode->prev = currentNode->next;
		currentNode->next = bufNode;
	}

}

DoubleLinkedList DoubleLinkedList::reverse() const
{
	DoubleLinkedList reversed = *this;
	reversed.reverse();

	return reversed;
}

DoubleLinkedList DoubleLinkedList::getReverseList() const
{
	DoubleLinkedList reversed = *this;
	reversed.reverse();

	return reversed;
}

size_t DoubleLinkedList::size() const
{
	return _size;
}

void DoubleLinkedList::forceNodeDelete(Node* node)
{
	if (node == nullptr) {
		return;
	}

	Node* nextDeleteNode = node->next;
	delete node;
	forceNodeDelete(nextDeleteNode);
}
int main() {
	return 0;
}