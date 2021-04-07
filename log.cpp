#include "log.hpp"
#include <thread>
#include <type_traits>
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

Logger& Logger::operator()(const logLvl& lvl)
{
	this->lvl = lvl;
	return *this;
}

string Logger::whatLevel() const
{
	switch (lvl)
	{
	case logLvl::INFO:
		return "INFO";
	case logLvl::DEBUG:
		return "DEBUG";
	case logLvl::WARNING:
		return "WARNING";
	case logLvl::ERROR:
		return "ERROR";
	}
	return {};
}