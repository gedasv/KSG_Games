#pragma once

#include "chess_rules.h"
#include "chess_bot.h"
#include "msclr\marshal_cppstd.h"

namespace KSGGames {

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
		bool whitesMove;
	}

	/// <summary>
	/// Summary for Chess
	/// </summary>
	public ref class Chess : public System::Windows::Forms::Form
	{

	public:
		Chess(void)
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

					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

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

					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

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

					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

					/*System::Drawing::Image^ img1 = safe_cast<PictureBox^>(sender)->BackgroundImage;
					safe_cast<PictureBox^>(sender)->BackgroundImage = backImg;
					fromBox->BackgroundImage = img1;
					safe_cast<PictureBox^>(sender)->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("")));

					System::Drawing::Point coord1 = safe_cast<PictureBox^>(sender)->Location;
					safe_cast<PictureBox^>(sender)->Location = fromBox->Location;
					fromBox->Location = coord1;*/

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
					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

			fromBox = safe_cast<PictureBox^>(sender);
			backImg = fromBox->BackgroundImage;
			fromBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("greenSquare.BackgroundImage")));
			ableToSwap = true;
		}
	}

	private: System::Void choosePawn(System::Object^  sender, System::EventArgs^  e)
	{
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

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
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

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
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));

		picBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(name)));

		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ addBoardClick(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click += gcnew System::EventHandler(this, &Chess::boxClick);
		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ removeBoardClick(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click -= gcnew System::EventHandler(this, &Chess::boxClick);
		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ addChoosePawn(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click += gcnew System::EventHandler(this, &Chess::choosePawn);
		return picBox;
	}

	private: System::Windows::Forms::PictureBox^ removeChoosePawn(System::Windows::Forms::PictureBox^ picBox)
	{
		picBox->Click -= gcnew System::EventHandler(this, &Chess::choosePawn);
		return picBox;
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Chess()
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

	private: System::Windows::Forms::PictureBox^  darkSquare;
	private: System::Windows::Forms::PictureBox^  greySquare;
	private: System::Windows::Forms::PictureBox^  whitePawn;
	private: System::Windows::Forms::PictureBox^  blackPawn;
	private: System::Windows::Forms::PictureBox^  blackBishop;
	private: System::Windows::Forms::PictureBox^  blackKing;
	private: System::Windows::Forms::PictureBox^  blackQueen;
	private: System::Windows::Forms::PictureBox^  blackRook;
	private: System::Windows::Forms::PictureBox^  whiteBishop;
	private: System::Windows::Forms::PictureBox^  whiteKing;

	private: System::Windows::Forms::PictureBox^  whiteQueen;
	private: System::Windows::Forms::PictureBox^  whiteRook;
	private: System::Windows::Forms::PictureBox^  blackKnight;
	private: System::Windows::Forms::PictureBox^  whiteKnight;
	private: System::Windows::Forms::PictureBox^  greenSquare;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Chess::typeid));
			this->darkSquare = (gcnew System::Windows::Forms::PictureBox());
			this->greySquare = (gcnew System::Windows::Forms::PictureBox());
			this->whitePawn = (gcnew System::Windows::Forms::PictureBox());
			this->blackPawn = (gcnew System::Windows::Forms::PictureBox());
			this->blackBishop = (gcnew System::Windows::Forms::PictureBox());
			this->blackKing = (gcnew System::Windows::Forms::PictureBox());
			this->blackQueen = (gcnew System::Windows::Forms::PictureBox());
			this->blackRook = (gcnew System::Windows::Forms::PictureBox());
			this->whiteBishop = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKing = (gcnew System::Windows::Forms::PictureBox());
			this->whiteQueen = (gcnew System::Windows::Forms::PictureBox());
			this->whiteRook = (gcnew System::Windows::Forms::PictureBox());
			this->blackKnight = (gcnew System::Windows::Forms::PictureBox());
			this->whiteKnight = (gcnew System::Windows::Forms::PictureBox());
			this->greenSquare = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->darkSquare))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greySquare))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKing))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackQueen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKing))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteQueen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenSquare))->BeginInit();
			this->SuspendLayout();
			// 
			// darkSquare
			// 
			this->darkSquare->Location = System::Drawing::Point(13, 13);
			this->darkSquare->Name = L"darkSquare";
			this->darkSquare->Size = System::Drawing::Size(10, 10);
			this->darkSquare->TabIndex = 0;
			this->darkSquare->TabStop = false;
			this->darkSquare->Visible = false;
			// 
			// greySquare
			// 
			this->greySquare->Location = System::Drawing::Point(13, 30);
			this->greySquare->Name = L"greySquare";
			this->greySquare->Size = System::Drawing::Size(10, 10);
			this->greySquare->TabIndex = 1;
			this->greySquare->TabStop = false;
			this->greySquare->Visible = false;
			// 
			// whitePawn
			// 
			this->whitePawn->Location = System::Drawing::Point(13, 47);
			this->whitePawn->Name = L"whitePawn";
			this->whitePawn->Size = System::Drawing::Size(10, 10);
			this->whitePawn->TabIndex = 2;
			this->whitePawn->TabStop = false;
			this->whitePawn->Visible = false;
			// 
			// blackPawn
			// 
			this->blackPawn->Location = System::Drawing::Point(13, 64);
			this->blackPawn->Name = L"blackPawn";
			this->blackPawn->Size = System::Drawing::Size(10, 10);
			this->blackPawn->TabIndex = 3;
			this->blackPawn->TabStop = false;
			this->blackPawn->Visible = false;
			// 
			// blackBishop
			// 
			this->blackBishop->Location = System::Drawing::Point(29, 64);
			this->blackBishop->Name = L"blackBishop";
			this->blackBishop->Size = System::Drawing::Size(10, 10);
			this->blackBishop->TabIndex = 4;
			this->blackBishop->TabStop = false;
			this->blackBishop->Visible = false;
			// 
			// blackKing
			// 
			this->blackKing->Location = System::Drawing::Point(45, 64);
			this->blackKing->Name = L"blackKing";
			this->blackKing->Size = System::Drawing::Size(10, 10);
			this->blackKing->TabIndex = 5;
			this->blackKing->TabStop = false;
			this->blackKing->Visible = false;
			// 
			// blackQueen
			// 
			this->blackQueen->Location = System::Drawing::Point(61, 64);
			this->blackQueen->Name = L"blackQueen";
			this->blackQueen->Size = System::Drawing::Size(10, 10);
			this->blackQueen->TabIndex = 6;
			this->blackQueen->TabStop = false;
			this->blackQueen->Visible = false;
			// 
			// blackRook
			// 
			this->blackRook->Location = System::Drawing::Point(77, 64);
			this->blackRook->Name = L"blackRook";
			this->blackRook->Size = System::Drawing::Size(10, 10);
			this->blackRook->TabIndex = 7;
			this->blackRook->TabStop = false;
			this->blackRook->Visible = false;
			// 
			// whiteBishop
			// 
			this->whiteBishop->Location = System::Drawing::Point(29, 48);
			this->whiteBishop->Name = L"whiteBishop";
			this->whiteBishop->Size = System::Drawing::Size(10, 10);
			this->whiteBishop->TabIndex = 8;
			this->whiteBishop->TabStop = false;
			this->whiteBishop->Visible = false;
			// 
			// whiteKing
			// 
			this->whiteKing->Location = System::Drawing::Point(45, 48);
			this->whiteKing->Name = L"whiteKing";
			this->whiteKing->Size = System::Drawing::Size(10, 10);
			this->whiteKing->TabIndex = 9;
			this->whiteKing->TabStop = false;
			this->whiteKing->Visible = false;
			// 
			// whiteQueen
			// 
			this->whiteQueen->Location = System::Drawing::Point(77, 47);
			this->whiteQueen->Name = L"whiteQueen";
			this->whiteQueen->Size = System::Drawing::Size(10, 10);
			this->whiteQueen->TabIndex = 11;
			this->whiteQueen->TabStop = false;
			this->whiteQueen->Visible = false;
			// 
			// whiteRook
			// 
			this->whiteRook->Location = System::Drawing::Point(93, 48);
			this->whiteRook->Name = L"whiteRook";
			this->whiteRook->Size = System::Drawing::Size(10, 10);
			this->whiteRook->TabIndex = 12;
			this->whiteRook->TabStop = false;
			this->whiteRook->Visible = false;
			// 
			// blackKnight
			// 
			this->blackKnight->Location = System::Drawing::Point(94, 65);
			this->blackKnight->Name = L"blackKnight";
			this->blackKnight->Size = System::Drawing::Size(10, 10);
			this->blackKnight->TabIndex = 13;
			this->blackKnight->TabStop = false;
			this->blackKnight->Visible = false;
			// 
			// whiteKnight
			// 
			this->whiteKnight->Location = System::Drawing::Point(61, 47);
			this->whiteKnight->Name = L"whiteKnight";
			this->whiteKnight->Size = System::Drawing::Size(10, 10);
			this->whiteKnight->TabIndex = 14;
			this->whiteKnight->TabStop = false;
			this->whiteKnight->Visible = false;
			// 
			// greenSquare
			// 
			this->greenSquare->BackColor = System::Drawing::SystemColors::Control;
			this->greenSquare->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"greenSquare.BackgroundImage")));
			this->greenSquare->Location = System::Drawing::Point(30, 13);
			this->greenSquare->Name = L"greenSquare";
			this->greenSquare->Size = System::Drawing::Size(10, 10);
			this->greenSquare->TabIndex = 15;
			this->greenSquare->TabStop = false;
			this->greenSquare->Visible = false;
			// 
			// Chess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 720);
			this->Controls->Add(this->greenSquare);
			this->Controls->Add(this->whiteKnight);
			this->Controls->Add(this->blackKnight);
			this->Controls->Add(this->whiteRook);
			this->Controls->Add(this->whiteQueen);
			this->Controls->Add(this->whiteKing);
			this->Controls->Add(this->whiteBishop);
			this->Controls->Add(this->blackRook);
			this->Controls->Add(this->blackQueen);
			this->Controls->Add(this->blackKing);
			this->Controls->Add(this->blackBishop);
			this->Controls->Add(this->blackPawn);
			this->Controls->Add(this->whitePawn);
			this->Controls->Add(this->greySquare);
			this->Controls->Add(this->darkSquare);
			this->Name = L"Chess";
			this->Text = L"Chess";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->darkSquare))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greySquare))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whitePawn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackPawn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackBishop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKing))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackQueen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackRook))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteBishop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKing))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteQueen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteRook))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blackKnight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->whiteKnight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenSquare))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

};
}