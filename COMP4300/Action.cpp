#include "Action.h"

const std::string& Action::name() const
{
    // TODO: insert return statement here
    return m_name;
}

std::string Action::toString() const
{
    return std::string(m_name + " "+m_type);
}

const std::string& Action::type() const
{
    // TODO: insert return statement here
    return m_type;
}
