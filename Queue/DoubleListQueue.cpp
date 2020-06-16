#include "DoubleListQueue.h"

DoubleListQueue::DoubleListQueue() {}

DoubleListQueue::DoubleListQueue(const DoubleListQueue& copyList) : DoublyLinkedList(copyList) {}

void DoubleListQueue::enqueue(const ValueType& value) {

	pushBack(value);
}

void DoubleListQueue::dequeue() {

	removeFront();
}


const ValueType& DoubleListQueue::front() const {

	return(*this)[0];

}

bool DoubleListQueue::isEmpty() const {

	return (DoublyLinkedList::size() == 0 ? true : false);

}

std::size_t DoubleListQueue::size() const {

	return DoublyLinkedList::size();

}
