#include "../include/as_object.h"


BEGINNAMESPACEASHENVALE

ASObject::ASObject(ASObject *parent)
    : _parent(parent)
{
    _children.clear();
    if(_parent)
        _parent->addChild(this);
}

ASObject::~ASObject()
{
    if(_parent)
        _parent->removeChild(this);
    clearChild();
}

ASObject *ASObject::getParent()
{
    return _parent;
}

void ASObject::setParent(ASObject *parent)
{
    if(_parent){
        _parent->removeChild(this);
        _parent = parent;
        if(_parent)
            _parent->addChild(this);
    }else{
        _parent = parent;
        if(_parent)
            _parent->addChild(this);
    }
}

void ASObject::addChild(ASObject *child)
{
    for(std::vector<ASObject *>::iterator it = _children.begin(); it != _children.end(); ++it){
        if(child == *it)
            return;
    }
    _children.push_back(child);
}

void ASObject::removeChild(ASObject *child)
{
    for(std::vector<ASObject *>::iterator it = _children.begin(); it != _children.end(); ++it){
        if(child == *it){
            _children.erase(it);
            break;
        }
    }
}

void ASObject::clearChild()
{
    while(!_children.empty()){
        std::vector<ASObject *>::iterator it = _children.begin();
        delete *it;
    }
}

ASNoCopyStructure::ASNoCopyStructure()
{

}

ASNoCopyStructure::~ASNoCopyStructure()
{

}

ASNoCopyStructure::ASNoCopyStructure(const ASNoCopyStructure &)
{

}

ENDNAMESPACEASHENVALE
