#include "dlog.h"

void dlog::cout(const std::string& text)
{
	std::cout << text << std::endl;
}

void dlog::error(const std::string& text)
{
	std::cout << "Error: " << text << std::endl;
}
