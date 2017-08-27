//
// Created by Pavel on 26.08.2017.
//

#pragma once

#include <boost/shared_ptr.hpp>
#include <hge.h>
#include <hgefont.h>
#include "Widget.h"
#include "WidgetContainer.h"

class Image;

class Button : public WidgetContainer {
public:
    Button(HGE* hge, hgeGUI* gui,
           std::string const& font, std::string const& title,
           std::string const& imageNotPressed,
           std::string const& imagePressed, float x, float y, float w, float h);
    Button(HGE* hge, hgeGUI* gui,
           std::string const& font, std::string const& title,
           std::string const& id, std::string const& imageNotPressed,
           std::string const& imagePressed, float x, float y, float w, float h);

    virtual ~Button();

    virtual bool MouseLButton(bool bDown);

    virtual void Update(float dt);

    virtual void Draw();

    virtual void SetPos(float x, float y);

    virtual void SetSize(float w, float h);

private:
    Image *imageNotPressed;
    bool pressed;
    float pressedDelay;

    boost::shared_ptr<hgeFont> font;
    std::string text;

    void init(HGE *hge, const std::string &imageNotPressed, const std::string &imagePressed,
              std::string const& font, std::string const& title,
              float x, float y, float w, float h);
};
