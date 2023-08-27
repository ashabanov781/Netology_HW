#include <string>
#include "DynamicLib.h"


namespace lib_dynamic {

	std::string Leaver::leave(std::string z) {
		std::string z2 = ("До свидания, " + z + " !\n");
		return z2;
	}

}