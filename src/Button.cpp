//
// Created by Pavel on 26.08.2017.
//

#include <boost/make_shared.hpp>
#include "Button.h"
#include "Image.h"

Button::Button(HGE* hge, hgeGUI* gui,
               std::string const& font, std::string const& title,
               std::string const &imageNotPressed, std::string const &imagePressed,
               float x, float y, float w, float h) : WidgetContainer(gui) {
    init(hge, imageNotPressed, imagePressed, font, title, x, y, w, h);
}

Button::Button(HGE *hge, hgeGUI *gui,
               std::string const& font, std::string const& title,
               std::string const &id, std::string const &imageNotPressed,
               std::string const &imagePressed,
               float x, float y, float w, float h): WidgetContainer(gui, id) {
    init(hge, font, title, imageNotPressed, imagePressed, x, y, w, h);
}

Button::~Button() {
}

bool Button::MouseLButton(bool bDown) {
    if (bDown) {
        imageNotPressed->Hide();
        pressed = true;
        pressedDelay = 0.2f;
    }
    return Widget::MouseLButton(bDown);
}

void Button::Update(float dt) {
    pressedDelay -= dt;
    if (pressedDelay < 0) {
        pressed = false;
        imageNotPressed->Show();
    }
    hgeGUIObject::Update(dt);
}

void Button::init(HGE *hge,
                  std::string const& font, std::string const& title,
                  const std::string &imageNotPressed, const std::string &imagePressed,
                  float x, float y, float w, float h) {
    pressed = false;
    text = title;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    boost::shared_ptr<Image> ip = boost::make_shared<Image>(hge, imagePressed, x, y, w, h);
    AddWidget(0, ip);
    ip.get();

    boost::shared_ptr<Image> inp = boost::make_shared<Image>(hge, imageNotPressed, x, y, w, h);
    AddWidget(1, inp);
    Button::imageNotPressed = inp.get();

    this->font = boost::make_shared<hgeFont>(font.c_str());

    rect = Button::imageNotPressed->rect;
}

void Button::Draw() {
    WidgetContainer::Draw();
    font->Render(x + w/2, y + 1*h/4, HGETEXT_CENTER | HGETEXT_MIDDLE, text.c_str());
}

void Button::SetPos(float x, float y) {
    this->x = x;
    this->y = y;
    for (WidgetMultiMap::iterator wIt = widgets.begin(); wIt != widgets.end(); ++wIt) {
        wIt->second->SetPos(x, y);
    }
    rect = Button::imageNotPressed->rect;
}

void Button::SetSize(float w, float h) {
    this->w = w;
    this->h = h;
    for (WidgetMultiMap::iterator wIt = widgets.begin(); wIt != widgets.end(); ++wIt) {
        wIt->second->SetSize(w, h);
    }
    rect = Button::imageNotPressed->rect;
}

