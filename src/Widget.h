//
// Created by Pavel on 26.08.2017.
//

#pragma once

#include <map>
#include <string>
#include <hge.h>
#include <hgegui.h>
#include <boost/shared_ptr.hpp>

class Widget : public hgeGUIObject {
public:
    typedef boost::shared_ptr<Widget> Ptr;

    typedef void (*EventHandler)(Widget*);

    enum Event {
        MouseEnter,
        MouseLeave,
        MouseLDown,
        MouseLUp,
        MouseRDown,
        MouseRUp,
    };

    Widget();

    Widget(std::string const& id);

    virtual ~Widget();

    virtual void Draw() = 0;

    virtual void SetId(std::string const& id);

    virtual const std::string& GetId() const;

//    virtual void SetOrder(int order);

    virtual void SetPos(float x, float y);

    virtual void SetSize(float w, float h);

    virtual void Show();

    virtual void Hide();

    virtual void Enter();

    virtual void Leave();

    virtual bool IsDone();

    virtual void Focus(bool bFocused);

    virtual void MouseOver(bool bOver);

    virtual bool MouseMove(float x, float y);

    virtual bool MouseLButton(bool bDown);

    virtual bool MouseRButton(bool bDown);

    virtual bool MouseWheel(int nNotches);

    virtual bool KeyClick(int key, int chr);

    void SetEventHandler(Event, EventHandler);

protected:
    std::string id;
    float x, y, w, h;

    void CallEvent(Event);

    typedef std::map<Event, EventHandler> EventHandlers;
    EventHandlers eventHandlers;
};
