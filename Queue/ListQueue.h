#pragma once

#include "QueueImplementation.h"
#include "SinglyLinkedList.h" 
#include <cstddef>
// ������� � �������������� ����� ����������� ������ � �������������� ������������
// ���� �� ������ �� ��� ����������, �� ���� �� ������������ ������ �� ����������
// ������������� ������������ ����� �������� �� ����������
class ListQueue : public QueueImplementation, public SinglyLinkedList
{
public:

	ListQueue();

	ListQueue(const ListQueue& copyList);

	~ListQueue() override {};

	void enqueue(const ValueType& value) override;// ���������� � �������

	void dequeue() override;// �������� �� �������

	const ValueType& front() const override;// ���������� ������� � "������"

	bool isEmpty() const override;// �������� �� �������

	std::size_t size() const override;// ������

};
