#include <iostream>
#include <fstream>
#include <cstdint>

#include "abc.h"


class BaseInt8FileReader : public ABCUInt8Reader {
protected:
    std::ifstream m_in;
    std::string m_filename;

    uint8_t* m_data;
    uint8_t m_n;
public:
    explicit BaseInt8FileReader(const std::string& filename) : m_filename(filename), m_data(nullptr), m_n(0) {}

    bool Open() override {
        m_in.open(m_filename);
        if (!m_in.is_open())
            return false;
        return true;
    }

    void Close() override {
        m_in.close();
    }

    void GetData(uint8_t* buf, uint8_t& n) override {
        n = m_n;
        std::copy(m_data, m_data+m_n, buf);
    }
};


class BaseFloatFileReader : public ABCFloatFileReader {
protected:
    std::ifstream m_in;
    std::string m_filename;

    float* m_data;
    uint16_t m_n;
public:
    explicit BaseFloatFileReader(const std::string& filename) : m_filename(filename), m_data(nullptr), m_n(0) {}

    bool Open() override {
        m_in.open(m_filename);
        if (!m_in.is_open())
            return false;
        return true;
    }

    void Close() override {
        m_in.close();
    }

    void GetData(float* buf, uint16_t& n) override {
        n = m_n;
        std::copy(m_data, m_data+m_n, buf);
    }
};