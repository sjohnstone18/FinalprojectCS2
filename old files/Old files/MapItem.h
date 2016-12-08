#pragma once

#include <stdio.h>

class MapItem {
public:
	virtual void render();
	virtual bool passThru();
	// etc. ?
};