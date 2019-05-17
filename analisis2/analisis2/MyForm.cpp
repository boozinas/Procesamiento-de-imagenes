#include "MyForm.h"
#include<stdlib.h>
#include<stdio.h>


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	analisis2::MyForm form;
	Application::Run(%form);
	return 0;
}


