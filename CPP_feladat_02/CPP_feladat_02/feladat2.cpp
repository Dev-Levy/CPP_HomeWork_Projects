#include "feladat2.h"
#include <malloc.h>

char* fifoStartPtr = nullptr;
char* fifoEndPtr = nullptr;
char* counter = nullptr;
char* popCounter = nullptr;
char* pushCounter = nullptr;

int NewFifo(int s) //done
{
	if (fifoStartPtr == nullptr || s <= 0) //van már FIFO || s<=0
	{
		fifoStartPtr = (char*)malloc(s);

		if (fifoStartPtr == nullptr) // memória allokáció sikertelen
			return -1;

		fifoEndPtr = fifoStartPtr + s;
		counter = fifoStartPtr;
		popCounter = fifoStartPtr;
		pushCounter = fifoStartPtr;
		return 0;
	}
	return -1;
}

int DeleteFifo(void) //done
{
	if (fifoStartPtr == nullptr) // nincs FIFO
		return -1;

	free(fifoStartPtr);
	fifoStartPtr = nullptr;
	return 0;
}

int Push(char c)
{
	if (fifoStartPtr == nullptr || fifoEndPtr == counter) // nincs FIFO || betelt a FIFO
		return -1;


	*pushCounter = c;
	pushCounter == fifoEndPtr - 1 ? pushCounter = fifoStartPtr : pushCounter++;

	counter++;
	return 0;
}

int Pop(void)
{
	if (fifoStartPtr == nullptr || fifoStartPtr == counter) // nincs FIFO || üres a tár
		return -1;

	char poppedData = *popCounter;
	popCounter == fifoEndPtr - 1 ? popCounter = fifoStartPtr : popCounter++;


	counter--;
	return poppedData;
}

int ClearFifo(void) //done
{
	if (fifoStartPtr == nullptr) // nincs FIFO
		return -1;

	int size = GetSize();
	for (size_t i = 0; i < size; i++)
	{
		*(fifoStartPtr + i) = NULL;
	}
	counter = fifoStartPtr;
	return 0;
}

int GetFree(void) // done
{
	if (fifoStartPtr == nullptr) // nincs FIFO
		return -1;
	int ans = fifoEndPtr - counter;

	return ans;
}

int GetSize(void) //done
{
	if (fifoStartPtr == nullptr) // nincs FIFO
		return -1;

	int fee = (int)fifoEndPtr;
	int foo = (int)fifoStartPtr;
	int length = fifoEndPtr - fifoStartPtr;

	return length;
}

int SetSize(int s)
{
	char* otherFifoStartPtr = nullptr;

	// nincs FIFO || s<=0 || memória allokáció sikertelen
	if (fifoStartPtr == nullptr || s <= 0 || !(otherFifoStartPtr = (char*)malloc(s)))
		return -1;


	char* source = fifoStartPtr;
	char* destination = otherFifoStartPtr;

	bool go = true;
	while (go) {

		*destination = *source;

		// ha az új, vagy régi FIFO végére ér megáll
		if (source == fifoEndPtr - 1 || destination == otherFifoStartPtr + s - 1)
			go = false;


		// popCounter, pushCounter átállítása
		if (source == popCounter)
			popCounter = destination;
		if (source == pushCounter)
			pushCounter = destination;

		source++;
		destination++;
	}

	free(fifoStartPtr);

	fifoStartPtr = otherFifoStartPtr;
	fifoEndPtr = fifoStartPtr + s;
	counter = destination;

	return 0;
}
