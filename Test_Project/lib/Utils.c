#include "Utils.h"

void dec2bin(int dec, Bit *bin){

	for (int i = 7; i >= 0; --i)
	{
		bin[i].bit = dec%2;
		dec /= 2;
	}
}
