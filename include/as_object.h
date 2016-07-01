#ifndef AS_OBJECT_H
#define AS_OBJECT_H
#include <vector>

#ifndef BEGINNAMESPACEASHENVALE
#define BEGINNAMESPACEASHENVALE namespace AS{
#endif

#ifndef ENDNAMESPACEASHENVALE
#define ENDNAMESPACEASHENVALE }
#endif

BEGINNAMESPACEASHENVALE

class ASNoCopyStructure;

class ASObject : public ASNoCopyStructure
{
public:
    ASObject(ASObject *parent);
    virtual ~ASObject();

    ASObject *getParent() const;
    void setParent(ASObject *parent);

private:
    void addChild(ASObject *child);
    void removeChild(ASObject *child);
    void clearChild();

private:
    ASObject *_parent;
    std::vector<ASObject *> _children;
};

class ASNoCopyStructure
{
public:
    ASNoCopyStructure();
private:
    ASNoCopyStructure(const ASNoCopyStructure &);
};

ENDNAMESPACEASHENVALE

#endif
