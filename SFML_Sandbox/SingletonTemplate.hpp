#pragma once
#include <stddef.h>
#include <assert.h>

template<class T>
class tSingleton
{
public:
    static T* Instance() {
        if (m_pInstance == nullptr)
            m_pInstance = new T;
        assert(m_pInstance);
        return m_pInstance;
    }
protected:
    tSingleton() {};
    ~tSingleton() {};

private:
    tSingleton(const tSingleton&) {};
    tSingleton& operator=(const tSingleton&) {};
    static T* m_pInstance;
};

template<class T> T* tSingleton<T>::m_pInstance = nullptr;