#include <iostream>

using namespace std;



int main()
{
	bool P = true;
	bool Q = false;

	bool conjunction = P && Q;          // 合取 (与)
	bool disjunction = P || Q;         // 析取 (或)
	bool xor_result = P != Q;          // 异或
	bool implication = !P || Q;        // 条件语句
	bool biconditional = P == Q;       // 双条件

	return 0;
}