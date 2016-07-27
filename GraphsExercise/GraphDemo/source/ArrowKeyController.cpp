#include "ArrowKeyController.h"
#include "Input.h"
#include "glfw3.h"



ArrowKeyController::ArrowKeyController()
{
}


ArrowKeyController::~ArrowKeyController()
{
}

void ArrowKeyController::update(Agent* enemy, float dTime)
{
	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_UP))
	{
		enemy->addForce(Vector3(0, -10, 1) * dTime);
		std::cout << "W IS PRESSED" << '\n';
	}

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_DOWN))
	{
		enemy->addForce(Vector3(0, 10, 1) * dTime);
		std::cout << "S IS PRESSED" << '\n';
	}

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_LEFT))
	{
		enemy->addForce(Vector3(-10, 0, 1) * dTime);
		std::cout << "A IS PRESSED" << '\n';
	}

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_RIGHT))
	{
		enemy->addForce(Vector3(10, 0, 1) * dTime);
		std::cout << "D IS PRESSED" << '\n';
	}
}