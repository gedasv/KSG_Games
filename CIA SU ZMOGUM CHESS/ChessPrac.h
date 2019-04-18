#pragma once

#include "chess_rules.h"
#include "msclr\marshal_cppstd.h"

namespace ChessPrac {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	namespace
	{
		Square Chess_Board[8][8];
		Square Test_Board[8][8];
		std::string Types[9];
	}

	/// <summary>
	/// Summary for Chess
	/// </summary>
	public ref class ChessPrac : public System::Windows::Forms::Form
	{

	public:
		ChessPrac(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			System::Windows::Forms::Control::SetStyle(System::Windows::Forms::ControlStyles::SupportsTransparentBackColor, true);

			Board = gcnew array<System::Windows::Forms::PictureBox^, 2>(8, 8);
			ChangePawn = gcnew array<System::Windows::Forms::PictureBox^, 2>(2, 2);

			Pictures = gcnew array<String^>(8);
			Pictures[0] = "Rook.Image";
			Pictures[1] = "Knight.Image";
			Pictures[2] = "Bishop.Image";
			Pictures[3] = "Queen.Image";
			Pictures[4] = "King.Image";
			Pictures[5] = "Bishop.Image";
			Pictures[6] = "Knight.Image";
			Pictures[7] = "Rook.Image";

			Types[0] = "Rook";
			Types[1] = "Knight";
			Types[2] = "Bishop";
			Types[3] = "Queen";
			Types[4] = "King";
			Types[5] = "Bishop";
			Types[6] = "Knight";
			Types[7] = "Rook";

			whitesMove = true;

			for (int i = 0; i < 2; i++)
			{
				System::String^ box = "";
				for (int j = 0; j < 2; j++)
				{
					if ((i + j) % 2 == 0) box = "darkSquare.BackgroundImage";
					else box = "greySquare.BackgroundImage";

					ChangePawn[i, j] = startBoxInit(ChangePawn[i, j], i * 80 + 720, j * 80 + 40, box);
					ChangePawn[i, j] = endBoxInit(ChangePawn[i, j]);
				}
			}

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					System::String^ box = "";

					if ((i + j) % 2 == 0) box = "darkSquare.BackgroundImage";
					else box = "greySquare.BackgroundImage";

					Board[i, j] = startBoxInit(Board[i, j], i * 80 + 40, j * 80 + 40, box);
					Board[i, j] = addBoardClick(Board[i, j]);
				}
			}

