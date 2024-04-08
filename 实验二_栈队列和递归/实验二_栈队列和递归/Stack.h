#pragma once
#include <vector>

using namespace std;

namespace sup
{
	template<class T,class Con = vector<T>>//结构适配器，默认使用vector
	class stack
	{
		stack()
			:_top(0)
			,_con(0)
		{}




	private:
		int _top;
		Con _con;
	};


}