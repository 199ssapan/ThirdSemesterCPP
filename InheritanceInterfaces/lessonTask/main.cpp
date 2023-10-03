#include <iostream>
#include <vector>

class IUpdatable
{
public:
	virtual void update() = 0;
};

class IDrawable
{
public:
	virtual void draw() = 0;
};

class IPrintable
{
public:
	virtual void print() = 0;
};

class ChessDesk : public IDrawable, public IUpdatable
{
	void virtual update() override
	{
		std::cout << "Updating figures" << std::endl;
	}
	void virtual draw() override
	{
		std::cout << "Drawing figures" << std::endl;
	}
};

class Timer : public IDrawable, public IUpdatable
{
	void virtual update() override
	{
		std::cout << "Updating time" << std::endl;
	}
	void virtual draw() override
	{
		std::cout << "Drawing digits" << std::endl;
	}
};

class Display : public IDrawable, public IUpdatable, public IPrintable
{
	void virtual update() override
	{
		std::cout << "Updating pixels" << std::endl;
	}
	void virtual draw() override
	{
		std::cout << "Drawing pixels" << std::endl;
	}
	void virtual print() override
	{
		std::cout << "Print words" << std::endl;
	}
};

int main()
{
	std::vector<IUpdatable*> updatable;
	std::vector<IDrawable*> drawable;
	std::vector<IPrintable*> printable;

	ChessDesk cd;
	Timer t;
	Display d;
	updatable.push_back(&cd);
	updatable.push_back(&t);
	updatable.push_back(&d);

	drawable.push_back(&cd);
	drawable.push_back(&t);
	drawable.push_back(&d);

	printable.push_back(&d);

	for (auto f : updatable) {
		f->update();
	}

	for (auto s : drawable) {
		s->draw();
	}
	for (auto s : printable) {
		s->print();
	}
	return 0;
}