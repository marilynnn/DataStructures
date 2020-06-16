#pragma once

#include "QueueImplementation.h"
#include "DoublyLinkedList.h"
#include <cstddef>

class DoubleListQueue : public QueueImplementation, public DoublyLinkedList
{
public:

	DoubleListQueue();

	DoubleListQueue(const DoubleListQueue& copyList);

	~DoubleListQueue() override {};

	// ���������� � �������
	void enqueue(const ValueType& value) override;

	// �������� � �������
	void dequeue() override;

	// ���������� ������� � "������"
	const ValueType& front() const override;

	// �������� �� �������
	bool isEmpty() const override;

	// ������
	std::size_t size() const override;

	
	
};