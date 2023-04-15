#pragma once

class HWLTexture {
 public:
    inline HWLTexture() {}

    int uBufferWidth = 0;
    int uBufferHeight = 0;
    int uAreaWidth = 0;
    int uAreaHeigth = 0;
    unsigned int uWidth = 0;
    unsigned int uHeight = 0;
    int uAreaX = 0;
    int uAreaY = 0;
    uint16_t *pPixels = nullptr;
};

class Logger;

class HWLContainer {
 public:
    HWLContainer();
    virtual ~HWLContainer();

    bool Open(const std::string &pFilename);

    HWLTexture *LoadTexture(const std::string &pName);

 protected:
    FILE *pFile = nullptr;
    Logger *log = nullptr;
    std::map<std::string, size_t> mNodes;
};
