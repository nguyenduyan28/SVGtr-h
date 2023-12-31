// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <iostream>
#include <map>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "rapidxml.hpp"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <vector>
#include <string>
#include <sstream>
#include <shellapi.h>
#include <fstream>
using namespace std;
using namespace rapidxml;
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")
// TODO: reference additional headers your program requires here
struct RGB
{
    unsigned char r, g, b;
    RGB& operator=(const RGB& other)
    {
        if (this != &other)
        {
            r = other.r;
            g = other.g;
            b = other.b;
        }
        return *this;
    }
};

struct Points
{
    float x, y;
};
void applyAttributesToChildren(xml_node<>* parentNode, vector<pair<string, string>>& attributes);
void read(xml_node<>* node, vector<pair<string, string>>& gAttributes, Graphics& graphics);
void setProperties(char* nodeName, vector<pair<string, string>> a, Graphics& graphics);
void DrawSVGFile(string& filename, HDC hdc);

std::map<std::string, std::string> colorMap = {
    {"black", "rgb(0,0,0)"},
    {"white", "rgb(255,255,255)"},
    {"red", "rgb(255,0,0)"},
    {"maroon", "rgb(128,0,0)"},
    {"darkred", "rgb(139,0,0)"},
    {"brown", "rgb(165,42,42)"},
    {"firebrick", "rgb(178,34,34)"},
    {"crimson", "rgb(220,20,60)"},
    {"red", "rgb(255,0,0)"},
    {"tomato", "rgb(255,99,71)"},
    {"coral", "rgb(255,127,80)"},
    {"indianred", "rgb(205,92,92)"},
    {"lightcoral", "rgb(240,128,128)"},
    {"darksalmon", "rgb(233,150,122)"},
    {"salmon", "rgb(250,128,114)"},
    {"lightsalmon", "rgb(255,160,122)"},
    {"orangered", "rgb(255,69,0)"},
    {"darkorange", "rgb(255,140,0)"},
    {"orange", "rgb(255,165,0)"},
    {"gold", "rgb(255,215,0)"},
    {"darkgoldenrod", "rgb(184,134,11)"},
    {"goldenrod", "rgb(218,165,32)"},
    {"palegoldenrod", "rgb(238,232,170)"},
    {"darkkhaki", "rgb(189,183,107)"},
    {"khaki", "rgb(240,230,140)"},
    {"olive", "rgb(128,128,0)"},
    {"yellow", "rgb(255,255,0)"},
    {"yellowgreen", "rgb(154,205,50)"},
    {"darkolivegreen", "rgb(85,107,47)"},
    {"olivedrab", "rgb(107,142,35)"},
    {"lawngreen", "rgb(124,252,0)"},
    {"chartreuse", "rgb(127,255,0)"},
    {"greenyellow", "rgb(173,255,47)"},
    {"darkgreen", "rgb(0,100,0)"},
    {"green", "rgb(0,128,0)"},
    {"forestgreen", "rgb(34,139,34)"},
    {"lime", "rgb(0,255,0)"},
    {"limegreen", "rgb(50,205,50)"},
    {"lightgreen", "rgb(144,238,144)"},
    {"palegreen", "rgb(152,251,152)"},
    {"darkseagreen", "rgb(143,188,143)"},
    {"mediumspringgreen", "rgb(0,250,154)"},
    {"springgreen", "rgb(0,255,127)"},
    {"seagreen", "rgb(46,139,87)"},
    {"mediumaquamarine", "rgb(102,205,170)"},
    {"mediumseagreen", "rgb(60,179,113)"},
    {"lightseagreen", "rgb(32,178,170)"},
    {"darkslategray", "rgb(47,79,79)"},
    {"teal", "rgb(0,128,128)"},
    {"darkcyan", "rgb(0,139,139)"},
    {"aqua", "rgb(0,255,255)"},
    {"cyan", "rgb(0,255,255)"},
    {"lightcyan", "rgb(224,255,255)"},
    {"darkturquoise", "rgb(0,206,209)"},
    {"turquoise", "rgb(64,224,208)"},
    {"mediumturquoise", "rgb(72,209,204)"},
    {"paleturquoise", "rgb(175,238,238)"},
    {"aquamarine", "rgb(127,255,212)"},
    {"powderblue", "rgb(176,224,230)"},
    {"cadetblue", "rgb(95,158,160)"},
    {"steelblue", "rgb(70,130,180)"},
    {"cornflowerblue", "rgb(100,149,237)"},
    {"deepskyblue", "rgb(0,191,255)"},
    {"dodgerblue", "rgb(30,144,255)"},
    {"lightblue", "rgb(173,216,230)"},
    {"skyblue", "rgb(135,206,235)"},
    {"lightskyblue", "rgb(135,206,250)"},
    {"midnightblue", "rgb(25,25,112)"},
    {"navy", "rgb(0,0,128)"},
    {"darkblue", "rgb(0,0,139)"},
    {"mediumblue", "rgb(0,0,205)"},
    {"blue", "rgb(0,0,255)"},
    {"royalblue", "rgb(65,105,225)"},
    {"blueviolet", "rgb(138,43,226)"},
    {"indigo", "rgb(75,0,130)"},
    {"darkslateblue", "rgb(72,61,139)"},
    {"slateblue", "rgb(106,90,205)"},
    {"mediumslateblue", "rgb(123,104,238)"},
    {"mediumpurple", "rgb(147,112,219)"},
    {"darkmagenta", "rgb(139,0,139)"},
    {"darkviolet", "rgb(148,0,211)"},
    {"darkorchid", "rgb(153,50,204)"},
    {"mediumorchid", "rgb(186,85,211)"},
    {"purple", "rgb(128,0,128)"},
    {"thistle", "rgb(216,191,216)"},
    {"plum", "rgb(221,160,221)"},
    {"violet", "rgb(238,130,238)"},
    {"magenta", "rgb(255,0,255)"},
    {"fuchsia", "rgb(255,0,255)"},
    {"orchid", "rgb(218,112,214)"},
    {"mediumvioletred", "rgb(199,21,133)"},
    {"palevioletred", "rgb(219,112,147)"},
    {"deeppink", "rgb(255,20,147)"},
    {"hotpink", "rgb(255,105,180)"},
    {"lightpink", "rgb(255,182,193)"},
    {"pink", "rgb(255,192,203)"},
    {"antiquewhite", "rgb(250,235,215)"},
    {"beige", "rgb(245,245,220)"},
    {"bisque", "rgb(255,228,196)"},
    {"blanchedalmond", "rgb(255,235,205)"},
    {"wheat", "rgb(245,222,179)"},
    {"cornsilk", "rgb(255,248,220)"},
    {"lemonchiffon", "rgb(255,250,205)"},
    {"lightgoldenrodyellow", "rgb(250,250,210)"},
    {"lightyellow", "rgb(255,255,224)"},
    {"saddlebrown", "rgb(139,69,19)"},
    {"sienna", "rgb(160,82,45)"},
    {"chocolate", "rgb(210,105,30)"},
    {"peru", "rgb(205,133,63)"},
    {"sandybrown", "rgb(244,164,96)"},
    {"burlywood", "rgb(222,184,135)"},
    {"tan", "rgb(210,180,140)"},
    {"rosybrown", "rgb(188,143,143)"},
    {"moccasin", "rgb(255,228,181)"},
    {"navajowhite", "rgb(255,222,173)"},
    {"peachpuff", "rgb(255,218,185)"},
    {"mistyrose", "rgb(255,228,225)"},
    {"lavenderblush", "rgb(255,240,245)"},
    {"linen", "rgb(250,240,230)"},
    {"oldlace", "rgb(253,245,230)"},
    {"papayawhip", "rgb(255,239,213)"},
    {"seashell", "rgb(255,245,238)"},
    {"mintcream", "rgb(245,255,250)"},
    {"slategray", "rgb(112,128,144)"},
    {"lightslategray", "rgb(119,136,153)"},
    {"lightsteelblue", "rgb(176,196,222)"},
    {"lavender", "rgb(230,230,250)"},
    {"floralwhite", "rgb(255,250,240)"},
    {"aliceblue", "rgb(240,248,255)"},
    {"ghostwhite", "rgb(248,248,255)"},
    {"honeydew", "rgb(240,255,240)"},
    {"ivory", "rgb(255,255,240)"},
    {"azure", "rgb(240,255,255)"},
    {"snow", "rgb(255,250,250)"},
    {"dimgray", "rgb(105,105,105)"},
    {"gray", "rgb(128,128,128)"},
    { "grey", "rgb(128,128,128)" },
    {"darkgray", "rgb(169,169,169)"},
    {"silver", "rgb(192,192,192)"},
    {"lightgray", "rgb(211,211,211)"},
    {"gainsboro", "rgb(220,220,220)"},
    {"whitesmoke", "rgb(245,245,245)"},
    {"none", "rgb(255,255,255)"},
    {"white", "rgb(255,255,255)"}
};


