#include "StaticLib.h"
#include <string>


namespace lib	{

	std::string Greeter::ret_name(std::string z) {
		std::string z2 = ("Приветствую, " + z + " !\n");
		return z2;
	}

}