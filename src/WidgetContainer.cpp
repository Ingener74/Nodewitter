//
// Created by Pavel on 26.08.2017.
//

#include <hge.h>
#include "WidgetContainer.h"

WidgetContainer::WidgetContainer(hgeGUI* gui) : Widget(), gui(gui) {
}

WidgetContainer::WidgetContainer(hgeGUI *gui, std::string const &id): Widget(id), gui(gui) {
}

WidgetContainer::~WidgetContainer() {
}

void WidgetContainer::Draw() {
    Render();
}

void WidgetContainer::AddWidget(int order, boost::shared_ptr<Widget> widget) {
    widgets.insert(std::make_pair(order, widget));
    gui->AddCtrl(widget.get());
}

void WidgetContainer::Render() {
    for (WidgetMultiMap::iterator widgetIt = widgets.begin(); widgetIt != widgets.end(); ++widgetIt)
        if ((*widgetIt).second->bVisible)
            (*widgetIt).second->Draw();
}

void WidgetContainer::SetOrder(int order, Widget * widget) {
    WidgetMultiMapRange range = widgets.equal_range(order);
    for (WidgetMultiMap::iterator widgetIt = range.first; widgetIt != range.second; ++widgetIt) {
        if (widgetIt->second.get() == widget && widgetIt->first != order) {
            WidgetPtr t = widgetIt->second;
            widgets.erase(widgetIt);
            widgets.insert(std::make_pair(order, t));
        }
    }
}

Widget *WidgetContainer::GetWidget(std::string const &id) {
    for (WidgetMultiMap::iterator widgetIt = widgets.begin(); widgetIt != widgets.end(); ++widgetIt)
        if ((*widgetIt).second->GetId() == id)
            return (*widgetIt).second.get();
    return NULL;
}

