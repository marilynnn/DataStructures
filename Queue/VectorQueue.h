#pragma once
#include "QueueImplementation.h"
#include "Vector.h"
#include <cstddef>

// ������� � �������������� ����� ����������� ������� � �������������� ������������
// ���� �� ������ �� ��� ����������, �� ���� �� ������������ ������ �� ����������
// ������������� ������������ ����� �������� �� ����������

class VectorQueue : public QueueImplementation, public Vector
{
public:
	VectorQueue();

	VectorQueue(const VectorQueue& copyQueue);

	~VectorQueue() override {};

	// ���������� � �����
	void enqueue(const ValueType& value) override;

	// �������� � ������
	void dequeue() override;

	// ���������� ������� � ������
	const ValueType& front() const override;

	// �������� �� �������
	bool isEmpty() const override;

	// ������ 
	size_t size() const override;
};
