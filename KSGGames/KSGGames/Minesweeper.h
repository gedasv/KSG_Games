#pragma once

#include "minesweeper_rules.h"
#include "msclr\marshal_cppstd.h"

namespace KSGGames {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Minesweeper
	/// </summary>
	public ref class Minesweeper : public System::Windows::Forms::Form
	{
	public:
		Minesweeper(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			int xLength = 10, yLength = 10;

			Board = gcnew array<System::Windows::Forms::PictureBox^, 2>(xLength, yLength);

			/*
			Pictures = gcnew array<String^>(10);
			Pictures[0] = "bgTile.Image";
			Pictures[1] = "number1.Image";
			Pictures[2] = "number2.Image";
			Pictures[3] = "number3.Image";
			Pictures[4] = "number4.Image";
			Pictures[5] = "number5.Image";
			Pictures[6] = "number6.Image";
			Pictures[7] = "number7.Image";
			Pictures[8] = "number8.Image";
			Pictures[9] = "bomb.Image";
			Pictures[10] = "flag.Image";
			Pictures[11] = "frontTile.Image";
			*/

			
			for (int i = 0; i < xLength; i++)
			{
				for (int j = 0; j < yLength; j++)
				{
					Tile tile(i, j);

					//System::String^ box = "";

					//box = "bgTile.BackgroundImage";
			

					//Board[i, j] = startBoxInit(Board[i, j], i * 80 + 40, j * 80 + 40, box);
					//Board[i, j] = addBoardClick(Board[i, j]);
				}
			}
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Minesweeper()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Drawing::Image^ backImg;
			 double picSize = 50;
			 array<System::Windows::Forms::PictureBox^, 2>^ Board;
			 array<System::String^ >^ Pictures;

	private: System::Windows::Forms::PictureBox^  bomb;
	private: System::Windows::Forms::PictureBox^  flag;
	private: System::Windows::Forms::PictureBox^  frontTile;

	private: System::Windows::Forms::PictureBox^  number1;
	private: System::Windows::Forms::PictureBox^  number2;
	private: System::Windows::Forms::PictureBox^  number3;
	private: System::Windows::Forms::PictureBox^  number4;
	private: System::Windows::Forms::PictureBox^  number5;
	private: System::Windows::Forms::PictureBox^  number6;
	private: System::Windows::Forms::PictureBox^  number7;
	private: System::Windows::Forms::PictureBox^  number8;
	private: System::Windows::Forms::PictureBox^  bgTile;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Minesweeper::typeid));
			this->bomb = (gcnew System::Windows::Forms::PictureBox());
			this->flag = (gcnew System::Windows::Forms::PictureBox());
			this->frontTile = (gcnew System::Windows::Forms::PictureBox());
			this->number1 = (gcnew System::Windows::Forms::PictureBox());
			this->number2 = (gcnew System::Windows::Forms::PictureBox());
			this->number3 = (gcnew System::Windows::Forms::PictureBox());
			this->number4 = (gcnew System::Windows::Forms::PictureBox());
			this->number5 = (gcnew System::Windows::Forms::PictureBox());
			this->number6 = (gcnew System::Windows::Forms::PictureBox());
			this->number7 = (gcnew System::Windows::Forms::PictureBox());
			this->number8 = (gcnew System::Windows::Forms::PictureBox());
			this->bgTile = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bomb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frontTile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bgTile))->BeginInit();
			this->SuspendLayout();
			// 
			// bomb
			// 
			this->bomb->BackColor = System::Drawing::Color::Transparent;
			this->bomb->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bomb.Image")));
			this->bomb->Location = System::Drawing::Point(15, 68);
			this->bomb->Name = L"bomb";
			this->bomb->Size = System::Drawing::Size(50, 50);
			this->bomb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bomb->TabIndex = 8;
			this->bomb->TabStop = false;
			this->bomb->Visible = false;
			// 
			// flag
			// 
			this->flag->BackColor = System::Drawing::Color::Transparent;
			this->flag->Cursor = System::Windows::Forms::Cursors::No;
			this->flag->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"flag.Image")));
			this->flag->Location = System::Drawing::Point(71, 68);
			this->flag->Name = L"flag";
			this->flag->Size = System::Drawing::Size(50, 50);
			this->flag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->flag->TabIndex = 9;
			this->flag->TabStop = false;
			this->flag->Visible = false;
			// 
			// frontTile
			// 
			this->frontTile->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frontTile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"frontTile.Image")));
			this->frontTile->Location = System::Drawing::Point(15, 124);
			this->frontTile->Name = L"frontTile";
			this->frontTile->Size = System::Drawing::Size(50, 50);
			this->frontTile->TabIndex = 10;
			this->frontTile->TabStop = false;
			this->frontTile->Visible = false;
			// 
			// number1
			// 
			this->number1->BackColor = System::Drawing::Color::Transparent;
			this->number1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number1.Image")));
			this->number1->Location = System::Drawing::Point(15, 12);
			this->number1->Name = L"number1";
			this->number1->Size = System::Drawing::Size(50, 50);
			this->number1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number1->TabIndex = 11;
			this->number1->TabStop = false;
			this->number1->Visible = false;
			// 
			// number2
			// 
			this->number2->BackColor = System::Drawing::Color::Transparent;
			this->number2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number2.Image")));
			this->number2->Location = System::Drawing::Point(71, 12);
			this->number2->Name = L"number2";
			this->number2->Size = System::Drawing::Size(50, 50);
			this->number2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number2->TabIndex = 12;
			this->number2->TabStop = false;
			this->number2->Visible = false;
			// 
			// number3
			// 
			this->number3->BackColor = System::Drawing::Color::Transparent;
			this->number3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number3.Image")));
			this->number3->Location = System::Drawing::Point(127, 12);
			this->number3->Name = L"number3";
			this->number3->Size = System::Drawing::Size(50, 50);
			this->number3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number3->TabIndex = 13;
			this->number3->TabStop = false;
			this->number3->Visible = false;
			// 
			// number4
			// 
			this->number4->BackColor = System::Drawing::Color::Transparent;
			this->number4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number4.Image")));
			this->number4->Location = System::Drawing::Point(183, 12);
			this->number4->Name = L"number4";
			this->number4->Size = System::Drawing::Size(50, 50);
			this->number4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number4->TabIndex = 14;
			this->number4->TabStop = false;
			this->number4->Visible = false;
			// 
			// number5
			// 
			this->number5->BackColor = System::Drawing::Color::Transparent;
			this->number5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number5.Image")));
			this->number5->Location = System::Drawing::Point(239, 12);
			this->number5->Name = L"number5";
			this->number5->Size = System::Drawing::Size(50, 50);
			this->number5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number5->TabIndex = 15;
			this->number5->TabStop = false;
			this->number5->Visible = false;
			// 
			// number6
			// 
			this->number6->BackColor = System::Drawing::Color::Transparent;
			this->number6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number6.Image")));
			this->number6->Location = System::Drawing::Point(295, 12);
			this->number6->Name = L"number6";
			this->number6->Size = System::Drawing::Size(50, 50);
			this->number6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number6->TabIndex = 16;
			this->number6->TabStop = false;
			this->number6->Visible = false;
			// 
			// number7
			// 
			this->number7->BackColor = System::Drawing::Color::Transparent;
			this->number7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number7.Image")));
			this->number7->Location = System::Drawing::Point(351, 12);
			this->number7->Name = L"number7";
			this->number7->Size = System::Drawing::Size(50, 50);
			this->number7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number7->TabIndex = 17;
			this->number7->TabStop = false;
			this->number7->Visible = false;
			// 
			// number8
			// 
			this->number8->BackColor = System::Drawing::Color::Transparent;
			this->number8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"number8.Image")));
			this->number8->Location = System::Drawing::Point(407, 12);
			this->number8->Name = L"number8";
			this->number8->Size = System::Drawing::Size(50, 50);
			this->number8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->number8->TabIndex = 18;
			this->number8->TabStop = false;
			this->number8->Visible = false;
			// 
			// bgTile
			// 
			this->bgTile->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bgTile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bgTile.Image")));
			this->bgTile->Location = System::Drawing::Point(71, 124);
			this->bgTile->Name = L"bgTile";
			this->bgTile->Size = System::Drawing::Size(50, 50);
			this->bgTile->TabIndex = 19;
			this->bgTile->TabStop = false;
			this->bgTile->Visible = false;
			// 
			// Minesweeper
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 591);
			this->Controls->Add(this->bgTile);
			this->Controls->Add(this->number8);
			this->Controls->Add(this->number7);
			this->Controls->Add(this->number6);
			this->Controls->Add(this->number5);
			this->Controls->Add(this->number4);
			this->Controls->Add(this->number3);
			this->Controls->Add(this->number2);
			this->Controls->Add(this->number1);
			this->Controls->Add(this->frontTile);
			this->Controls->Add(this->flag);
			this->Controls->Add(this->bomb);
			this->MaximizeBox = false;
			this->Name = L"Minesweeper";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Minesweeper";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bomb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frontTile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bgTile))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
