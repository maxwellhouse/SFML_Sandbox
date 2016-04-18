#include "ResourceBase.h"


tBaseResource::tBaseResource(const std::string& path, const eResourceType type) :
    m_Path(path)
    , m_Type(type)
    , m_IsLoaded(false)
{
}

tBaseResource::~tBaseResource()
{}

tBaseResource::eResourceType tBaseResource::Type() const
{
    return m_Type;
}

std::string tBaseResource::Path() const
{
    return m_Path;
}

bool tBaseResource::IsLoaded() const
{
    return m_IsLoaded;
}

void tBaseResource::SetLoaded(bool loaded)
{
    m_IsLoaded = loaded;
}
