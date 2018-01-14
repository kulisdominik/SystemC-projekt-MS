#include "stdafx.h"
#include "Task4.h"

void Task4::Task()
{
	auto value = state.read();
	if (value == 4)
		std::cout << "Task4: " << value << std::endl;
}
