#include "stdafx.h"
#include "Processor_1.h"
#include "Processor_2.h"

int sc_main(int argc, char** argv)
{
	sc_clock clock("clock_main", 1, 0.5);
	sc_fifo<int> queue;

	Processor_1 processor_1("processor_1");
	processor_1.clock(clock);
	processor_1.queue(queue);

	Processor_2 processor_2("processor_2");
	processor_2.clock(clock);
	processor_2.queue(queue);

	sc_start();
	return 0;
}