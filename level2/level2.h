typedef struct {
	int hour;
	int minute;
} myTime;
typedef struct {
	double x, y, z;
} POINT;
typedef struct {
	POINT topLeft; POINT bottomRight;
} RECT;
typedef struct {
	POINT pts[2]; float dist;
} PAIR;
typedef enum {
	MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE
} PLANETS;
typedef enum {
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} MONTH;
typedef enum {
	NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST
} DIRECTION;
typedef unsigned char ubyte;
typedef struct {
	ubyte r, g, b;
} Color;
typedef enum {
	BLACK, RED, YELLOW, PURPLE, GREEN, BROWN, BLUE, WHITE
} enColors;
typedef struct {
	double h, w, l;
} DIM;


void arrays_main();
void bitwiseops_main();
void contiguoussubarraygreatestsum_main();
void morerecursions_main();
void pointers_main();
void preprocessor_main();
void recursions_main();
void stringmanipulation_main();
void vectors_main();
void references_main();
void sortsearch_main();
void fileIO_main();
void errorchecking_main();

long long getNum();
double getDouble();
void getString(char* str, int size);

