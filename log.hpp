#pragma once
#include <iostream>
#include <fstream>

enum class logLvl{
	INFO,
	DEBUG,
	WARNING,
	ERROR
};

class Logger{
  public: 
	Logger() : isFile(false) {}
	Logger(const std::string& fileName, const std::string& prefix = ""): prefix(prefix)
	{
		fout.open(fileName);
	}
	Logger& operator()(const logLvl& lvl);

	template<typename T>
	Logger& operator<<(const T& message);

  private:
		const bool isFile = false;
		std::ofstream fout;
		const std::string prefix = "";
		logLvl lvl = logLvl::INFO;
};

Logger getLogger();
Logger getLogger(const std::string& fileName);
Logger getLogger(const std::string& fileName, const std::string& prefix);