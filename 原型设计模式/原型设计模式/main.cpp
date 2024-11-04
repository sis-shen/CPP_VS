#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MusicNote
{
public:
	virtual MusicNote* clone() = 0;

	virtual void draw() = 0;
};

class WholeNote:public MusicNote
{
public:
	WholeNote(int level) :_level(level) {}

	WholeNote* clone()override
	{
		return new WholeNote(_level);
	}

	void draw()override
	{
		cout << "WholeNote(" << _level << ") ";
	}

private:
	int _level;
};

class HalfNote :public MusicNote
{
public:
	HalfNote(int level) :_level(level) {}

	HalfNote* clone()override
	{
		return new HalfNote(_level);
	}

	void draw()override
	{
		cout << "HalfNote(" << _level << ") ";
	}

private:
	int _level;
};


class MusicNoteDrawer
{
public:
	MusicNoteDrawer():_index() {}

	bool registerNote(const string& name, int level)
	{
		string fullName = name + to_string(level);
		if (_index.count(fullName))return false;//ÒÑ´æÔÚ

		if (name == "WholeNote")
		{
			_index[fullName] = new WholeNote(level);
			return true;
		}
		else if (name == "HalfNote")
		{
			_index[fullName] = new HalfNote(level);
			return true;
		}
		else
		{
			cout << "unkown Note :" << fullName << endl;
			return false;
		}
	}

	//ÎªÀÖÆ×Ìí¼ÓÒô·û
	bool addNote(const string& name, int level)
	{
		string fullName = name + to_string(level);
		if (_index.count(fullName))
		{
			_music.push_back(_index[fullName]->clone());
			return true;
		}
		else
		{
			cout << "unkown Note :" << fullName << endl;
			return false;
		}
	}

	//»æÖÆÀÖÆ×
	void draw()
	{
		for (auto ptr : _music)
		{
			ptr->draw();
		}
		cout << endl;
	}

	~MusicNoteDrawer()
	{
		for (auto& p : _index)
		{
			delete p.second;
			p.second = nullptr;
		}
		for (auto ptr : _music)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
private:
	vector<MusicNote*>_music;
	unordered_map<string, MusicNote*> _index;
};


int main()
{
	MusicNoteDrawer* mnd = new MusicNoteDrawer;

	for (int i = 0; i < 10; ++i)
	{
		//×¢²á¸÷ÖÖÒô·û
		mnd->registerNote("WholeNote", i);
		mnd->registerNote("HalfNote", i);
	}

	mnd->addNote("HalfNote", 1);
	mnd->addNote("HalfNote", 1);
	mnd->addNote("WholeNote", 5);
	mnd->addNote("WholeNote", 5);
	mnd->addNote("WholeNote", 6);
	mnd->addNote("WholeNote", 6);
	mnd->addNote("HalfNote", 5);

	mnd->draw();

	return 0;
}