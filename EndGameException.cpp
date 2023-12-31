#include "EndGameException.hpp"

EndGameException::EndGameException(std::string error) : m_error(error)
{}  

const char* EndGameException::what() const noexcept
{
    return m_error.c_str();
}