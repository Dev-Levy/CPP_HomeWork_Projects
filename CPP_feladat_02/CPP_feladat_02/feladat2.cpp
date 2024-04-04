#include "feladat2.h"
#include <malloc.h>

//Oláh Levente - A3C6TV - feladat2 - V3 - Pótlás


static char* fifoStartPtr = nullptr;
static char* fifoEndPtr = nullptr;

static int counter;
static int out;
static int in;


int NewFifo(int s) //done
{
	if (fifoStartPtr != nullptr || s <= 0) //van már FIFO || s<=0	
		return -1;

	fifoStartPtr = (char*)malloc(s);

	if (fifoStartPtr == nullptr) // memória allokáció sikertelen
		return -1;

	fifoEndPtr = fifoStartPtr + s;

	counter = 0;
	out = 0;
	in = 0;

	return 0;
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
	if (fifoStartPtr == nullptr || fifoEndPtr == fifoStartPtr + counter) // nincs FIFO || betelt a FIFO
		return -1;

	*(fifoStartPtr + in) = c;

	fifoStartPtr + in == fifoEndPtr - 1 ? in = 0 : in++;

	counter++;
	return 0;
}

int Pop(void)
{
	if (fifoStartPtr == nullptr || counter == 0) // nincs FIFO || üres a tár
		return -1;

	unsigned char poppedData = *(fifoStartPtr + out);
	fifoStartPtr + out == fifoEndPtr - 1 ? out = 0 : out++;

	counter--;

	int result = 0xFF & poppedData;
	//255-nél -1et adna vissza enélkül
	return result;
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
	counter = 0;
	return 0;
}

int GetFree(void) // done
{
	if (fifoStartPtr == nullptr) // nincs FIFO
		return -1;
	int asd = fifoEndPtr - (fifoStartPtr + counter);

	return asd;
}

int GetSize(void) //done
{
	if (fifoStartPtr == nullptr) // nincs FIFO
		return -1;

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
		if (source == fifoStartPtr + out)
			out = destination - otherFifoStartPtr;
		if (source == fifoStartPtr + in)
			in = destination - otherFifoStartPtr;

		source++;
		destination++;
	}

	free(fifoStartPtr);

	fifoStartPtr = otherFifoStartPtr;
	fifoEndPtr = fifoStartPtr + s;
	fifoEndPtr - fifoStartPtr < counter ? counter = fifoEndPtr - fifoStartPtr : counter;

	return 0;
}
