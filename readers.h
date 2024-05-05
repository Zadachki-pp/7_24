#include <iostream>
#include <cstdint>

#include "base.h"


// N < 256 и a_i < 256, для всех i=1..N
// .txt - массив данных в формате N и a_i, где i=1..N (ASCII)
class TxtReader : public BaseInt8FileReader {
public:
    explicit TxtReader(const std::string& filename) : BaseInt8FileReader(filename) {}

    virtual ~TxtReader() {
        delete[] m_data;
    }

    void Read() override {
        int tmp;
        m_in >> tmp;
        m_n = tmp;
        m_data = new uint8_t[m_n];
        for (int i = 0; i < m_n; i++) {
            m_in >> tmp;
            m_data[i] = tmp;
        }
    }
};


// N < 256 и a_i < 256, для всех i=1..N
// .bin - массив данных в формате N и a_i, где i=1..N (bin)
class BinReader : public BaseInt8FileReader
{
public:
    explicit BinReader(const std::string& filename) : BaseInt8FileReader(filename) {}

    virtual ~BinReader() {
        delete[] m_data;
    }

    void Read() override {
        m_in.read((char*)&m_n, 1);
        m_data = new uint8_t[m_n];
        m_in.read((char*)m_data, m_n);
    }
};


//4 байта - количество чисел N (unsigned int).
//4*N байт - числа типа float.
class FBinReader : public BaseFloatFileReader
{
public:
    explicit FBinReader(const std::string& filename) : BaseFloatFileReader(filename) {}

    virtual ~FBinReader() {
        delete[] m_data;
    }

    void Read() override {
        m_in.read((char*)&m_n, 4);
        m_data = new float[m_n];
        m_in.read((char*)m_data, 4*m_n);
    }
};