#pragma once
#include "Logger.h"

class tLocator
{
public:
    static void InitializeLogger() { m_pLogger = &m_NullLogger; }

    static tLogger& GetLogger() { return *m_pLogger; }

    static void ProvideLogger(tLogger* service)
    {
        if (service == NULL)
        {
            // Revert to null service.
            m_pLogger = &m_NullLogger;
        }
        else
        {
            m_pLogger = service;
        }
    }

private:
    static tLogger* m_pLogger;
    static tNullLogger m_NullLogger;
};
