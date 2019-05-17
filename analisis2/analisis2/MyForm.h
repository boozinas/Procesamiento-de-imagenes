#pragma once
//#include "stdAfx.h"
#include "histogramavisual.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <iostream>
#include <fstream>
#include "OpPuntual.h"
#include "OpAritmetica.h"
#include "histograma.h"
#include "pruebaPasaAltas.h"

#include "pasaBajas.h"
#include <Magick++.h>
//using namespace std;
using namespace Magick;
#define MAX_COLOR 255
#define FACTOR_BRILLO 25
using namespace System;
using namespace System::Runtime::InteropServices; 


namespace analisis2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		char* rutaChar;
		char* rutaChar_arith;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  operacionesPuntualesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  negativoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  binanirzarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aumentarDisminiuirBrilloToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sepiaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  grisesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rGBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rEDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gREENToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bLUEToolStripMenuItem;
	private: System::Windows::Forms::Button^  imagick;
	private: System::Windows::Forms::ToolStripMenuItem^  operacionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sumaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  restaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  operacionesLogicasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nOTToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aNDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oRToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sumaImagenesBinariasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  restaImagenesBinariasToolStripMenuItem;
	private: System::Windows::Forms::Button^  convolucion;
	private: System::Windows::Forms::ToolStripMenuItem^  filtrosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasaAltasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasaBajasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasaBandaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  promedioToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  promediadorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gaussiandoToolStripMenuItem;
	private: System::Windows::Forms::Button^  PromedioManual;





	public:
		String^ rutaSalida = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp";


		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		
		int copia_total(char ruta[]) {
			char buf[BUFSIZ];
			size_t size;

			FILE* source = fopen(ruta, "rb");
			FILE* dest = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp", "wb");
			FILE* dest_t = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");

			while (size = fread(buf, 1, BUFSIZ, source)) {
				fwrite(buf, 1, size, dest);
				fwrite(buf, 1, size, dest_t);
			}

			fclose(source);
			fclose(dest);
			fclose(dest_t);
			return 1;
		}
		int copia_total_arith(char ruta[]) {
			char buf[BUFSIZ];
			size_t size;

			FILE* source = fopen(ruta, "rb");
			FILE* dest = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_arith.bmp", "wb");
			//FILE* dest_t = fopen("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_tratamiento.bmp", "wb");

			while (size = fread(buf, 1, BUFSIZ, source)) {
				fwrite(buf, 1, size, dest);
			//	fwrite(buf, 1, size, dest_t);
			}

			fclose(source);
			fclose(dest);
			//fclose(dest_t);
			return 1;
		}

	
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

