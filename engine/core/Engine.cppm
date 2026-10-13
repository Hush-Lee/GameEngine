module;
#include <string>

export module Engine;

export namespace Engine
{
	class Engine{
	public:
		void log(const std::string& message);
		void run();
	};
}
