#include <iostream>
#include <memory>
#include "MyShared_ptr.h"

using namespace std;

int main()
{
	MyShared_ptr<int> shared_ptr1(new int(0));
	MyShared_ptr<int> shared_ptr2 = shared_ptr1;
	int count = shared_ptr1.GetReferenceCount();

	cout << count << endl;

	{
		MyShared_ptr<int> shared_ptr3 = shared_ptr2;

		int count2 = shared_ptr3.GetReferenceCount();
		cout << count2 << endl;
	}

	int count3 = shared_ptr2.GetReferenceCount();
	cout << count3 << endl;

	return 0;
}