#pragma once
#include <iostream>
#include <thread>
#include <ctime>
#include <fstream>
#include <sstream>

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
		Logger& operator<<(const T& message)
		{
			time_t now = time(0);
			std::stringstream ss;
			std::string time = ctime(&now);
			time.pop_back();
			ss << time
				<< "; "<< whatLevel() 
				<< "; "<< prefix << "(" << std::this_thread::get_id() 
				<< "): " << message << std::endl;
			if(isFile)
				if(fout.good())
					fout << ss.str();
					else{}
			else 
				std::cout << ss.str();
			return *this;
		}
  private:
		std::string whatLevel() const;

		const bool isFile = true;
		std::ofstream fout;
		const std::string prefix = "";
		logLvl lvl = logLvl::INFO;
};

Logger getLogger();
Logger getLogger(const std::string& fileName);
Logger getLogger(const std::string& fileName, const std::string& prefix);