#include "VendingMachine.h"

int main()
{
	shared_ptr<VendingMachine> pvm(new VendingMachine());//通过shared_ptr实现单例模式

	pvm->Run();
	return 0;
}