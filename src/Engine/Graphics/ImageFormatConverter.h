#pragma once

typedef bool (*ImageFormatConverter)(unsigned int num_pixels, const void *src, void *dst);

inline uint32_t R5G6B5_to_A8B8G8R8(uint16_t color16, unsigned char alpha) {
    uint32_t c = color16;
    unsigned int b = (c & 31) * 8;
    unsigned int g = ((c >> 5) & 63) * 4;
    unsigned int r = ((c >> 11) & 31) * 8;

    return ((unsigned int)alpha << 24) | (b << 16) | (g << 8) | r;
}

inline bool Image_R5G6B5_to_A8B8G8R8(unsigned int num_pixels, const void *src_pixels, void *dst_pixels) {
    auto src = (uint16_t*)src_pixels;
    auto dst = (uint32_t*)dst_pixels;

    for (unsigned int i = 0; i < num_pixels; ++i) {
        dst[i] = R5G6B5_to_A8B8G8R8(src[i], 0xFF);
    }

    return true;
}

inline uint32_t R8G8B8_to_A8B8G8R8(uint8_t r, uint8_t g, uint8_t b, unsigned char alpha) {
    return ((unsigned int)alpha << 24) | (b << 16) | (g << 8) | r;
}

inline bool Image_R8G8B8_to_A8B8G8R8(unsigned int num_pixels, const void *src_pixels, void *dst_pixels) {
    auto src = (uint8_t *)src_pixels;
    auto dst = (uint32_t *)dst_pixels;

    for (unsigned int i = 0; i < num_pixels; ++i) {
        dst[i] = R8G8B8_to_A8B8G8R8(src[i*3], src[i*3+1], src[i*3+2], 0xFF);
    }
    return true;
}

inline unsigned int A1R5G5B5_extract_A(uint16_t c) {
    return c & 0x8000 ? 255 : 0;
}
inline unsigned int A1R5G5B5_extract_R(uint16_t c) {
    return 8 * ((c >> 10) & 0x1F);
}
inline unsigned int A1R5G5B5_extract_G(uint16_t c) {
    return 8 * ((c >> 5) & 0x1F);
}
inline unsigned int A1R5G5B5_extract_B(uint16_t c) {
    return 8 * ((c >> 0) & 0x1F);
}

inline bool Image_A1R5G5B5_to_A8B8G8R8(unsigned int num_pixels,
    const void *src_pixels,
    void *dst_pixels) {
    auto src = (uint16_t *)src_pixels;
    auto dst = (uint8_t *)dst_pixels;

    for (unsigned int i = 0; i < num_pixels; ++i) {
        dst[i * 4 + 0] = A1R5G5B5_extract_R(src[i]);
        dst[i * 4 + 1] = A1R5G5B5_extract_G(src[i]);
        dst[i * 4 + 2] = A1R5G5B5_extract_B(src[i]);
        dst[i * 4 + 3] = A1R5G5B5_extract_A(src[i]);
    }

    return true;
}

inline uint16_t A8R8G8B8_to_A1R5G5B5(uint32_t c) {
    uint32_t b = ((c & 0xFF) / 8) & 31;
    uint32_t g = (((c >> 8) & 0xFF) / 8) & 31;
    uint32_t r = (((c >> 16) & 0xFF) / 8) & 31;
    uint32_t a = (((c >> 24) & 0xFF)) == 255;

    return (uint16_t)((a << 15) | (r << 10) | (g << 5) | b);
}

inline bool Image_A8R8G8B8_to_A1R5G5B5(unsigned int num_pixels,
    const void *src_pixels, void *dst_pixels) {

    auto src = (uint32_t *)src_pixels;
    auto dst = (uint16_t *)dst_pixels;

    for (unsigned int i = 0; i < num_pixels; ++i) {
        dst[i] = A8R8G8B8_to_A1R5G5B5(src[i]);
    }

    return true;
}

inline uint32_t A8R8G8B8_to_A8B8G8R8(uint32_t c) {
    uint32_t b = c & 0xFF;
    uint32_t g = (c >> 8) & 0xFF;
    uint32_t r = (c >> 16) & 0xFF;
    uint32_t a = (c >> 24) & 0xFF;

    return (uint32_t)((a << 24) | (b << 16) | (g << 8) | r);
}

inline bool Image_A8R8G8B8_to_A8B8G8R8(unsigned int num_pixels,
    const void *src_pixels, void *dst_pixels) {

    auto src = (uint32_t *)src_pixels;
    auto dst = (uint32_t *)dst_pixels;

    for (unsigned int i = 0; i < num_pixels; ++i) {
        dst[i] = A8R8G8B8_to_A8B8G8R8(src[i]);
    }

    return true;
}
#define Image_A8B8G8R8_to_A8R8G8B8 Image_A8R8G8B8_to_A8B8G8R8
