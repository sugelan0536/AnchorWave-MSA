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

#pragma once

#include <iostream>
#include "InputParser.h"
#include <sstream>
#include <vector>
#include "./model/AlignmentMatch.h"
#include "./service/TransferGffWithNucmerResult.h"
#include "./impl/getSequencesFromGff.h"
#include "./impl/deNovoGenomeVariantCalling.h"
#include "./myImportandFunction/alignSlidingWindow.h"
#include "./version.h"

int gff2seq(int argc, char **argv);

int genomeAlignment(int argc, char **argv);

int proportionalAlignment(int argc, char **argv);

int ali(int argc, char **argv);
