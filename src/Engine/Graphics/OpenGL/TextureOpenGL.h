#pragma once
#include "Engine/Graphics/Texture.h"

class TextureOpenGL : public Texture {
 public:
    int GetOpenGlTexture(bool bLoad = true);

    virtual ~TextureOpenGL();

 protected:
    friend class RenderOpenGL;

    static Texture *Create(unsigned int width, unsigned int height, IMAGE_FORMAT format, const void * pixels);

    static Texture *Create(ImageLoader *loader);

    void SetOpenGlTexture(int ogl_texture) { this->ogl_texture = ogl_texture; }

    explicit TextureOpenGL(bool lazy_initialization = true)
        : Texture(lazy_initialization), ogl_texture(-1) {}

    int ogl_texture;

    virtual bool LoadImageData();
};
