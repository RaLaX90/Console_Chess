#pragma once
#include <string>

using namespace std;

struct figure
{
private:
	string icon;
public:
	figure(string icon);

	string getIcon();

};


figure::figure(string icon) {
	this->icon = icon;
}

string figure::getIcon() {
	return icon;
}

struct rook : public figure {
	rook(string icon) : figure(icon) {}
};

struct knight : public figure {
	knight(string icon) : figure(icon) {}
};

struct bishop : public figure {
	bishop(string icon) : figure(icon) {}
};

struct queen : public figure {
	queen(string icon) : figure(icon) {}
};

struct king : public figure {
	king(string icon) : figure(icon) {}
};

struct pawn : public figure {
	pawn(string icon) : figure(icon) {}
};