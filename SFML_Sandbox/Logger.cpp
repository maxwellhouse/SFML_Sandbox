#include "Logger.h"


tLogger::tLogger(bool logToConsole) :
    m_LogToConsole(logToConsole)
{
    m_OutFile.open("./log", std::ofstream::out);
}

tLogger::~tLogger()
{
    m_OutFile.close();
}

bool tLogger::LogToConsole() const
{
    return m_LogToConsole;
}

void tLogger::SetLogToConsole(bool logToConsole)
{
    m_LogToConsole = logToConsole;
}

void tLogger::Log(const std::string& message) 
{
    if (m_LogToConsole)
    {
        std::cerr << message.c_str() << std::endl;
    }
    m_OutFile << message << std::endl;
}