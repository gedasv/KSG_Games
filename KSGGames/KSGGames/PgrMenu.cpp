#include "PgrMenu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KSGGames::PgrMenu form;
	Application::Run(%form);
}