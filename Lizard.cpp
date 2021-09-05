#include "Lizard.h"

Lizard::Lizard()
{
}

void Lizard::Appear(int tornev_x, int appear_x)
{
	if (tornev_x > appear_x)
		this->setFlag(true);
}
