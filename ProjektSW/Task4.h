#pragma once
#include <systemc.h>

struct Task4 : public sc_module
{
	sc_in_clk clock;
	sc_in<sc_int<10>> state;

	void Task();

	SC_CTOR(Task4)
	{
		SC_METHOD(Task);
		sensitive << clock.pos();
	}
};