protected:

	private: System::Windows::Forms::PictureBox^  pictureBox1;




	private: System::Windows::Forms::OpenFileDialog^  abreImagen;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->abreImagen = (gcnew System::Windows::Forms::OpenFileDialog());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->operacionesPuntualesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->negativoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binanirzarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aumentarDisminiuirBrilloToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepiaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grisesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rEDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gREENToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bLUEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->operacionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sumaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sumaImagenesBinariasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restaImagenesBinariasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->operacionesLogicasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nOTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aNDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oRToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtrosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasaAltasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->promedioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasaBajasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->promediadorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gaussiandoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasaBandaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imagick = (gcnew System::Windows::Forms::Button());
			this->convolucion = (gcnew System::Windows::Forms::Button());
			this->PromedioManual = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(9, 121);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(353, 335);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// abreImagen
			// 
			this->abreImagen->FileName = L"abreImagen";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(9, 51);
			this->trackBar1->Margin = System::Windows::Forms::Padding(2);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Minimum = -255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(353, 45);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->abrirToolStripMenuItem,
					this->operacionesPuntualesToolStripMenuItem, this->operacionesToolStripMenuItem, this->operacionesLogicasToolStripMenuItem, this->histogramaToolStripMenuItem,
					this->filtrosToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(859, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::abrirToolStripMenuItem_Click);
			// 
			// operacionesPuntualesToolStripMenuItem
			// 
			this->operacionesPuntualesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->negativoToolStripMenuItem,
					this->binanirzarToolStripMenuItem, this->aumentarDisminiuirBrilloToolStripMenuItem, this->sepiaToolStripMenuItem, this->grisesToolStripMenuItem,
					this->rGBToolStripMenuItem
			});
			this->operacionesPuntualesToolStripMenuItem->Name = L"operacionesPuntualesToolStripMenuItem";
			this->operacionesPuntualesToolStripMenuItem->Size = System::Drawing::Size(140, 20);
			this->operacionesPuntualesToolStripMenuItem->Text = L"Operaciones Puntuales";
			// 
			// negativoToolStripMenuItem
			// 
			this->negativoToolStripMenuItem->Name = L"negativoToolStripMenuItem";
			this->negativoToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->negativoToolStripMenuItem->Text = L"Negativo";
			this->negativoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::negativoToolStripMenuItem_Click);
			// 
			// binanirzarToolStripMenuItem
			// 
			this->binanirzarToolStripMenuItem->Name = L"binanirzarToolStripMenuItem";
			this->binanirzarToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->binanirzarToolStripMenuItem->Text = L"Binanirzar";
			this->binanirzarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::binanirzarToolStripMenuItem_Click);
			// 
			// aumentarDisminiuirBrilloToolStripMenuItem
			// 
			this->aumentarDisminiuirBrilloToolStripMenuItem->Name = L"aumentarDisminiuirBrilloToolStripMenuItem";
			this->aumentarDisminiuirBrilloToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->aumentarDisminiuirBrilloToolStripMenuItem->Text = L"Aumentar/Disminiuir Brillo";
			this->aumentarDisminiuirBrilloToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aumentarDisminiuirBrilloToolStripMenuItem_Click);
			// 
			// sepiaToolStripMenuItem
			// 
			this->sepiaToolStripMenuItem->Name = L"sepiaToolStripMenuItem";
			this->sepiaToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->sepiaToolStripMenuItem->Text = L"Sepia";
			this->sepiaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sepiaToolStripMenuItem_Click);
			// 
			// grisesToolStripMenuItem
			// 
			this->grisesToolStripMenuItem->Name = L"grisesToolStripMenuItem";
			this->grisesToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->grisesToolStripMenuItem->Text = L"Grises";
			this->grisesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::grisesToolStripMenuItem_Click);
			// 
			// rGBToolStripMenuItem
			// 
			this->rGBToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->rEDToolStripMenuItem,
					this->gREENToolStripMenuItem, this->bLUEToolStripMenuItem
			});
			this->rGBToolStripMenuItem->Name = L"rGBToolStripMenuItem";
			this->rGBToolStripMenuItem->Size = System::Drawing::Size(216, 22);
			this->rGBToolStripMenuItem->Text = L"R,G,B";
			// 
			// rEDToolStripMenuItem
			// 
			this->rEDToolStripMenuItem->Name = L"rEDToolStripMenuItem";
			this->rEDToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->rEDToolStripMenuItem->Text = L"RED";
			this->rEDToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rEDToolStripMenuItem_Click);
			// 
			// gREENToolStripMenuItem
			// 
			this->gREENToolStripMenuItem->Name = L"gREENToolStripMenuItem";
			this->gREENToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->gREENToolStripMenuItem->Text = L"GREEN";
			this->gREENToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::gREENToolStripMenuItem_Click);
			// 
			// bLUEToolStripMenuItem
			// 
			this->bLUEToolStripMenuItem->Name = L"bLUEToolStripMenuItem";
			this->bLUEToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->bLUEToolStripMenuItem->Text = L"BLUE";
			this->bLUEToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::bLUEToolStripMenuItem_Click);
			// 
			// operacionesToolStripMenuItem
			// 
			this->operacionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->sumaToolStripMenuItem,
					this->restaToolStripMenuItem, this->sumaImagenesBinariasToolStripMenuItem, this->restaImagenesBinariasToolStripMenuItem
			});
			this->operacionesToolStripMenuItem->Name = L"operacionesToolStripMenuItem";
			this->operacionesToolStripMenuItem->Size = System::Drawing::Size(148, 20);
			this->operacionesToolStripMenuItem->Text = L"Operaciones Aritmeticas";
			this->operacionesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::operacionesToolStripMenuItem_Click);
			// 
			// sumaToolStripMenuItem
			// 
			this->sumaToolStripMenuItem->Name = L"sumaToolStripMenuItem";
			this->sumaToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->sumaToolStripMenuItem->Text = L"Suma";
			this->sumaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sumaToolStripMenuItem_Click);
			// 
			// restaToolStripMenuItem
			// 
			this->restaToolStripMenuItem->Name = L"restaToolStripMenuItem";
			this->restaToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->restaToolStripMenuItem->Text = L"Resta";
			this->restaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::restaToolStripMenuItem_Click);
			// 
			// sumaImagenesBinariasToolStripMenuItem
			// 
			this->sumaImagenesBinariasToolStripMenuItem->Name = L"sumaImagenesBinariasToolStripMenuItem";
			this->sumaImagenesBinariasToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->sumaImagenesBinariasToolStripMenuItem->Text = L"Suma Imagenes Binarias";
			// 
			// restaImagenesBinariasToolStripMenuItem
			// 
			this->restaImagenesBinariasToolStripMenuItem->Name = L"restaImagenesBinariasToolStripMenuItem";
			this->restaImagenesBinariasToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->restaImagenesBinariasToolStripMenuItem->Text = L"Resta Imagenes Binarias";
			// 
			// operacionesLogicasToolStripMenuItem
			// 
			this->operacionesLogicasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nOTToolStripMenuItem,
					this->aNDToolStripMenuItem, this->oRToolStripMenuItem
			});
			this->operacionesLogicasToolStripMenuItem->Name = L"operacionesLogicasToolStripMenuItem";
			this->operacionesLogicasToolStripMenuItem->Size = System::Drawing::Size(128, 20);
			this->operacionesLogicasToolStripMenuItem->Text = L"Operaciones Logicas";
			// 
			// nOTToolStripMenuItem
			// 
			this->nOTToolStripMenuItem->Name = L"nOTToolStripMenuItem";
			this->nOTToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->nOTToolStripMenuItem->Text = L"NOT";
			// 
			// aNDToolStripMenuItem
			// 
			this->aNDToolStripMenuItem->Name = L"aNDToolStripMenuItem";
			this->aNDToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->aNDToolStripMenuItem->Text = L"AND";
			// 
			// oRToolStripMenuItem
			// 
			this->oRToolStripMenuItem->Name = L"oRToolStripMenuItem";
			this->oRToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->oRToolStripMenuItem->Text = L"OR";
			// 
			// histogramaToolStripMenuItem
			// 
			this->histogramaToolStripMenuItem->Name = L"histogramaToolStripMenuItem";
			this->histogramaToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->histogramaToolStripMenuItem->Text = L"Histograma";
			this->histogramaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramaToolStripMenuItem_Click);
			// 
			// filtrosToolStripMenuItem
			// 
			this->filtrosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->pasaAltasToolStripMenuItem,
					this->pasaBajasToolStripMenuItem, this->pasaBandaToolStripMenuItem
			});
			this->filtrosToolStripMenuItem->Name = L"filtrosToolStripMenuItem";
			this->filtrosToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->filtrosToolStripMenuItem->Text = L"Filtros";
			// 
			// pasaAltasToolStripMenuItem
			// 
			this->pasaAltasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->promedioToolStripMenuItem,
					this->sobelToolStripMenuItem
			});
			this->pasaAltasToolStripMenuItem->Name = L"pasaAltasToolStripMenuItem";
			this->pasaAltasToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->pasaAltasToolStripMenuItem->Text = L"Pasa Altas";
			// 
			// promedioToolStripMenuItem
			// 
			this->promedioToolStripMenuItem->Name = L"promedioToolStripMenuItem";
			this->promedioToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->promedioToolStripMenuItem->Text = L"Promedio";
			this->promedioToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::promedioToolStripMenuItem_Click);
			// 
			// sobelToolStripMenuItem
			// 
			this->sobelToolStripMenuItem->Name = L"sobelToolStripMenuItem";
			this->sobelToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->sobelToolStripMenuItem->Text = L"Sobel";
			this->sobelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sobelToolStripMenuItem_Click);
			// 
			// pasaBajasToolStripMenuItem
			// 
			this->pasaBajasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->promediadorToolStripMenuItem,
					this->gaussiandoToolStripMenuItem
			});
			this->pasaBajasToolStripMenuItem->Name = L"pasaBajasToolStripMenuItem";
			this->pasaBajasToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->pasaBajasToolStripMenuItem->Text = L"Pasa Bajas";
			// 
			// promediadorToolStripMenuItem
			// 
			this->promediadorToolStripMenuItem->Name = L"promediadorToolStripMenuItem";
			this->promediadorToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->promediadorToolStripMenuItem->Text = L"Promediador";
			this->promediadorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::promediadorToolStripMenuItem_Click);
			// 
			// gaussiandoToolStripMenuItem
			// 
			this->gaussiandoToolStripMenuItem->Name = L"gaussiandoToolStripMenuItem";
			this->gaussiandoToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->gaussiandoToolStripMenuItem->Text = L"Gaussiano";
			this->gaussiandoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::gaussiandoToolStripMenuItem_Click);
			// 
			// pasaBandaToolStripMenuItem
			// 
			this->pasaBandaToolStripMenuItem->Name = L"pasaBandaToolStripMenuItem";
			this->pasaBandaToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->pasaBandaToolStripMenuItem->Text = L"Pasa Banda";
			// 
			// imagick
			// 
			this->imagick->Location = System::Drawing::Point(641, 58);
			this->imagick->Name = L"imagick";
			this->imagick->Size = System::Drawing::Size(75, 23);
			this->imagick->TabIndex = 8;
			this->imagick->Text = L"Imagick";
			this->imagick->UseVisualStyleBackColor = true;
			this->imagick->Click += gcnew System::EventHandler(this, &MyForm::imagick_Click);
			// 
			// convolucion
			// 
			this->convolucion->Location = System::Drawing::Point(641, 121);
			this->convolucion->Name = L"convolucion";
			this->convolucion->Size = System::Drawing::Size(75, 23);
			this->convolucion->TabIndex = 9;
			this->convolucion->Text = L"convolucion";
			this->convolucion->UseVisualStyleBackColor = true;
			this->convolucion->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// PromedioManual
			// 
			this->PromedioManual->Location = System::Drawing::Point(641, 185);
			this->PromedioManual->Name = L"PromedioManual";
			this->PromedioManual->Size = System::Drawing::Size(75, 23);
			this->PromedioManual->TabIndex = 10;
			this->PromedioManual->Text = L"Promedio";
			this->PromedioManual->UseVisualStyleBackColor = true;
			this->PromedioManual->Click += gcnew System::EventHandler(this, &MyForm::PromedioManual_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(859, 720);
			this->Controls->Add(this->PromedioManual);
			this->Controls->Add(this->convolucion);
			this->Controls->Add(this->imagick);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		OpPuntual *negativo1;
		//OpPuntual negativo;
		//negativo.Negativo();
		negativo1 = new OpPuntual();
		negativo1->Negativo();
		delete negativo1;
		
		//negativo1->Negativo;
		//negativo.~OpPuntual;
		pictureBox1->ImageLocation = rutaSalida;
	}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	abreImagen->Filter = "Bmp files (*.bmp)|*.bmp";
	abreImagen->ShowDialog();
	String^ ruta = abreImagen->FileName;
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(ruta);
	rutaChar = static_cast<char*>(ptrToNativeString.ToPointer());
	//array<Char^>^ rutachar = ruta ->ToCharArray;
	copia_total(rutaChar);

	pictureBox1->ImageLocation = ruta;
	


	

}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *brillo;
	brillo = new OpPuntual();
	brillo->Brillo(trackBar1->Value);
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//aumentoBrillo();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void binarizar_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *binarizar;
	binarizar = new OpPuntual();
	binarizar->Binarizar(128);
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void negativoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *negativo1;
	//OpPuntual negativo;
	//negativo.Negativo();
	negativo1 = new OpPuntual();
	negativo1->Negativo();
	delete negativo1;

	//negativo1->Negativo;
	//negativo.~OpPuntual;
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void binanirzarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *binarizar;
	binarizar = new OpPuntual();
	binarizar->Binarizar(128);
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void aumentarDisminiuirBrilloToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *brillo;
	brillo = new OpPuntual();
	brillo->Brillo(trackBar1->Value);
	pictureBox1->ImageLocation = rutaSalida;
}

