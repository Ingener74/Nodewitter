//
// Created by Pavel on 26.08.2017.
//

#pragma once

#include <map>
#include <boost/shared_ptr.hpp>
#include "Widget.h"

class WidgetContainer : public Widget {
public:
    typedef boost::shared_ptr<Widget> WidgetPtr;

    WidgetContainer(hgeGUI* gui);

    WidgetContainer(hgeGUI* gui, std::string const& id);

    virtual ~WidgetContainer();

    virtual void Draw();

    virtual void AddWidget(int order, WidgetPtr widget);

    virtual void Render();

    virtual void SetOrder(int order, Widget*);

    Widget* GetWidget(std::string const& id);

protected:
    hgeGUI* gui;
    typedef std::multimap<int, WidgetPtr> WidgetMultiMap;
    typedef std::pair<WidgetMultiMap::iterator, WidgetMultiMap::iterator> WidgetMultiMapRange;
    WidgetMultiMap widgets;
};
