#pragma once
#include <string>

using namespace std;

struct figure
{
public:
	enum class colors { WHITE, BLACK };

	figure(string icon, colors color, int x, int y);

	string getIcon();

private:
	string icon;
	colors color;

	int x;
	int y;
};


figure::figure(string icon, colors color, int x, int y) {
	this->icon = icon;
	this->color = color;
	this->x = x;
	this->y = y;
}

string figure::getIcon() {
	return icon;
}



struct rook : public figure {
	rook(string icon, colors color, int x, int y) : figure(icon, color, x, y) {}
};

struct knight : public figure {
	knight(string icon, colors color, int x, int y) : figure(icon, color, x, y) {}
};

struct bishop : public figure {
	bishop(string icon, colors color, int x, int y) : figure(icon, color, x, y) {}
};

struct queen : public figure {
	queen(string icon, colors color, int x, int y) : figure(icon, color, x, y) {}
};

struct king : public figure {
	king(string icon, colors color, int x, int y) : figure(icon, color, x, y) {}
};

struct pawn : public figure {
	pawn(string icon, colors color, int x, int y) : figure(icon, color, x, y) {}
};