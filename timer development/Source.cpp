#ifndef _SOURCE_
#define _SOURCE_

#include "timer.h"
#include <iostream>
#include <string>

using namespace std;

counter* checkTiming;

int main(int argc, char *argv[])
{
	checkTiming = new counter();
	FILE* log;
	log = fopen("greg.txt", "w");
	int holdOver = 0;
	for(int i = 0; i < 4000000; i++)
	{
	string greg;
	checkTiming -> updateSystem();
	if(holdOver != checkTiming -> getInc())
	{
	fprintf(log, 
		"Current Inc: %d\nCurrent Recorded timing: %d \nCurrent System Timing: %d \n",
		checkTiming -> getInc(), checkTiming -> checkTime(), time(0));
	holdOver = checkTiming -> getInc();
	}
	}
	fclose(log);
	return 0;
}

#endif