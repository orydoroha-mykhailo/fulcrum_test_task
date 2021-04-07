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
			fout.open(fileName, std::ios::app);
		}
		Logger& operator()(const logLvl& lvl);

		template<typename T>
		Logger& operator<<(const T& message)
		{
			std::time_t now = std::time(0);
			time = std::ctime(&now);
			time.pop_back();
			logs << message;
			return *this;
		}
		~Logger()
		{
			std::stringstream ss;
			ss << time
				<< "; "<< whatLevel() 
				<< "; "<< prefix << "(" << std::this_thread::get_id() 
				<< "): " << logs.str() << std::endl;
			if(isFile)
				if(fout.good())
				{
					fout << ss.str();
				}else{}
			else
				std::cout << ss.str();
		}
  private:
		std::string whatLevel() const;
		std::string time;
		std::ostringstream logs;
		const bool isFile = true;
		std::ofstream fout;
		const std::string prefix = "";
		logLvl lvl = logLvl::INFO;
};

Logger getLogger();
Logger getLogger(const std::string& fileName);
Logger getLogger(const std::string& fileName, const std::string& prefix);