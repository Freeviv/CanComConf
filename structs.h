#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>

enum IdentifierType
{
    STANDARD = 11,
    EXTENDED = 29
};

#pragma pack(push,1)
struct GroupInformation
{
    uint16_t nameSize;
    IdentifierType id_type;
    bool maskSet;
    uint32_t dontCares : 29;
    uint32_t mask : 29;
    int64_t priority;
    uint32_t nChildren; // could be another group or mInfo
    uint64_t bytesToNext; // number of bytes to next entry on the same level
    // name
};

struct MessageInformation
{
    uint16_t nameSize;
    IdentifierType id_type;
    bool idSet;
    uint32_t id : 29;
    int64_t priority;
};
#pragma pack(pop)

#endif // STRUCTS_H
