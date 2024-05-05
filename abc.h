#include <iostream>
#include <fstream>
#include <cstdint>


class ABCReader {
public:
    virtual bool Open() = 0;  // Открыть источник
    virtual void Read() = 0;  // Прочитать источник
    virtual void Close() = 0;  // Закрыть источник
};


class ABCUInt8Reader : public ABCReader {
public:
    // Получить данные источника в массив
    virtual void GetData(uint8_t* buf, uint8_t& n) = 0;
};


class ABCFloatFileReader : virtual public ABCReader {
public:
    // Получить данные источника в массив
    virtual void GetData(float* buf, uint16_t& n) = 0;
};