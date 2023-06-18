#include "InvalidOptionException.hpp"

InvalidOptionException::InvalidOptionException(std::string error)
    : m_error(std::move(error))
{
}

const char* InvalidOptionException::what() const noexcept
{
    return m_error.c_str();
}
