#include "LinkedList.h"

#include <cassert>

LinkedList::Node::Node(const ValueType& value, Node* next)
{
	this->value = value;
	this->next = next;
}

LinkedList::Node::~Node()
{
	// ничего не удаляем, т.к. агрегация
}

void LinkedList::Node::insertNext(const ValueType& value)
{
	Node* newNode = new Node(value, this->next);
	this->next = newNode;
}

void LinkedList::Node::removeNext()
{
	Node* removeNode = this->next;
	Node* newNext = removeNode->next;
	delete removeNode;
	this->next = newNext;
}

LinkedList::LinkedList()
	: _head(nullptr), _size(0)
{

}

LinkedList& LinkedList::operator=(const LinkedList& copyList)
{
	if (this == &copyList) {
		return *this;
	}

	forceNodeDelete(_head);
	LinkedList* bufList = new LinkedList(copyList);

	this->_size = bufList->_size;
	this->_head = bufList->_head;

	return *this;
}
LinkedList::LinkedList(const LinkedList& copyList)
{
	this->_size = copyList._size;
	if (this->_size == 0) {
		this->_head = nullptr;
		return;
	}

	this->_head = new Node(copyList._head->value);

	Node* currentNode = this->_head;
	Node* currentCopyNode = copyList._head;

	while (currentCopyNode->next) {
		currentCopyNode = currentCopyNode->next;
		currentNode->next = new Node(currentCopyNode->value);
		currentNode = currentNode->next;
	}
}
LinkedList::LinkedList(LinkedList&& moveList) noexcept
{
	this->_size = moveList._size;
	this->_head = moveList._head;

	moveList._size = 0;
	moveList._head = nullptr;
}

LinkedList& LinkedList::operator=(LinkedList&& moveList) noexcept
{
	if (this == &moveList) {
		return *this;
	}
	forceNodeDelete(_head);
	this->_size = moveList._size;
	this->_head = moveList._head;

	moveList._size = 0;
	moveList._head = nullptr;

	return *this;
}

LinkedList::~LinkedList()
{
	forceNodeDelete(_head);
	_size = 0;
}

ValueType& LinkedList::operator[](const size_t pos) const
{
	return getNode(pos)->value;
}

LinkedList::Node* LinkedList::getNode(const size_t pos) const
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

void LinkedList::insert(const size_t pos, const ValueType& value)
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
		bufNode->insertNext(value);
		++_size;
	}
}

void LinkedList::insertAfterNode(Node* node,  const ValueType& value)
{
	node->insertNext(value);
	_size++;
}

void LinkedList::pushBack(const ValueType& value)
{
	if (_size == 0) {
		pushFront(value);
		return;
	}
	insert(_size, value);
}

void LinkedList::pushFront(const ValueType& value)
{
	_head = new Node(value, _head);
	++_size;
}

void LinkedList::remove(const size_t pos)
{
	if (pos < 0) {
		assert(pos < 0);
	}
	else if (pos > this->_size-1) {
		assert(pos > this->_size-1);
	}

	if (pos == 0) {
		Node* bufNode = _head;
		_head = _head->next;
		delete bufNode;
		_size--;
	}
	else {
		Node* prevNode = this->_head;
		for (size_t i = 0; i < pos - 1; ++i) {
			prevNode = prevNode->next;
		}
		Node* delNode = prevNode->next;
		prevNode->next = delNode->next;
		delete delNode;

	 _size--;
	}
}

void LinkedList::removeNextNode(Node* node)
{
	if (node->next == nullptr) { 
		return;
	}
	Node* removeNode = node->next;
	Node* newNext = removeNode->next;
	delete removeNode;
	node->next = newNext;
	--_size;

}

void LinkedList::removeFront() {
	remove(0);
}

void LinkedList::removeBack() {
	remove(_size - 1);
}


long long int LinkedList::findIndex(const ValueType& value) const
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

LinkedList::Node* LinkedList::findNode(const ValueType& value) const
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

void LinkedList::reverse()
{
	Node* currentNode = _head;
	Node* prevNode = nullptr;
	Node* nextNode = nullptr;

	while (currentNode != nullptr) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	_head = prevNode;
}

LinkedList LinkedList::reverse() const
{
	LinkedList reversed (*this);
	reversed.reverse();

	return reversed;
}

LinkedList LinkedList::getReverseList() const
{
	LinkedList reversed = (*this);
	reversed.reverse();

	return reversed;
}

size_t LinkedList::size() const
{
	return _size;
}

void LinkedList::forceNodeDelete(Node* node)
{
	if (node == nullptr) {
		return;
	}

	Node* nextDeleteNode = node->next;
	delete node;
	forceNodeDelete(nextDeleteNode);
}
