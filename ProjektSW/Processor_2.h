#pragma once
#include <systemc.h>

struct  Processor_2 : sc_module
{
	sc_in_clk clock;
	sc_fifo_in<int> queue;

	void Task5();

	SC_CTOR(Processor_2)
	{
		std::cout << "Start CTOR Processor_2" << std::endl;

		SC_THREAD(Task5);
		sensitive << clock.pos();
	}
};

