#include "header.h"

unsigned char opacity2alpha(double opacity) {
	opacity = max(0.0, min(1.0, opacity));
	return  static_cast<unsigned char>(opacity * 255.0);
}

Shape::Shape() {
	this->fill.r = this->fill.g = this->fill.b = 0;
	this->stroke.r = this->stroke.g = this->stroke.b = 0;
	this->fillOpacity = 1.0;
	this->strokeOpacity = 1.0;
	this->strokeWidth = 0;
}

void RectangleSVG::getData() {
	fillOpacity = 0.2;
	fill.r = 200;
	fill.g = 100;
	fill.b = 150;
	stroke.r = stroke.g = stroke.b = 55;
	strokeWidth = 2;
	point.x = 20;
	point.y = 20;
	width = 800;
	height = 400;
}

RectangleSVG::RectangleSVG() {
	point.x = point.y = 0;
	width = 0;
	height = 0;
}

void RectangleSVG::drawRectangleSVG() {
	unsigned char fillalpha, strokealpha;
	fillalpha = opacity2alpha(fillOpacity);
	strokealpha = opacity2alpha(strokeOpacity);
	DrawRectangle(point.x, point.y, width, height, Color{ fill.r, fill.g, fill.b, fillalpha });
	DrawRectangleLines(point.x, point.y, width, height, Color{ stroke.r, stroke.g, stroke.b, strokealpha });
}


TextSVG::TextSVG() {
	point.x = point.y = 0;
	int fontSize = 12;
	info = "";
}

void TextSVG::drawTextSVG(){
	unsigned char fillalpha;
	fillalpha = opacity2alpha(fillOpacity);
	const char* data = info.c_str();
	DrawText(data, point.x, point.y, fontSize, Color{ fill.r, fill.g, fill.b, fillalpha});
}

CircleSVG::CircleSVG() {
	point.x = point.y = 0;
	radius = 0;
}

void CircleSVG::drawCircleSVG() {
	unsigned char fillalpha, strokealpha;
	fillalpha = opacity2alpha(fillOpacity);
	strokealpha = opacity2alpha(strokeOpacity);
	DrawCircle(point.x, point.y, float(radius), Color{ fill.r, fill.g, fill.b, fillalpha });
	DrawCircleLines(point.x, point.y, float(radius), Color{ stroke.r, stroke.g, stroke.b, strokealpha });
}

PolylineSVG::PolylineSVG() {
	points.clear();
}

void PolylineSVG::drawPolylineSVG() {

	vector <Vector2> newP;
	for (int i = 0; i < points.size(); i++) {
		newP.push_back(Vector2{float( points[i].x), float(points[i].y) });
	}
	Vector2* pointsArray = newP.data();
	DrawLineStrip(pointsArray, sizeof newP, Color{ fill.r, fill.g, fill.b });
}

EllipseSVG::EllipseSVG() {
	c.x = c.y = 0;
	radiusX = radiusY = 0.0;
}


void EllipseSVG::getData() {
	c.x = 500;
	c.y = 100;
	radiusX = 100;
	radiusY = 50;
	stroke.r = 255;
	stroke.g = 255;
	stroke.b = 0;
	strokeWidth = 3;
	fill.r = 0;
	fill.g = 255;
	fill.b = 0;
	strokeOpacity = 0.7;
	fillOpacity = 0.5;
}

void EllipseSVG::drawEllipseSVG() {
	unsigned char fillalpha, strokealpha;
	fillalpha = opacity2alpha(fillOpacity);
	strokealpha = opacity2alpha(strokeOpacity);
	DrawEllipse(c.x, c.y, radiusX, radiusY, Color{ fill.r, fill.g, fill.b, fillalpha });
	DrawEllipseLines(c.x, c.y, radiusX, radiusY, Color{ stroke.r, stroke.g, stroke.b, strokealpha });
}

LineSVG::LineSVG() {
	from.x = from.y = to.x = to.y;
}

void LineSVG::drawLineSVG() {
	unsigned char fillalpha, strokealpha;
	fillalpha = opacity2alpha(fillOpacity);
	strokealpha = opacity2alpha(strokeOpacity);
	Vector2 start, end;
	start.x = float(from.x);
	start.y = float(from.y);
	end.x = float(to.x);
	end.y = float(to.y);
	DrawLineEx(start, end, float(strokeWidth), Color{ stroke.r, stroke.g, stroke.b, strokealpha });
}

Vector2 PolygonSVG::findPolygonCenter(const vector<Point>& vertices) {
	Vector2 center = { 0.0f, 0.0f };
	for (const Point& vertex : vertices) {
		center.x += vertex.x;
		center.y += vertex.y;
	}

	center.x /= vertices.size();
	center.y /= vertices.size();

	return center;
}

PolygonSVG::PolygonSVG() {
	points.clear();
}

float calculateDistance(const Vector2& p1, const Point& p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

float findPolygonRadius(vector<Point>& vertices, const Vector2& center) {
	double maxDistance = 0.0;

	for (const Point& vertex : vertices) {
		double distance = calculateDistance(center, vertex);
		if (distance > maxDistance) {
			maxDistance = distance;
		}
	}

	return maxDistance;
}

void PolygonSVG::drawPolygonSVG() {
	unsigned char fillalpha, strokealpha;
	fillalpha = opacity2alpha(fillOpacity);
	strokealpha = opacity2alpha(strokeOpacity);
	Vector2 center = findPolygonCenter(points);
	DrawPoly(center, points.size(), findPolygonRadius(points, center), 1.0, Color{ fill.r, fill.g, fill.b, fillalpha });
	DrawPolyLines(center, points.size(), findPolygonRadius(points, center), 1.0, Color{ stroke.r, stroke.g, stroke.b, strokealpha });
}

void PolygonSVG::getData() {
	fill.r = 255;
	fill.g = 255;
	fill.b = 0;
	fillOpacity = 0.6;
	strokeWidth = 10;
	stroke.r = 255;
	stroke.g = 0;
	stroke.b = 0;
	strokeOpacity = 0.7;
}