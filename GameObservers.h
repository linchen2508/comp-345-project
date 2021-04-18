#pragma once
//#include "Player.h"
#include <list>

class ActionObserver;
class StatisticsObserver;
class Player;
class GameEngine;

//Player Subject
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

//Game Subject
class GameSubject {
public:
	virtual void Attach(StatisticsObserver* o);
	virtual void Detach(StatisticsObserver* o);
	virtual void Notify();
	GameSubject();
	~GameSubject();
private:
	list<StatisticsObserver*> *_observers;
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

class StatisticsObserver : public GameObserver {
public:
	StatisticsObserver(GameEngine* s);
	~StatisticsObserver();
	void Update();
	void display();
private:
	GameEngine* _subject;
};