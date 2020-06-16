#include "ListQueue.h"

ListQueue::ListQueue() {}

ListQueue::ListQueue(const ListQueue& copyList) : SinglyLinkedList(copyList) {}

void ListQueue::enqueue(const ValueType& value) {

	pushBack(value);
}

void ListQueue::dequeue() {

	removeFront();
}

const ValueType& ListQueue::front() const {

	return getNode(0)->value;
}

bool ListQueue::isEmpty() const {

	return (SinglyLinkedList::size() == 0 ? true : false);

}
std::size_t ListQueue::size() const {

	return SinglyLinkedList::size();

}