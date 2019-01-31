#pragma once
#include "ErrorLogging.h"


static unsigned int uid = 0;

unsigned int GetNextUId() {
    return ++uid;
}
