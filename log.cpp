#include "log.hpp"
using namespace std;

Logger getLogger()
{
	return {};
}

Logger getLogger(const std::string& fileName)
{
	return {fileName};
}

Logger getLogger(const std::string& fileName,
	const std::string& prefix)
{
	return {fileName, prefix};
}
