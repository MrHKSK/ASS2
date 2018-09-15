#include <iostream>
#include "XBoxController.h"
#include "XInputWrapper.h"

#define XINPUT_GAMEPAD_TRIGGER_THRESHOLD    30

GamePad::XBoxController::XBoxController(XInputWrapper * xinput, DWORD id)
{
	this->xinput = xinput;
	ControllerID = id;
}

DWORD GamePad::XBoxController::GetControllerId()
{
	return ControllerID;
}

bool GamePad::XBoxController::IsConnected()
{
	this->xinput = xinput;
	xinput->XInputGetState(ControllerID, &ControllerState);
	ZeroMemory(&ControllerState, sizeof(XINPUT_STATE));
	DWORD Result = XInputGetState(ControllerID, &ControllerState);

	if (Result == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedA()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_A)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedB()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_B)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedX()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_X)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedY()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedLeftShoulder()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedRightShoulder()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedLeftDpad()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedRightDpad()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedUpDpad()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedDownDpad()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedStart()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedBack()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedLeftThumb()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePad::XBoxController::PressedRightThumb()
{
	if (ControllerState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

BYTE GamePad::XBoxController::LeftTriggerLocation()
{
	BYTE LT = ControllerState.Gamepad.bLeftTrigger;

	if (LT > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		if (LT > 255) LT = 255;
	}
	else
	{
		LT = 0;
	}
	return LT;
}

BYTE GamePad::XBoxController::RightTriggerLocation()
{
	BYTE RT = ControllerState.Gamepad.bRightTrigger;

	if (RT > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		if (RT > 255) RT = 255;
	}
	else
	{
		RT = 0;
	}

	return RT;
}

GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation()
{
	SHORT LX = ControllerState.Gamepad.sThumbLX;
	SHORT LY = ControllerState.Gamepad.sThumbLY;

	double magnitude = sqrt(LX * LX + LY * LY);

	double normalizedLX = LX / magnitude;
	double normalizedLY = LY / magnitude;

	double normalizedMagnitude = 0;

	if (magnitude > DeadZone)
	{
		if (magnitude > 32767) magnitude = 32767;

		magnitude = magnitude - DeadZone;
		normalizedMagnitude = magnitude / (32767 - DeadZone);

		return GamePad::Coordinate(LX, LY);
	}
	else
	{
		magnitude = 0.0;
		normalizedMagnitude = 0.0;

		return GamePad::Coordinate(0, 0);
	}
}

GamePad::Coordinate GamePad::XBoxController::RightThumbLocation()
{
	SHORT RX = ControllerState.Gamepad.sThumbRX;
	SHORT RY = ControllerState.Gamepad.sThumbRY;

	double magnitude = sqrt(RX * RX + RY * RY);

	double normalizedLX = RX / magnitude;
	double normalizedLY = RY / magnitude;

	double normalizedMagnitude = 0;

	if (magnitude > DeadZone)
	{
		if (magnitude > 32767) magnitude = 32767;

		magnitude = magnitude - DeadZone;
		normalizedMagnitude = magnitude / (32767 - DeadZone);

		return GamePad::Coordinate(RX, RY);
	}
	else
	{
		magnitude = 0.0;
		normalizedMagnitude = 0.0;

		return GamePad::Coordinate(0, 0);
	}
}

void GamePad::XBoxController::Vibrate(WORD left, WORD right)
{
	this->xinput = xinput;
	xinput->XInputGetState(ControllerID, &ControllerState);
	XINPUT_VIBRATION Vibration;

	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

	Vibration.wLeftMotorSpeed = left;
	Vibration.wRightMotorSpeed = right;

	XInputSetState(ControllerID, &Vibration);
}

void GamePad::XBoxController::SetDeadzone(unsigned int radius)
{
	DeadZone = radius;
}

XINPUT_STATE GamePad::XBoxController::GetState()
{
	this->xinput = xinput;
	xinput->XInputGetState(ControllerID, &ControllerState);
	ZeroMemory(&ControllerState, sizeof(XINPUT_STATE));
	XInputGetState(ControllerID, &ControllerState);
	return ControllerState;
}