#pragma once

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

// vectors integers
typedef struct {int x, y;}       vec2i;
typedef struct {int x, y, z;}    vec3i;
typedef struct {int x, y, z, w;} vec4i;

// vectors integers 8
typedef struct {int8 x, y;}       vec2i8;
typedef struct {int8 x, y, z;}    vec3i8;
typedef struct {int8 x, y, z, w;} vec4i8;

// vectors integers 16
typedef struct {int16 x, y;}       vec2i16;
typedef struct {int16 x, y, z;}    vec3i16;
typedef struct {int16 x, y, z, w;} vec4i16;

// vectors integers 32
typedef struct {int32 x, y;}       vec2i32;
typedef struct {int32 x, y, z;}    vec3i32;
typedef struct {int32 x, y, z, w;} vec4i32;

// vectors integers 64
typedef struct {int64 x, y;}       vec2i64;
typedef struct {int64 x, y, z;}    vec3i64;
typedef struct {int64 x, y, z, w;} vec4i64;

// vector floats
typedef struct {float x, y;}       vec2f;
typedef struct {float x, y, z;}    vec3f;
typedef struct {float x, y, z, w;} vec4f;
