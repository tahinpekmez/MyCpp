#include <iostream>
using std::cout;
using std::endl;

class abstract
{
public:
	virtual void foo() = 0;

};

class firstfoo : public abstract
{
	void foo()
	{
		cout << "Let's go to the foo bar!" << endl;
	}
};

class secondfoo : public abstract
{
	void foo()
	{
		cout << "I prefer the foo beer !" << endl;
	}
};

abstract& factorymethod()
{
	static int what = 0;

	if (what++ % 2 == 0)
		return *(new firstfoo());
	else
		return *(new secondfoo());

}

int main(int argc, char* argv[])
{
	int howmany = 10;
	int i = 0;

	while(i++ < howmany)
	{
		abstract& abs = factorymethod();
		abs.foo();
		delete& abs;
	}
}