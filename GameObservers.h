#pragma once
//#include "Player.h"
#include <list>

class ActionObserver;
class Player;

class PlayerSubject {
public:
	virtual void Attach(ActionObserver* o);
	virtual void Detach(ActionObserver* o);
	virtual void Notify();
	PlayerSubject();
	~PlayerSubject();
private:
	list<ActionObserver*> *_observers;
};


class GameObserver {
public:
	~GameObserver();
	virtual void Update() = 0;
protected:
	GameObserver();
};


class ActionObserver : public GameObserver{
public:
	ActionObserver(Player* s);
	~ActionObserver();
	void Update();
	void display();
private:
	Player* _subject;
};
