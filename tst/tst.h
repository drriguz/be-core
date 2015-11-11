#pragma once

class Grp;


class Event {
public:
	Event(Grp &g) {}
};

class Grp {
public:
	Grp() {}
protected:
	Event* e;
};