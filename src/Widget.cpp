//
// Created by Pavel on 26.08.2017.
//

#include "Widget.h"

Widget::Widget() {}

Widget::Widget(std::string const &id) : id(id) {
}

Widget::~Widget() {
}

void Widget::SetId(std::string const &id) {
    Widget::id = id;
}

const std::string &Widget::GetId() const {
    return id;
}

void Widget::SetPos(float x, float y) {
    Widget::x = x; Widget::y = y;
}

void Widget::SetSize(float w, float h) {
    Widget::w = w; Widget::h = h;
}

void Widget::Show() {
    bVisible = true;
}

void Widget::Hide() {
    bVisible = false;
}

void Widget::Enter() {
    hgeGUIObject::Enter();
//    CallEvent(MouseEnter);
}

void Widget::Leave() {
    hgeGUIObject::Leave();
//    CallEvent(MouseLeave);
}

bool Widget::IsDone() {
    return hgeGUIObject::IsDone();
}

void Widget::Focus(bool bFocused) {
    hgeGUIObject::Focus(bFocused);
}

void Widget::MouseOver(bool bOver) {
    bOver ? CallEvent(MouseEnter) : CallEvent(MouseLeave);
    hgeGUIObject::MouseOver(bOver);
}

bool Widget::MouseMove(float x, float y) {
    return hgeGUIObject::MouseMove(x, y);
}

bool Widget::MouseLButton(bool bDown) {
    bDown ? CallEvent(MouseLDown) : CallEvent(MouseLUp);
    return hgeGUIObject::MouseLButton(bDown);
}

bool Widget::MouseRButton(bool bDown) {
    bDown ? CallEvent(MouseRDown) : CallEvent(MouseRUp);
    return hgeGUIObject::MouseRButton(bDown);
}

bool Widget::MouseWheel(int nNotches) {
    return hgeGUIObject::MouseWheel(nNotches);
}

bool Widget::KeyClick(int key, int chr) {
    return hgeGUIObject::KeyClick(key, chr);
}

void Widget::SetEventHandler(Event event, EventHandler eventHandler) {
    eventHandlers[event] = eventHandler;
}

void Widget::CallEvent(Event event) {
    EventHandlers::iterator ehIt = eventHandlers.find(event);
    if (ehIt != eventHandlers.end() && (*ehIt).second)
        (*ehIt).second(this);
}
