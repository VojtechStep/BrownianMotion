#include <iostream>
#include <stdint.h>
#include <time.h>
#include <conio.h>
#include "Recorder.h"

class timer
{
private:
	uint64_t m_Begin;
public:
	void start()
	{
		m_Begin = clock();
	}
	double elapsed()
	{
		return ((double)clock() - m_Begin) / CLOCKS_PER_SEC;
	}
};

char tryReadKey()
{
	if (!_kbhit()) return -1;
	return _getch();
}

int main(int argc, char** argv)
{
	Recorder rec0(0, "out0.avi", { 640, 480 }, 10.0);
	Recorder rec1(1, "out1.avi", { 640, 480 }, 10.0);
	timer t;

	std::cout << "Starting capture" << std::endl;

	t.start();
	do
	{
		rec0.grab();
		rec1.grab();
		rec0.retrieve();
		rec1.retrieve();
		rec0.write();
		rec1.write();
	} while (tryReadKey() != 27);

	std::cout << "Done " << std::endl;

	return 0;
}
