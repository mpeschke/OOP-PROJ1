/**
    stdafx.h
    Purpose: Pre-compiled header.

    Reference any additional headers you need here.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include <iostream>
#include <fstream>

#include "tchar_templates.hpp"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

namespace BLL {

const tstring gDirSeparator = _T("/");

}
