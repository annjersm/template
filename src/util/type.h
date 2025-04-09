#pragma once
// #################################################################|#########
// #################################################################|# (¬_¬) #
// #################################################################|#########
#include <stdint.h>

// Signed int
typedef int8_t       int8;
typedef int16_t      int16;
typedef int32_t      int32;
typedef int64_t      int64;

// Unsigned int
typedef unsigned int Uint;
typedef uint8_t      Uint8;
typedef uint16_t     Uint16;
typedef uint32_t     Uint32;
typedef uint64_t     Uint64;

#define PI 3.14159265359
#define GetDegrees(r) (r * (180 / PI))
#define GetRadians(d) (d * (PI / 180))
