// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include "TreasureMap.h"

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
           std::ofstream file(filename, std::ios::out | std::ios::binary);
           if (file) {
              file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
              file.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));
              for (std::size_t i = 0; i < rows; i++) {
                 file.write(&(map[i][0]), map[i].size());
              }
           }
           else {
              throw("Error: Cannot open file!");
           }
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
       std::ifstream file(filename, std::ios::in | std::ios::binary);
       if (file) {
          file.read(reinterpret_cast<char*>(&rows), sizeof(rows));
          file.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));
          map = new std::string[rows];
          for (std::size_t i = 0; i < rows; i++) {
             map[i].resize(colSize);   // Make sure there's enough room
             file.read(reinterpret_cast<char*>(&(map[i][0])), colSize);
          }
       }
       else {
          throw("Error: Cannot open file!");
       }
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        for (size_t i = 0; i < rows; ++i){
            count += digForTreasure(map[i], mark);
        }

        return count;
    }
}