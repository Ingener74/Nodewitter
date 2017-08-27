//
// Created by Pavel on 26.08.2017.
//

#include <boost/make_shared.hpp>
#include "Image.h"

Image::Image(HGE* hge, std::string const &filename, float x, float y, float width, float height) {
    init(hge, filename, x, y, width, height);
}

Image::Image(HGE *hge, std::string const &id, std::string const &filename, float x, float y, float width,
             float height): Widget(id) {
    init(hge, filename, x, y, width, height);
}

Image::~Image() {
    hge->Texture_Free(imageQuad.tex);
}

void Image::Draw() {
    hge->Gfx_RenderQuad(&imageQuad);
}

void Image::Render() {
}

void Image::SetPos(float x, float y) {
    this->x = x;
    this->y = y;
    updateQuad();
}

void Image::SetSize(float w, float h) {
    this->w = w;
    this->h = h;
    updateQuad();
}

void Image::init(HGE *hge, const std::string &filename, float x, float y, float width, float height) {
//    this->x = x;
//    this->y = y;
//    this->w = width;
//    this->h = height;

    imageQuad.tex = hge->Texture_Load(filename.c_str());

//    imageQuad.v[0].x = x;         imageQuad.v[0].y = y;
//    imageQuad.v[1].x = x + width; imageQuad.v[1].y = y;
//    imageQuad.v[2].x = x + width; imageQuad.v[2].y = y + height;
//    imageQuad.v[3].x = x;         imageQuad.v[3].y = y + height;
    SetPos(x, y);
    SetSize(width, height);

    imageQuad.v[0].tx = 0; imageQuad.v[0].ty = 0;
    imageQuad.v[1].tx = 1; imageQuad.v[1].ty = 0;
    imageQuad.v[2].tx = 1; imageQuad.v[2].ty = 1;
    imageQuad.v[3].tx = 0; imageQuad.v[3].ty = 1;

    imageQuad.blend = BLEND_DEFAULT;
    for (int i = 0; i < 4; ++i) {
        imageQuad.v[i].col = 0xFFFFFFFF;
        imageQuad.v[i].z = 0.5f;
    }

//    rect.Set(x, y, x + width, y + height);
}

void Image::updateQuad() {
    imageQuad.v[0].x = x;     imageQuad.v[0].y = y;
    imageQuad.v[1].x = x + w; imageQuad.v[1].y = y;
    imageQuad.v[2].x = x + w; imageQuad.v[2].y = y + h;
    imageQuad.v[3].x = x;     imageQuad.v[3].y = y + h;
    rect.Set(x, y, x + w, y + h);
}