class Shape
{
protected:
    RGB fill;
    double fillOpacity;
    RGB stroke;
    int strokeWidth;
    double strokeOpacity;
    bool hasStroke;
    Points translate;
    double rotate;
    Points scale;

public:
    Shape();
    virtual void drawShape(Graphics& graphics);
    void setShape(const string& a, string& b, bool& fo, bool& f, bool& s, bool& sw, bool& so);
    virtual void setBesides(vector<pair<string, string>> a);
};
vector<Points> parsePoints(const string& p);

class RectangleSVG : public Shape
{
private:
    Points point;
    int width;
    int height;

public:
    RectangleSVG();
    void drawShape(Graphics& graphics) override;
    void setBesides(vector<pair<string, string>> a) override;
};

class TextSVG : public Shape
{
private:
    Points point;
    int fontSize;
    string info;
    const wchar_t* fontFamily = L"Times New Roman"; 
    int dx, dy;

public:
    TextSVG();
    void drawShape(Graphics& graphics) override;
    void setBesides(vector<pair<string, string>> a) override;
};

class CircleSVG : public Shape
{
private:
    Points point;
    double radius;

public:
    CircleSVG();
    void drawShape(Graphics& graphics) override;
    void setBesides(vector<pair<string, string>> a) override;
};

class PolylineSVG : public Shape
{
private:
    vector<Points> points;

public:
    PolylineSVG();
    void drawShape(Graphics& graphics) override;
    void setBesides(vector<pair<string, string>> a) override;
};

class EllipseSVG : public Shape
{
private:
    Points c;
    float radiusX, radiusY;

public:
    EllipseSVG();
    void drawShape(Graphics& graphics) override;
    void setBesides(vector<pair<string, string>> a) override;
};

class LineSVG : public Shape
{
private:
    Points from, to;

public:
    LineSVG();
    void drawShape(Graphics& graphics) override;
    void setBesides(vector<pair<string, string>> a) override;
};

class PolygonSVG : public Shape
{
private:
    vector<Points> points;

public:
    PolygonSVG();
    void drawShape(Graphics& graphics) override;
    void setBesides(vector<pair<string, string>> a) override;
};

class PathSVG : public Shape
{
private:
    Points startPoint;
    Points curPoint;
    vector<pair<char, vector<Points>>> dData;

public:
    PathSVG();
    void updatePoint(Points newPoint);
    void drawShape(Graphics& graphics);
    void setBesides(vector<pair<string, string>> a);
};

