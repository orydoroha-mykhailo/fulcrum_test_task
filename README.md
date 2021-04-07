# Simple logger
## _About_
This is a simple logger.

- Supports next log levels: **info, debug, warning, error**.
- Supports logging to custom text file or console window. The client is able to choose which output to use.
- Supports multi-threaded environment, where several threads could log to same file.
- The client is able to set a custom prefix, which appends automatically to each message.
- Each log message starts with date and time.

## _Usage_
```c++
// destination: standart output
getLogger() << "Starting the app"; // Default log level INFO

// stdout:
// Wed Apr  7 11:53:56 2021; INFO; (140181488551744): Starting the app

// destination: log.txt
getLogger("log.txt", "f2")(llv::DEBUG) << "Running a thread";
double timeSpent = 10.0;
getLogger("log.txt", "f2")(llv::WARNING) << "Time spent in the thread: " << timeSpent << " seconds";

/* log.txt:
Wed Apr  7 11:53:56 2021; DEBUG; f2(140181480154688): Running a thread
Wed Apr  7 11:53:56 2021; WARNING; f2(140181480154688): Time spent in the thread: 10 seconds
*/

// destination: log2.txt
getLogger("log2.txt", "f3") << "Running a thread"; // Default log level INFO
int i = 123;
getLogger("log2.txt", "f3")(llv::ERROR) << "My int is " << i;

/* log2.txt:
Wed Apr  7 11:53:56 2021; INFO; f3(140181337544256): Running a thread
Wed Apr  7 11:53:56 2021; ERROR; f3(140181337544256): My int is 123
*/


```
