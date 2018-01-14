#include "stdafx.h"
#include "Processor_1.h"
#include <array>
#include <numeric>

void Processor_1::Init()
{
	std::cout << "Start Init Processor_1" << std::endl;
	SC_CTHREAD(Task0, clock.pos());

	SC_METHOD(Task1);
	sensitive << clock.pos();
	SC_METHOD(Task2);
	sensitive << clock.pos();
	SC_METHOD(Task3);
	sensitive << clock.pos();
}

void Processor_1::Task0()
{
	std::array<int, 5> stateArray{};

	while (true)
	{
		int value;
		std::cin >> value;

		switch (value)
		{
		case 1:
			if (stateArray[0])
			{
				stateArray[0] = 0;
				stateArray[1] = 0;
				stateArray[2] = 0;
				stateArray[3] = 0;
				state.write(0);
			}
			else
			{
				stateArray[0] = 1;
				state.write(1);
			}
			break;
		case 2:
		case 3:
		case 4:
			if (stateArray[0])
			{
				if (stateArray[value - 1])
				{
					stateArray[value - 1] = 0;
					state.write(0);
				}	
				else
				{
					stateArray[value - 1] = 1;
					state.write(value);
				}	
				break;
			}
			break;
		case 5:
			if (stateArray[4])
			{
				state.write(0);
				stateArray[4] = 0;
			}	
			else
			{
				state.write(5);
				stateArray[4] = 1;
			}
			break;
		default:
			std::cout << "Bledne dane!!! Koniec programu!" << std::endl;
			sc_stop();
			exit(0);
		}

		queue.write(state.read());
		//system("cls");
		//for (unsigned int i = 0; i < stateArray.size(); ++i)
		//{
		//	std::cout << i + 1 << ". ma aktualnie stan " << stateArray[i] << std::endl;
		//}

		wait();
	}
}

void Processor_1::Task1()
{
	auto& value = state.read();
	std::cout << value << std::endl;
	if (value == 1)
		std::cout << "Task1: " << value << std::endl;

}

void Processor_1::Task2()
{
	auto& value = state.read();
	if (value == 2)
		std::cout << "Task2: " << value << std::endl;
}

void Processor_1::Task3()
{
	auto& value = state.read();
	if (value == 3)
		std::cout << "Task3: " << value << std::endl;
}
