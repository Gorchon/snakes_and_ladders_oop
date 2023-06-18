#include "InvalidConfigurationException.hpp"

InvalidConfigurationException::InvalidConfigurationException(std::string error)
    : m_error(std::move(error))
{
}

const char* InvalidConfigurationException::what() const noexcept
{
    return m_error.c_str();
}
