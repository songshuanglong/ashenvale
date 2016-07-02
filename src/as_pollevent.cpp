#include "../include/as_pollevent.h"

BEGINNAMESPACEASHENVALE

IASPollEvent::IASPollEvent(ASObject *parent)
    : ASObject(parent)
{

}

IASPollEvent::~IASPollEvent()
{

}

unsigned int IASPollEvent::getEvents()
{
    return _events;
}

void IASPollEvent::setEvents(unsigned int events)
{
    _events = events;
}

ENDNAMESPACEASHENVALE
