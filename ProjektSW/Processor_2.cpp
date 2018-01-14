#include "stdafx.h"
#include "Processor_2.h"

void Processor_2::Task5()
{
	while (true)
	{
		auto value = queue.read();
		if (value == 5)
			std::cout << "Task5: " << value << std::endl;
	}
}
