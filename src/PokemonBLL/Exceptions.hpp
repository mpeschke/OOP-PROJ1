/**
    Exceptions.hpp
    Purpose: Exceptions for the BLL namespace.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include <string>
#include <exception>

namespace BLL {

class CExcecao: protected std::exception
{
private:
    std::string m_exception;
public:
    CExcecao(const std::string& what);
    virtual ~CExcecao();
public:
    virtual const char* what() const throw();
};

}