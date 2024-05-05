#include <iostream>
#include <cstdint>

#include "factories.h"


int main() {
    // FBIN
    uint16_t float_n;
    float float_buf[100];

    ABCFloatFileReader* fbin_reader = FloatFactory("input.fbin");
    fbin_reader->Open();
    fbin_reader->Read();
    fbin_reader->GetData(float_buf, float_n);

    std::cout << float_n << std::endl;
    for (int i = 0; i < float_n; i++)
        std::cout << float_buf[i] << std::endl;
    std::cout << std::endl;


	uint8_t n;
	uint8_t buf[100];
    // Txt
    ABCUInt8Reader* txt_reader = Int8Factory("input.txt");
    txt_reader->Open();
    txt_reader->Read();
    txt_reader->GetData(buf, n);

	std::cout << (int)n << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << (int)buf[i] << std::endl;
    std::cout << std::endl;


    // BIN
    ABCUInt8Reader* bin_reader = Int8Factory("input.bin");
    bin_reader->Open();
    bin_reader->Read();
    bin_reader->GetData(buf, n);

    std::cout << (int)n << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << (int)buf[i] << std::endl;
    std::cout << std::endl;


    ABCReader* universal_reader = Factory("input.bin");
    universal_reader->Open();
}

