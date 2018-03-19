#pragma once

#ifndef __RPG_RANDOM_H__
#define __RPG_RANDOM_H__

#include "Range.h"

int Random(const Range& range);
int Random(int lowest, int highest);

#endif // __RPG_RANDOM_H__