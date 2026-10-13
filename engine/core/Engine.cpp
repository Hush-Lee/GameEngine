module Engine;
import std;

void engine::Application::log(const std::string& message)
{
	std::println("[Engine] {}", message);
}

void engine::Application::run()
{
	log("Engine skeleton OK");
}
