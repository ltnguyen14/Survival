#pragma once
#include "ErrorLogging.h"

namespace util {
	static unsigned int uid = 0;

	static unsigned int GetNextUId() {
		return ++uid;
	}
}
