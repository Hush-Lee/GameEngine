module;
#include <string>

export module Engine;

export namespace engine
{
	class Application{
	public:
		void log(const std::string& message);
		void run();
	};
}
