#include "readers.h"


ABCUInt8Reader* Int8Factory(const std::string& filename) {
    std::string extension = filename.substr(filename.find_last_of('.') + 1);

    if (extension == "txt")
        return new TxtReader(filename);
    else if (extension == "bin")
        return new BinReader(filename);
    return nullptr;
}


ABCFloatFileReader* FloatFactory(const std::string& filename) {
    std::string extension = filename.substr(filename.find_last_of('.') + 1);

    if (extension == "fbin")
        return new FBinReader(filename);
    return nullptr;
}


ABCReader* Factory(const std::string& filename) {
    std::string extension = filename.substr(filename.find_last_of('.') + 1);

    if (extension == "txt")
        return new TxtReader(filename);
    else if (extension == "bin")
        return new BinReader(filename);
    else if (extension == "fbin")
        return new FBinReader(filename);
    return nullptr;
}