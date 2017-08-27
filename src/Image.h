//
// Created by Pavel on 26.08.2017.
//

#pragma once

#include <hge.h>
#include <boost/shared_ptr.hpp>
#include <hgesprite.h>
#include "Widget.h"

class Image : public Widget {
public:
    Image(HGE* hge, std::string const& filename, float x, float y, float width, float height);
    Image(HGE* hge, std::string const& id, std::string const& filename, float x, float y, float width, float height);

    virtual ~Image();

    virtual void Draw();

    virtual void Render();

    virtual void SetPos(float x, float y);

    virtual void SetSize(float w, float h);

protected:
    hgeQuad imageQuad;

    void init(HGE *hge, const std::string &filename, float x, float y, float width, float height);

    void updateQuad();
};
