#pragma once
// #################################################################|#########
// #################################################################|# (¬_¬) #
// #################################################################|#########

typedef float vec2[2];
typedef float vec3[3];
typedef float vec4[4];

enum {X, Y, Z, W};

#define printV2(message, vec) printf(message "%1.2f, %1.2f\n",                \
		vec[X], vec[Y])

#define printV3(message, vec) printf(message "%1.2f, %1.2f, %1.2f\n",         \
		vec[X], vec[Y], vec[Z])

#define printV4(message, vec) printf(message "%1.2f, %1.2f, %1.2f, %1.2f\n",  \
		vec[X], vec[Y], vec[Z], vec[W])

#define printV(message, vec) printV3(message, vec)

