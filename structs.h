#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>

enum IdentifierType
{
    STANDARD = 11,
    EXTENDED = 29
};


struct GroupInformation
{
    uint16_t nameSize;
    IdentifierType id_type;
    uint32_t dontCares : 29;
    uint32_t mask : 29;
    // name
};
#endif // STRUCTS_H
