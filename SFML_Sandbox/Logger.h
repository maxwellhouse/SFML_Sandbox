#pragma once
#include <string>
#include <fstream>
#include <iostream>

class tLogger
{
public:
    tLogger(bool logToConsole);
    ~tLogger();

    virtual bool LogToConsole() const;
    virtual void SetLogToConsole(bool logToConsole);
    virtual void Log(const std::string& message);
private:
    bool m_LogToConsole;
    std::ofstream m_OutFile;
};

class tNullLogger : public tLogger
{
public:
    tNullLogger() : tLogger(false) {}
public:
    virtual void Log(const std::string& message) { /* Do nothing. */ }
};