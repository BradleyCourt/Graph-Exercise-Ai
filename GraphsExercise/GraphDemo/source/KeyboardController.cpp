#include "KeyboardController.h"
#include "Input.h"
#include "glfw3.h"


KeyboardController::KeyboardController()
{
}


KeyboardController::~KeyboardController()
{
}

void KeyboardController::update(Agent * tempAgent, float dTime)
{//****************************FORCE***********************\\

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_W))
	{
		tempAgent->addForce(Vector3(0, -10, 1) * dTime);
		std::cout << "W IS PRESSED" << '\n';
	}
	
	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_S))
	{
		tempAgent->addForce(Vector3(0, 10, 1) * dTime);
		std::cout << "S IS PRESSED" << '\n';
	}	

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_A))
	{
		tempAgent->addForce(Vector3(-10, 0, 1) * dTime);
		std::cout << "A IS PRESSED" << '\n';
	}	

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_D))
	{
		tempAgent->addForce(Vector3(10, 0, 1) * dTime);
		std::cout << "D IS PRESSED" << '\n';
	}


}
