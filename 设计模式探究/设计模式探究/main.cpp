#include "logsink.hpp"

int main()
{
	std::shared_ptr<suplog::LogSink> lsptr(new suplog::StdoutSink());

	return 0;
}