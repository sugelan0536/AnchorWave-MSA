//
// Created by baoxing on 10/10/17.
//

#include "readFastaFile.h"

void readFastaFile(const std::string &filePath, std::map<std::string, std::tuple<std::string, long, long, int> > &map) {
    std::ifstream infile(filePath);
    if (!infile.good()) {
        std::cerr << "error in opening fasta file " << filePath << std::endl;
        exit(1);
    }

    std::string name = "";
    std::stringstream ss;
    std::string line = "";

    long offset = 0;
    size_t size = 0;
    size_t line_bases = 0;
    size_t line_last = 0;

    while (std::getline(infile, line)) {

        if (line[0] == '>') {
            if (name.size() > 0) {
                map[name] = std::make_tuple(filePath, size, offset, line_bases);

                if(line_last == line_bases) {
                    offset += size + size/line_bases;
                }
                else {
                    offset += size + size/line_bases + 1;
                }
            }

            size = 0;

            name = line.substr(1, line.find(" ", 0) - 1);
            offset += line.size() + 1;
            if (name[0] == '>') {
                name = name.substr(1, name.find("\t", 0) - 1);
            } else {
                name = name.substr(0, name.find("\t", 0) - 1);
            }
        } else {
            size += line.size();
            line_last = line.size();

            if(line.size() > line_bases) {
                line_bases = line.size();
            }
        }
    }

    if (name.size() > 0) {
        map[name] = std::make_tuple(filePath, size, offset, line_bases);
    }

    infile.close();
}

void readFastaFileWorkWithIUPACcode(const std::string &filePath, std::map<std::string, std::string> &sequences) {
    std::ifstream infile(filePath);
    if (!infile.good()) {
        std::cerr << "error in opening fasta file " << filePath << std::endl;
        exit(1);
    }

    std::string name;
    std::stringstream sequencestream;
    std::string line;
    while (std::getline(infile, line)) {
        if (line[0] == '>') { // changed on 19 Sep, 2018, by reading the source code from Heng, Li.
            // this method is faster than regular expression
            if (!name.empty()) {
                std::string sequence = sequencestream.str();
                transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);
                sequences[name] = sequence;
            }

            name = line.substr(1, line.find(' ', 0) - 1);
            if (name[0] == '>') {
                name = name.substr(1, name.find('\t', 0) - 1);
            } else {
                name = name.substr(0, name.find('\t', 0) - 1);
            }
            sequencestream.str(std::string());
        } else {
            sequencestream << line;
        }
    }

    if (!name.empty()) {
        std::string sequence = sequencestream.str();
        if (!sequence.empty()) {
            transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);
            sequences[name] = sequence;
        }
    }

    infile.close();
}
