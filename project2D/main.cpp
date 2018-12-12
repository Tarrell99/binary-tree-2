#include "Application2D.h"
#include "TreeApplication.h"

int main() {
	
	// allocation
	auto app = new TreeApplication();
	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}