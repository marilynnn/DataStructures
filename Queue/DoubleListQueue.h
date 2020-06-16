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

	// добавление в очередь
	void enqueue(const ValueType& value) override;

	// удаление с очереди
	void dequeue() override;

	// посмотреть элемент в "голове"
	const ValueType& front() const override;

	// проверка на пустоту
	bool isEmpty() const override;

	// размер
	std::size_t size() const override;

	
	
};