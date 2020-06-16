#include "ListStack.h"

ListStack::ListStack() {};

ListStack::ListStack(const ListStack& copyList) : LinkedList (copyList) {};


void ListStack::push(const ValueType& value) {

	pushFront(value);

};

void ListStack::pop() {

	removeFront();

};

const ValueType& ListStack::top() const {

	return getNode(0)->value;

};

bool ListStack::isEmpty() const {

	return (LinkedList::size() == 0 ? true : false);

};

std::size_t ListStack::size() const {

	return LinkedList::size();

};