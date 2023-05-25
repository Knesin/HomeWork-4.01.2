#include <iostream>
#include <vector>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	auto variant = get_variant();
	if (const int* v = std::get_if<int>(&variant))
		std::cout << *v * 2 << std::endl;
	else if (const std::string* v = std::get_if<std::string>(&variant))
		std::cout << *v << std::endl;
	else if (const std::vector<int>* v = std::get_if<std::vector<int>>(&variant)) {
		for (const int& i : *v)
			std::cout << i << " ";
		std::cout << std::endl;
	}
}