private: System::Void abrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	abreImagen->Filter = "Bmp files (*.bmp)|*.bmp";
	abreImagen->ShowDialog();
	String^ ruta = abreImagen->FileName;
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(ruta);
	rutaChar = static_cast<char*>(ptrToNativeString.ToPointer());
	//array<Char^>^ rutachar = ruta ->ToCharArray;
	copia_total(rutaChar);

	pictureBox1->ImageLocation = ruta;
}
private: System::Void sepiaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *sepia;
	sepia = new OpPuntual();
	sepia->Sepia();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void grisesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *gray;
	gray = new OpPuntual();
	gray->Grises();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void rEDToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *gray;
	gray = new OpPuntual();
	gray->Red();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void gREENToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *gray;
	gray = new OpPuntual();
	gray->Green();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void bLUEToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpPuntual *gray;
	gray = new OpPuntual();
	gray->Blue();
	pictureBox1->ImageLocation = rutaSalida;
}

private: System::Void imagick_Click(System::Object^  sender, System::EventArgs^  e) {
	Magick::InitializeMagick("");
	char* copy = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy.bmp";
	char* copy_arith = "C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_arith.bmp";
	Magick::Image image1;
	Magick::Image image2;
	ColorRGB px;
	//Color pxsepi;
	ColorMono pxmono;
	
	//Magick::pixelColorImage *pixelcolor;

	//Blob blob;
	//image1.modifyImage();
	try {
		// Read a file into image object 

		image1.read(copy);
		image1.type(GrayscaleType);
		//image1.type(GrayscaleType);
		//int height = image1.columns();
		//int width = image1.rows();
		//image1.normalize();
		//image1.monochrome(TRUE);
		//image2.read(copy_arith);
		//image1.magick("BMP");
		
		///////////////////////////////////////////7image1.negate();
		//image1.syncPixels();
		image1.threshold(100);
		image1.write("C:\\Users\\boozh\\Documents\\8oSemestre\\Analisis_de_Imagenes\\Ejercicios\\ImageOutput_1\\copy_blob.bmp");
		//image1.write(&blob);
	}
	catch (Magick::Exception &error_) {
		printf("un intento");
	}
}
private: System::Void filtrosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void operacionesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void sumaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	abreImagen->Filter = "Bmp files (*.bmp)|*.bmp";
	abreImagen->ShowDialog();
	String^ rutaArith = abreImagen->FileName;
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(rutaArith);
	rutaChar_arith = static_cast<char*>(ptrToNativeString.ToPointer());
	//array<Char^>^ rutachar = ruta ->ToCharArray;
	copia_total_arith(rutaChar_arith);

	OpAritmetica *arith;
	arith = new OpAritmetica();
	arith->suma();
	pictureBox1->ImageLocation = rutaSalida;

	//pictureBox1->ImageLocation = ruta;
}
private: System::Void restaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	abreImagen->Filter = "Bmp files (*.bmp)|*.bmp";
	abreImagen->ShowDialog();
	String^ rutaArith = abreImagen->FileName;
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(rutaArith);
	rutaChar_arith = static_cast<char*>(ptrToNativeString.ToPointer());
	//array<Char^>^ rutachar = ruta ->ToCharArray;
	copia_total_arith(rutaChar_arith);

	OpAritmetica *arith;
	arith = new OpAritmetica();
	arith->resta();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void histogramaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	histograma *histo;
	histo = new histograma();
	//histo->mostrar();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	gImageAltas *filtro;
	filtro = new gImageAltas();
	filtro->filtroSobel();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void sobelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	gImageAltas *filtro;
	filtro = new gImageAltas();
	filtro->filtroSobel();
	pictureBox1->ImageLocation = rutaSalida;

}
private: System::Void promedioToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	gImageAltas *filtro;
	filtro = new gImageAltas();
	filtro->filtroPromedio();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void gaussiandoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	gImageBajas *filtro;
	filtro = new gImageBajas();
	filtro->filtroPromedioManual();
	pictureBox1->ImageLocation = rutaSalida;
}
private: System::Void PromedioManual_Click(System::Object^  sender, System::EventArgs^  e) {
	gImageBajas *filtro;
	//filtro = new gImage
}
private: System::Void promediadorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