			for (int i = 0; i < 8; i++)
			{
				Board[i, 0] = addPieceImg(Board[i, 0], "black" + Pictures[i]);
				Board[i, 1] = addPieceImg(Board[i, 1], "blackPawn.Image");
				Board[i, 6] = addPieceImg(Board[i, 6], "whitePawn.Image");
				Board[i, 7] = addPieceImg(Board[i, 7], "white" + Pictures[i]);

				for (int j = 0; j < 8; j++)
				{
					if (j < 2) Chess_Board[i][j].SetTeam("black");
					else if (j > 5) Chess_Board[i][j].SetTeam("white");
					else Chess_Board[i][j].SetTeam("neutral");

					if (j == 1 || j == 6) Chess_Board[i][j].SetType("Pawn");
					else if (j < 2 || j > 5) Chess_Board[i][j].SetType(Types[i]);
				}
			}

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					Board[i, j] = endBoxInit(Board[i, j]);
				}
			}
		}

	private: System::Void boxClick(System::Object^  sender, System::EventArgs^  e)
	{
		if (ableToSwap)
		{
			ableToSwap = false;
			bool Test_Move = whitesMove;

			int xFrom, yFrom, xTo, yTo;
			xFrom = (fromBox->Location.X - 40) / 80;
			yFrom = (fromBox->Location.Y - 40) / 80;
			xTo = (safe_cast<PictureBox^>(sender)->Location.X - 40) / 80;
			yTo = (safe_cast<PictureBox^>(sender)->Location.Y - 40) / 80;

			copyArr(Chess_Board, Test_Board);

			if ( firstCheckUp(Test_Board, xFrom, yFrom, xTo, yTo, Test_Move) )
			{
				if ( elPass(Test_Board, xFrom, yFrom, xTo, yTo, Test_Move) && !checkAfter(Test_Board, Test_Move))
				{
					copyArr(Test_Board, Chess_Board);
					whitesMove = Test_Move;
					clearMoved(Chess_Board, Test_Move);

					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

					Board[xTo, yTo]->Image = Board[xFrom, yFrom]->Image;
					Board[xFrom, yFrom]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("")));
					Board[xFrom, yFrom]->BackgroundImage = backImg;
					Board[xTo, yTo - 1]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("")));

				}

				else if ( castling(Test_Board, xFrom, yFrom, xTo, yTo, Test_Move) )
				{
					copyArr(Test_Board, Chess_Board);
					whitesMove = Test_Move;
					clearMoved(Chess_Board, Test_Move);

					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

					Board[xTo, yTo]->Image = Board[xFrom, yFrom]->Image;
					Board[xFrom, yFrom]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("")));
					Board[xFrom, yFrom]->BackgroundImage = backImg;

					int rookX;
					if (xTo > xFrom) rookX = 7;
					else rookX = 0;

					Board[(xTo + xFrom) / 2, yTo]->Image = Board[rookX, yTo]->Image;
					Board[rookX, yTo]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("")));
				}

				else if (otherMove(Test_Board, xFrom, yFrom, xTo, yTo, Test_Move) && !checkAfter(Test_Board, Test_Move))
				{
					copyArr(Test_Board, Chess_Board);
					whitesMove = Test_Move;
					clearMoved(Chess_Board, Test_Move);

					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

					Board[xTo, yTo]->Image = Board[xFrom, yFrom]->Image;
					Board[xFrom, yFrom]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("")));
					Board[xFrom, yFrom]->BackgroundImage = backImg;
				}

				else
				{
					fromBox->BackgroundImage = backImg;
				}

				if (endPawn(Chess_Board, whitesMove))
				{
					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							Board[i, j] = removeBoardClick(Board[i, j]);
						}
					}

					String^ PawnTo = "";

					if (whitesMove) PawnTo += "black";
					else PawnTo += "white";

					for (int i = 0; i < 2; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							int sk = (i * 2) +j;
							String^ picture = PawnTo + Pictures[sk];
							ChangePawn[i, j]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(picture)));
							ChangePawn[i, j] = addChoosePawn(ChangePawn[i, j]);
						}
					}


				}
			}

			else
			{
				fromBox->BackgroundImage = backImg;
			}
		}

		else
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

			fromBox = safe_cast<PictureBox^>(sender);
			backImg = fromBox->BackgroundImage;
			fromBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("greenSquare.BackgroundImage")));
			ableToSwap = true;
		}
	}

	private: System::Void choosePawn(System::Object^  sender, System::EventArgs^  e)
	{
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				ChangePawn[i, j] = removeChoosePawn(ChangePawn[i, j]);
				ChangePawn[i, j]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("")));
			}
		}

		int x, y;
		x = (safe_cast<PictureBox^>(sender)->Location.X - 720) / 80;
		y = (safe_cast<PictureBox^>(sender)->Location.Y - 40) / 80;

		std::string type = "";

		if (x == 0)
		{
			if (y == 0) type = "Rook";
			else type = "Knight";
		}
		else
		{
			if (y == 0) type = "Bishop";
			else type = "Queen";
		}

		std::string loc = changeEndPawn(Chess_Board, type);
		x = loc[0] - '0';
		y = loc[1] - '0';

		type += ".Image";

		std::string picture;

		if (y == 0) picture = "white" + type;
		else picture = "black" + type;

		String^ typeS = msclr::interop::marshal_as<String^>(picture);
		Board[x, y]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(typeS)));

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Board[i, j] = addBoardClick(Board[i, j]);
			}
		}
	}

	private: System::Windows::Forms::PictureBox^ startBoxInit(System::Windows::Forms::PictureBox^ picBox, int x, int y, System::String^ name)
	{
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

		picBox = gcnew System::Windows::Forms::PictureBox();

		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(picBox))->BeginInit();

		picBox->BackColor = System::Drawing::Color::Transparent;
		picBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(name)));
		picBox->Location = System::Drawing::Point(x, y);
		picBox->Size = System::Drawing::Size(picSize, picSize);
		picBox->TabIndex = 0;
		picBox->TabStop = false;

		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ endBoxInit(System::Windows::Forms::PictureBox^ picBox)
	{
		this->Controls->Add(picBox);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(picBox))->EndInit();

		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ addPieceImg(System::Windows::Forms::PictureBox^ picBox, System::String^ name)
	{
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessPrac::typeid));

		picBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(name)));

		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ addBoardClick(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click += gcnew System::EventHandler(this, &ChessPrac::boxClick);
		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ removeBoardClick(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click -= gcnew System::EventHandler(this, &ChessPrac::boxClick);
		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ addChoosePawn(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click += gcnew System::EventHandler(this, &ChessPrac::choosePawn);
		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ removeChoosePawn(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click -= gcnew System::EventHandler(this, &ChessPrac::choosePawn);
		return picBox;
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChessPrac()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ fromBox;
			 System::Drawing::Image^ backImg;
			 System::Boolean ableToSwap = false;
			 double picSize = 80;
			 array<System::Windows::Forms::PictureBox^, 2>^ Board;
			 array<System::String^ >^ Pictures;
			 array<System::Windows::Forms::PictureBox^, 2>^ ChangePawn;
			 bool whitesMove;



















	protected:


	protected:

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
			// Chess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 720);
			this->Name = L"Chess";
			this->Text = L"Chess";
			this->ResumeLayout(false);

		}
#pragma endregion

};
}