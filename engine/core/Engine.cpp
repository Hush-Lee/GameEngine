module Engine;
import std;

void Engine::Engine::log(const std::string& message)
{
	std::println("[Engine] {}", message);
}

void Engine::Engine::run()
{
	log("Engine skeleton OK");
}
