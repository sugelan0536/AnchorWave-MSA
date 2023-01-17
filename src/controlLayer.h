/*
 * =====================================================================================
 *
 *       Filename:  controlLayer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/25/2017 09:38:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Baoxing Song (songbx.me), songbaoxing168@163.com
 *
 * =====================================================================================
 */

#ifndef _CONTROLLAYER_H
#define _CONTROLLAYER_H

#include <iostream>
#include "InputParser.h"
#include <sstream>
#include "./util/util.h"
#include "./model/model.h"
#include "./service/service.h"
#include "./impl/impl.h"
#include "./myImportandFunction/myImportantFunction.h"
#include "./version.h"

int gff2seq(int argc, char **argv);

int genomeAlignment(int argc, char **argv);

int proportationalAlignment(int argc, char **argv);

int ali(int argc, char **argv);

#endif
