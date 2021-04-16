#ifndef Engine_ElieDebug_H
#define Engine_ElieDebug_H
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
#define DEBUG ElieDebug::GetDebug()
/**
*   Singleton Logger Class.
*/
class ElieDebug
{
public:
    /**
    *   Logs a message
    *   @param sMessage message to be logged.
    */
    void Log(const std::string& sMessage);
    /**
    *   Variable Length Logger function
    *   @param format string for the message to be logged.
    */
    void Log(const char * format, ...);
    /**
    *   << overloaded function to Logs a message
    *   @param sMessage message to be logged.
    */
    ElieDebug& operator<<(const string& sMessage);
    /**
    *   Funtion to create the instance of logger class.
    *   @return singleton object of ElieDebug class..
    */
    static ElieDebug* GetDebug();
private:
    /**
    *    Default constructor for the Logger class.
    */
    ElieDebug();
    /**
    *   copy constructor for the Logger class.
    */
    ElieDebug(const ElieDebug&){};             // copy constructor is private
    /**
    *   assignment operator for the Logger class.
    */
    ElieDebug& operator=(const ElieDebug&){ return *this; };  // assignment operator is private
    /**
    *   Log file name.
    **/
    static const std::string m_sFileName;
    /**
    *   Singleton logger class object pointer.
    **/
    static ElieDebug* m_pThis;
    /**
    *   Log file stream object.
    **/
    static ofstream m_Logfile;
};
#endif