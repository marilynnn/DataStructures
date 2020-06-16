#include "Queue.h"
#include "ListQueue.h"
#include "VectorQueue.h"
#include "DoubleListQueue.h"
#include "QueueImplementation.h"

#include <stdexcept>

Queue::Queue(QueueContainer container)
	: _containerType(container)
{
	switch (container)
	{
	case QueueContainer::SinglyLinkedList: {
		_pimpl = new ListQueue();
		break;
	}
	case QueueContainer::Vector: {
		_pimpl = new VectorQueue();
		break;
	}
	case QueueContainer::DoublyLinkedList: {
		_pimpl = new DoubleListQueue();
		break;
	}
	default:
		throw std::runtime_error("����������� ��� ����������");
	}
}

Queue::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container) : Queue(container) {
	for (size_t i = 0; i < arraySize; i++) {
		_pimpl->enqueue(valueArray[i]);
	}
}

Queue::Queue(const Queue& copyQueue) : Queue(copyQueue._containerType) {
	switch (_containerType) {
	case QueueContainer::SinglyLinkedList: {
		_pimpl = new ListQueue(*(static_cast<ListQueue*>(copyQueue._pimpl)));
		break;
	}
	case QueueContainer::Vector: {
		_pimpl = new VectorQueue(*(static_cast<VectorQueue*>(copyQueue._pimpl)));
		break;
	}
	case QueueContainer::DoublyLinkedList: {
		_pimpl = new DoubleListQueue(*(static_cast<DoubleListQueue*>(copyQueue._pimpl)));
		break;
	}
	default:
		throw std::runtime_error("����������� ��� ����������");
	}
}

Queue& Queue::operator=(const Queue& copyQueue) {

	if (this == &copyQueue) {
		return *this;
	}

	delete _pimpl;
	_containerType = copyQueue._containerType;


	switch (_containerType) {
	case QueueContainer::SinglyLinkedList: {
		_pimpl = new ListQueue(*(static_cast<ListQueue*>(copyQueue._pimpl)));
		break;
	}
	case QueueContainer::Vector: {
		_pimpl = new VectorQueue(*(static_cast<VectorQueue*>(copyQueue._pimpl)));
		break;
	}
	case QueueContainer::DoublyLinkedList: {
		_pimpl = new DoubleListQueue(*(static_cast<DoubleListQueue*>(copyQueue._pimpl)));
		break;
	}
	default:
		throw std::runtime_error("����������� ��� ����������");
	}

	return *this;
}

Queue::Queue(Queue&& moveQueue) noexcept {

	_containerType = moveQueue._containerType;

	delete _pimpl;
	_pimpl = moveQueue._pimpl;
	moveQueue._pimpl = nullptr;
}

Queue& Queue::operator=(Queue&& moveQueue) noexcept {

	if (this == &moveQueue) {
		return *this;
	}
	_containerType = moveQueue._containerType;
	delete _pimpl;
	_pimpl = moveQueue._pimpl;
	moveQueue._pimpl = nullptr;

	return *this;
}

Queue::~Queue()
{
	delete _pimpl;		// ����������!
}

void Queue::enqueue(const ValueType& value)
{
	// �����, �.�. push ��������� � ����������
	_pimpl->enqueue(value);
}

void Queue::dequeue()
{
	_pimpl->dequeue();
}

const ValueType& Queue::front() const
{
	return _pimpl->front();
}

bool Queue::isEmpty() const
{
	return _pimpl->isEmpty();
}

size_t Queue::size() const
{
	return _pimpl->size();
}