#include <thread>
#include "log.hpp"

/*
Example of console output:
23.02.2020 18:06:06; INFO; (1020): Starting the app
23.02.2020 18:06:06; DEBUG; (2561): Running a thread

Example of log.txt output:
23.02.2020 18:06:06; INFO; (2561): Running a thread
23.02.2020 18:06:06; DEBUG; f2(3444): Running a thread
23.02.2020 18:06:06; WARNING; f2(3444): Time spent in the thread: 10.0 seconds

Example of log2.txt:
23.02.2020 18:06:06; INFO; f3(3444): Running a thread
23.02.2020 18:06:06; ERROR; f3(3444): My int is 123;
*/

using llv = logLvl;

void f1() {
    //auto consoleLogger = getLogger(); // Log to console
    // Console output: 23.02.2020 18:06:06; DEBUG; (2561): Running a thread
    getLogger()(llv::DEBUG) << "Running a thread";

    //auto fileLogger = getLogger("log.txt"); // Log to file with name log.txt
    // File output: 23.02.2020 18:06:06; INFO; (2561): Running a thread
    getLogger("log.txt") << "Running a thread"; // Default log level INFO
}

void f2() {
    //getLogger("log.txt", "f2"); // Log to file with name log.txt. Each message has f2 prefix
    // File output: 23.02.2020 18:06:06; DEBUG; f2(3444): Running a thread
    getLogger("log.txt", "f2")(llv::DEBUG) << "Running a thread";

    double timeSpent = 10.0;
    // File output: 23.02.2020 18:06:06; WARNING; f2(3444): Time spent in the thread: 10.0 seconds
    getLogger("log.txt", "f2")(llv::WARNING) << "Time spent in the thread: " << timeSpent << " seconds";
}

void f3() {
    //auto logger = getLogger("log2.txt", "f3");  // Log to file with name log2.txt. Each message has f3 prefix
    // File output: 23.02.2020 18:06:06; INFO; f3(3444): Running a thread
    getLogger("log2.txt", "f3") << "Running a thread"; // Default log level INFO

    int i = 123;
    // File output: 23.02.2020 18:06:06; ERROR; f3(3444): My int is 123;
    getLogger("log2.txt", "f3")(llv::ERROR) << "My int is " << i;
}

int main() {
    //auto logger = getLogger(); // Log to console
    // Console output: 23.02.2020 18:06:06; INFO; (1020): Starting the app
    getLogger() << "Starting the app"; // Default log level INFO

    std::thread t1(f1);
    std::thread t2(f2);
    std::thread t3(f3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
