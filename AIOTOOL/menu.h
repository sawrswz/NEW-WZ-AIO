#pragma once
#include "framework.h"
#include "globals.h"
#include "sdk.h"
#include "ui.h"

extern ImFont* MainCaps;
extern ImFont* Main;
extern ImFont* FMenu;

static int gameMode = 0;
static int gameMode1 = 0;

static int applyMode = 0;
static int applyMode1 = 0;

static int weapontype = 0;

static int statMode = 0;

class cMenu
{
public:
	void DrawMenu();
};