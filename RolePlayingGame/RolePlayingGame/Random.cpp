#include <cstdlib>

#include "Random.h"

int Random(const Range & range)
{
	return (range.lowest + rand() % ((range.highest + 1) - range.lowest));
}

int Random(int lowest, int highest)
{
	return (lowest + rand() % ((highest + 1) - lowest));
}
