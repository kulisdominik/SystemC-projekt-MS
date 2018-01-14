#pragma once
#include <systemc.h>
#include "Task4.h"

struct Processor_1 : sc_module
{
	sc_in_clk clock;
	sc_fifo_out<int> queue;
	Task4 task4;
	sc_signal<sc_int<10>> state{ 0 };

	void Init();

	SC_CTOR(Processor_1)
		: task4("task4")
	{
		std::cout << "Start CTOR Processor_1" << std::endl;

		task4.clock(clock);
		task4.state(state);

		Init();
	}

	void Task0();
	void Task1();
	void Task2();
	void Task3();
};


