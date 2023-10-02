#pragma once
#include <string>


#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARYDYNAMIC_EXPORTS __declspec(dllexport)
#else
#define LIBRARYDYNAMIC_EXPORTS __declspec(dllimport)
#endif

namespace lib_dynamic
{
	class Leaver
	{
	public:
		LIBRARYDYNAMIC_EXPORTS std::string leave(std::string z);
	};
}