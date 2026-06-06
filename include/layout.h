#include "raylib.h"
#include <stdint.h>

typedef struct Element;

typedef struct ContainerElement {
    bool vertical;

    uint16_t verticalPadding;
    uint16_t horizontalPadding;

    uint16_t minWidth;
    uint16_t maxWidth;

    uint16_t minHeight;
    uint16_t maxHeight;

    Element *elements;
    uint16_t elementsCount;
    uint16_t elementsCapacity;
} ContainerElement;

typedef struct TextElement {
    char *text;
} TextElement;

typedef struct ClickableElement {
    struct ContainerElement;
    void (*callback)();
} ClickableElement;

typedef struct Element {
    enum {
        TEXT_ELEMENT,
        CONTAINER_ELEMENT,
        CLICKABLE_ELEMENT
    } type;

    union {
        TextElement textElement;
        ContainerElement containerElement;
        ClickableElement clickable;
    };
} Element;

void Container_Append(ContainerElement *container, Element element);
void Container_GetSize(ContainerElement *container);
void Container_Cleanup(ContainerElement *container);