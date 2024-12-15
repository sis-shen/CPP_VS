#include <iostream>
#include <vector>

using namespace std;

class SObject
{
public:
	SObject(SObject* parent = nullptr)
		:_parent(parent)
	{}

	void setParent(SObject* parent)
	{
		_parent = parent;
	}

	virtual void showParent()
	{
		cout << "SOBject : parent " << _parent<< endl;
	}
public:
	SObject* _parent;
};

class SWidget: public SObject
{
public:
	SWidget(SObject* parent = nullptr)
		:SObject(parent)
	{}

	virtual void showParent()
	{
		cout << "SWidget : parent" << _parent << endl;
	}

	void addChild(SObject* child)
	{
		_childs.push_back(child);
	}
public:
	vector<SObject*>_childs;
};

class SLabel:public SObject
{
public:
	SLabel(SObject* parent = nullptr)
		:SObject(parent)
	{}

	virtual void showParent()
	{
		cout << "SLabel : parent" << _parent << endl;
	}
};

int main()
{
	SWidget* mainW = new SWidget;
	SWidget* subW = new SWidget(mainW);
	mainW->addChild(subW);

	SWidget* leafW1 = new SWidget(subW);
	SWidget* leafW2 = new SWidget(subW);
	subW->addChild(leafW1);
	subW->addChild(leafW2);

	SLabel* label = new SLabel(mainW);
	mainW->addChild(label);

	mainW->showParent();
	subW->showParent();
	label->showParent();

	leafW1->showParent();
	leafW2->showParent();
	return 0;
}