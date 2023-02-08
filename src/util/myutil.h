// =====================================================================================
// 
//       Filename:  myutil.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  04/12/2017 04:26:31 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Baoxing Song (songbx.me), songbaoxing168@163.com
//
// =====================================================================================
#pragma once

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "nucleotideCodeSubstitutionMatrix.h"

void split(const std::string &s, char &delim, std::vector<std::string> &elems);

std::string songStrReplaceAll(std::string &str, const std::string &pattern, const std::string &pattern2);

int32_t min(const int32_t &a, const int32_t &b);

void splitCIGAR(std::string cigarString, std::vector<std::string> &cigarElems);
