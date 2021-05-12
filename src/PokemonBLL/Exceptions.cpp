/**
    CException.cpp
    Purpose: Exceptions for the BLL namespace.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "stdafx.h"
#include "Exceptions.hpp"

namespace BLL {

CExcecao::CExcecao(const std::string& what)
: m_exception(what)
{}

CExcecao::~CExcecao()
{}

const char* CExcecao::what() const throw()
{return this->m_exception.c_str();}

} /* namespace BLL */
