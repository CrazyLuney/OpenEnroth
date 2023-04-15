#pragma once

#include "Library/Lod/Internal/LodFile.h"


struct LodDirectory final {
    std::string name;
    std::vector<LodFile> files;

    size_t fileHeadersOffset = 0;
};
