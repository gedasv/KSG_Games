#pragma once

#include "minesweeper_rules.h"
#include "msclr\marshal_cppstd.h"
#include "user.h"

namespace KSGGames {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int sizeX = 16;
	const int sizeY = 16;
	const int howManyBombs = 55;

	namespace {
		Tile tiles[sizeX][sizeY];
		User user1;

	}

	/// <summary>
	/// Summary for Minesweeper
	/// </summary>
	public ref class Minesweeper : public System::Windows::Forms::Form
	{
	public:
		Minesweeper(int id)
		{
			InitializeComponent();

			System::Windows::Forms::Control::SetStyle(System::Windows::Forms::ControlStyles::SupportsTransparentBackColor, true);

			user1.initUser(id);
			
			bombsInGame = 0, tilesNotOpened = sizeX*sizeY;
			tilesButtons = gcnew array<System::Windows::Forms::Button^, 2>(16, 16);

			initTileButtons(tilesButtons);
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

	protected:


	protected:
		array<System::Windows::Forms::Button^, 2>^ tilesButtons;
		bool bombsInitialized = false;
		int bombsInGame, tilesNotOpened;

	private: void initBombs(int bombAmount, int x, int y) {
		if (!bombsInitialized) {
			Random^ rand = gcnew Random;
			int bomb, bombX, bombY;

			// sudeda bombas (jos gali buti pasikartojancios)
			for (int i = 0; i < bombAmount; i++) {
				bomb = rand->Next(0, 256);
				bombX = bomb % 16;
				bombY = bomb / 16;

				if (bombX >= x - 1 && bombX <= x + 1 && bombY >= y - 1 && bombY <= y + 1)
					bombAmount++;
				else
					tiles[bombX][bombY].setBomb(true);
			}

			// suskaiciuoja kiek yra bombu lauke
			for (int i = 0; i < sizeX; i++)
				for (int j = 0; j < sizeY; j++)
					if (tiles[i][j].hasBomb())
						bombsInGame++;

			bombsInitialized = true;
		}
	}

	private: void showBombs() {
		for (int i = 0; i < sizeX; i++) {
			for (int j = 0; j < sizeY; j++) {
				if (tiles[i][j].hasBomb()) {
					initPicBox(0, i, j, "bomb");
				}
				tilesButtons[i, j]->Enabled = false;
			}
		}
	}

	private: void finishGame(bool won) {
		showBombs();
		if (won) {
			user1.configurePoints(5);
			MessageBox::Show("You've won! +5 points to your account.");
		}
		else {
			user1.configurePoints(-5);
			MessageBox::Show("You've lost! -3 points to your account.");
		}
	}

	private: System::Void boxClicked(System::Object^ sender, System::Windows::Forms::MouseEventArgs^  e) {
		System::Windows::Forms::Button^ tempButton = (System::Windows::Forms::Button^)sender;

		int buttonX = tempButton->Location.X / 50;
		int buttonY = tempButton->Location.Y / 50;

		if (!tiles[buttonX][buttonY].hasFlag()) {
			initBombs(howManyBombs, buttonX, buttonY);
			if (tiles[buttonX][buttonY].hasBomb()) {
				finishGame(false);
				return;
			}
			openTile(tempButton, buttonX, buttonY);
		}
	}

	private: System::Void setFlag(System::Object^ sender, System::Windows::Forms::MouseEventArgs^  e) {
		System::Windows::Forms::Button^ tempButton = (System::Windows::Forms::Button^)sender;

		int buttonX = tempButton->Location.X / 50;
		int buttonY = tempButton->Location.Y / 50;

		if (tiles[buttonX][buttonY].hasFlag()) {
			tiles[buttonX][buttonY].setFlag(false);
			tempButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			tempButton->BackColor = System::Drawing::Color::Transparent;
		}
		else {
			tiles[buttonX][buttonY].setFlag(true);
			tempButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			tempButton->BackColor = System::Drawing::Color::DarkRed;
		}
	}

	private: void openTile(System::Windows::Forms::Button^ tile, int x, int y) {
		tile->Hide(); tiles[x][y].setOpen(true); tilesNotOpened--;
		if (bombsInGame == tilesNotOpened) {
			finishGame(true);
		}

		int bombAmount = 0;

		// find how many bombs are around
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int nextX = x - 1 + i;
				int nextY = y - 1 + j;

				if (nextX < 0 || nextX > 15 || nextY < 0 || nextY > 15) {
					;
				}
				else if (tiles[nextX][nextY].hasBomb()) {
					bombAmount++;
				}
			}
		}

		if (bombAmount == 0) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int nextX = x - 1 + i;
					int nextY = y - 1 + j;

					if (nextX < 0 || nextX > 15 || nextY < 0 || nextY > 15) {
						;
					}
					else if (tiles[nextX][nextY].isOpen()) {
						;
					}
					else {
						openTile(tilesButtons[nextX, nextY], nextX, nextY);
					}
				}
			}
		}
		else {
			initPicBox(bombAmount, x, y, "Box");

		}
	}

	private: void initPicBox(int bombAmount, int x, int y, String^ imageText) {
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Minesweeper::typeid));

		System::Windows::Forms::PictureBox^ picBox = (gcnew System::Windows::Forms::PictureBox());

		if (imageText == "Box") {
			imageText = "Box" + bombAmount;
		}

		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(picBox))->BeginInit();

		picBox->BackColor = System::Drawing::Color::Transparent;
		//number->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		picBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(imageText + ".Image")));
		picBox->Location = System::Drawing::Point(x * 50, y * 50);
		picBox->Size = System::Drawing::Size(40, 40);
		picBox->Parent = this;
		picBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		picBox->TabIndex = 0;
		picBox->BringToFront();
		picBox->TabStop = false;

		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(picBox))->EndInit();
	}

	private: void initTileButtons(array<System::Windows::Forms::Button^, 2>^ tilesButtons) {
		for (int i = 0; i < sizeX; i++) {
			for (int j = 0; j < sizeY; j++) {
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Minesweeper::typeid));

				System::Windows::Forms::Button^ button = (gcnew System::Windows::Forms::Button());

				button->BackColor = System::Drawing::Color::Transparent;
				//button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gray1.Image")));
				button->Location = System::Drawing::Point(50 * i, 50 * j);
				button->FlatStyle = System::Windows::Forms::FlatStyle::System;
				button->Size = System::Drawing::Size(50, 50);
				button->TabIndex = 0;
				button->TabStop = false;
				button->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Minesweeper::mouseClickUp);
				this->Controls->Add(button);

				tilesButtons[i, j] = button;
			}
		}
	}

	private: System::Void mouseClickUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
			setFlag(sender, e);
		else
			boxClicked(sender, e);
	}

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
			this->SuspendLayout();
			// 
			// Minesweeper
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 801);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"Minesweeper";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Minesweeper";
			this->ResumeLayout(false);

		}
#pragma endregion

};
}
