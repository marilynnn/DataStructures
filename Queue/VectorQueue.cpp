#include "VectorQueue.h"

VectorQueue::VectorQueue() {}

VectorQueue::VectorQueue(const VectorQueue& copyVector) : Vector(copyVector) {}
	
void VectorQueue::enqueue(const ValueType& value) {

	pushBack(value);

}

void VectorQueue::dequeue() {

	erase(0);

}

const ValueType& VectorQueue::front() const {

	return(*this)[0];

}


	
bool VectorQueue::isEmpty() const {

	return (Vector::size() == 0 ? true : false);

}

size_t VectorQueue::size() const {

	return Vector::size();

}