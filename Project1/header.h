#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"
using namespace std;

struct RGB {
   unsigned char r, g, b;
};

struct Point {
    int x, y;
};

unsigned char opacity2alpha(double opacity);

class Shape {
protected:
    RGB fill;
    double fillOpacity;
    RGB stroke;
    int strokeWidth;
    double strokeOpacity;

public:
    Shape();
    

};

class RectangleSVG : public Shape {
private:
    Point point;
    int width;
    int height;

public:
    RectangleSVG();
    void drawRectangleSVG();
    void getData();
};

class TextSVG : public Shape {
private:
    Point point;
    int fontSize;
    string info;

public:
    TextSVG();
    void drawTextSVG();
};

class CircleSVG : public Shape {
private:
    Point point;
    double radius;

public:
    CircleSVG();
    void drawCircleSVG();
};

class PolylineSVG : public Shape {
private:
   vector<Point> points;

public:
    PolylineSVG();
    void drawPolylineSVG();
    
};

class EllipseSVG : public Shape {
private:
    Point c;
    float radiusX, radiusY;

public:
    EllipseSVG();
    void drawEllipseSVG();
    void getData();
};

class LineSVG : public Shape {
private:
    Point from, to;

public:
    LineSVG();
    void drawLineSVG();
    void getData();
};

class PolygonSVG : public Shape {
private:
    vector<Point> points = {
        {50,75}, {379,161}, {469,161}, {397,215}, {423,301}, {350,250}, {277,301}, {303,215 }, {231, 161}, {321, 161}
    };

public:
    PolygonSVG();
    void drawPolygonSVG();
    Vector2 findPolygonCenter(const vector<Point>& vertices);
    void getData();
};
