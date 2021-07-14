#pragma once

template <typename T>
class MyShared_ptr
{
public:
	MyShared_ptr(T* object) : pointer(object), referenceCount(new int(1)) {}
	~MyShared_ptr()
	{
		if (!--(*referenceCount))	
		{
			delete pointer;
			delete referenceCount;
		}
	}

	// 복사 생성자 - 얕은 복사 
	MyShared_ptr(const MyShared_ptr& other)
	{
		this->pointer = other.pointer;
		this->referenceCount = other.referenceCount;
		(*referenceCount)++;
	}

	MyShared_ptr& operator = (const MyShared_ptr& other)
	{
		this->pointer = other.pointer;
		this->referenceCount = other.referenceCount;
		(*referenceCount)++;
		
		return *this;
	}

	int GetReferenceCount() { return *referenceCount; }
	
public:
	T* pointer;
	int* referenceCount;
};

