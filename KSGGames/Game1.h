#pragma once

namespace KSGGames {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Game1
	/// </summary>
	public ref class Game1 : public System::Windows::Forms::Form
	{
	public:
		Game1(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game1()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:


	private: System::Windows::Forms::PictureBox^  black_horse_l;
	private: System::Windows::Forms::PictureBox^  black_rook_l;
	private: System::Windows::Forms::PictureBox^  black_knight_r;
	private: System::Windows::Forms::PictureBox^  black_queen;
	private: System::Windows::Forms::PictureBox^  black_king;
	private: System::Windows::Forms::PictureBox^  black_rook_r;
	private: System::Windows::Forms::PictureBox^  black_pawn_1;
	private: System::Windows::Forms::PictureBox^  black_pawn_2;
	private: System::Windows::Forms::PictureBox^  black_pawn_3;
	private: System::Windows::Forms::PictureBox^  black_pawn_4;
	private: System::Windows::Forms::PictureBox^  black_pawn_5;
	private: System::Windows::Forms::PictureBox^  black_pawn_6;
	private: System::Windows::Forms::PictureBox^  black_pawn_7;
	private: System::Windows::Forms::PictureBox^  black_pawn_8;
	private: System::Windows::Forms::PictureBox^  black_bishop_l;
	private: System::Windows::Forms::PictureBox^  black_bishop_r;
	private: System::Windows::Forms::PictureBox^  white_pawn_1;
	private: System::Windows::Forms::PictureBox^  white_pawn_2;
	private: System::Windows::Forms::PictureBox^  white_pawn_3;
	private: System::Windows::Forms::PictureBox^  white_pawn_4;
	private: System::Windows::Forms::PictureBox^  white_pawn_5;
	private: System::Windows::Forms::PictureBox^  white_pawn_6;
	private: System::Windows::Forms::PictureBox^  white_pawn_7;
	private: System::Windows::Forms::PictureBox^  white_pawn_8;
	private: System::Windows::Forms::PictureBox^  white_rook_l;
	private: System::Windows::Forms::PictureBox^  white_knight_l;
	private: System::Windows::Forms::PictureBox^  white_bishop_l;
	private: System::Windows::Forms::PictureBox^  white_queen;
	private: System::Windows::Forms::PictureBox^  white_bishop_r;













	private: System::Windows::Forms::PictureBox^  white_king;
	private: System::Windows::Forms::PictureBox^  white_knight_r;
	private: System::Windows::Forms::PictureBox^  white_rook_r;




	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Game1::typeid));
			this->black_bishop_l = (gcnew System::Windows::Forms::PictureBox());
			this->black_bishop_r = (gcnew System::Windows::Forms::PictureBox());
			this->black_horse_l = (gcnew System::Windows::Forms::PictureBox());
			this->black_rook_l = (gcnew System::Windows::Forms::PictureBox());
			this->black_knight_r = (gcnew System::Windows::Forms::PictureBox());
			this->black_queen = (gcnew System::Windows::Forms::PictureBox());
			this->black_king = (gcnew System::Windows::Forms::PictureBox());
			this->black_rook_r = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_1 = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_2 = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_3 = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_4 = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_5 = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_6 = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_7 = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawn_8 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_1 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_2 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_3 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_4 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_5 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_6 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_7 = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawn_8 = (gcnew System::Windows::Forms::PictureBox());
			this->white_rook_l = (gcnew System::Windows::Forms::PictureBox());
			this->white_knight_l = (gcnew System::Windows::Forms::PictureBox());
			this->white_bishop_l = (gcnew System::Windows::Forms::PictureBox());
			this->white_queen = (gcnew System::Windows::Forms::PictureBox());
			this->white_bishop_r = (gcnew System::Windows::Forms::PictureBox());
			this->white_king = (gcnew System::Windows::Forms::PictureBox());
			this->white_knight_r = (gcnew System::Windows::Forms::PictureBox());
			this->white_rook_r = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishop_l))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishop_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_horse_l))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rook_l))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_knight_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_queen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_king))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rook_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rook_l))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knight_l))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishop_l))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_queen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishop_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_king))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knight_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rook_r))->BeginInit();
			this->SuspendLayout();
			// 
			// black_bishop_l
			// 
			this->black_bishop_l->BackColor = System::Drawing::Color::Transparent;
			this->black_bishop_l->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_bishop_l.BackgroundImage")));
			this->black_bishop_l->Location = System::Drawing::Point(175, 35);
			this->black_bishop_l->Name = L"black_bishop_l";
			this->black_bishop_l->Size = System::Drawing::Size(70, 70);
			this->black_bishop_l->TabIndex = 0;
			this->black_bishop_l->TabStop = false;
			// 
			// black_bishop_r
			// 
			this->black_bishop_r->BackColor = System::Drawing::Color::Transparent;
			this->black_bishop_r->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_bishop_r.BackgroundImage")));
			this->black_bishop_r->Location = System::Drawing::Point(385, 35);
			this->black_bishop_r->Name = L"black_bishop_r";
			this->black_bishop_r->Size = System::Drawing::Size(70, 70);
			this->black_bishop_r->TabIndex = 1;
			this->black_bishop_r->TabStop = false;
			// 
			// black_horse_l
			// 
			this->black_horse_l->BackColor = System::Drawing::Color::Transparent;
			this->black_horse_l->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_horse_l.BackgroundImage")));
			this->black_horse_l->Location = System::Drawing::Point(105, 35);
			this->black_horse_l->Name = L"black_horse_l";
			this->black_horse_l->Size = System::Drawing::Size(70, 70);
			this->black_horse_l->TabIndex = 2;
			this->black_horse_l->TabStop = false;
			// 
			// black_rook_l
			// 
			this->black_rook_l->BackColor = System::Drawing::Color::Transparent;
			this->black_rook_l->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_rook_l.BackgroundImage")));
			this->black_rook_l->Location = System::Drawing::Point(35, 35);
			this->black_rook_l->Name = L"black_rook_l";
			this->black_rook_l->Size = System::Drawing::Size(70, 70);
			this->black_rook_l->TabIndex = 3;
			this->black_rook_l->TabStop = false;
			// 
			// black_knight_r
			// 
			this->black_knight_r->BackColor = System::Drawing::Color::Transparent;
			this->black_knight_r->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_knight_r.BackgroundImage")));
			this->black_knight_r->Location = System::Drawing::Point(455, 35);
			this->black_knight_r->Name = L"black_knight_r";
			this->black_knight_r->Size = System::Drawing::Size(70, 70);
			this->black_knight_r->TabIndex = 4;
			this->black_knight_r->TabStop = false;
			// 
			// black_queen
			// 
			this->black_queen->BackColor = System::Drawing::Color::Transparent;
			this->black_queen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_queen.BackgroundImage")));
			this->black_queen->Location = System::Drawing::Point(245, 35);
			this->black_queen->Name = L"black_queen";
			this->black_queen->Size = System::Drawing::Size(70, 70);
			this->black_queen->TabIndex = 4;
			this->black_queen->TabStop = false;
			// 
			// black_king
			// 
			this->black_king->BackColor = System::Drawing::Color::Transparent;
			this->black_king->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_king.BackgroundImage")));
			this->black_king->Location = System::Drawing::Point(315, 35);
			this->black_king->Name = L"black_king";
			this->black_king->Size = System::Drawing::Size(70, 70);
			this->black_king->TabIndex = 5;
			this->black_king->TabStop = false;
			// 
			// black_rook_r
			// 
			this->black_rook_r->BackColor = System::Drawing::Color::Transparent;
			this->black_rook_r->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_rook_r.BackgroundImage")));
			this->black_rook_r->Location = System::Drawing::Point(525, 35);
			this->black_rook_r->Name = L"black_rook_r";
			this->black_rook_r->Size = System::Drawing::Size(70, 70);
			this->black_rook_r->TabIndex = 6;
			this->black_rook_r->TabStop = false;
			// 
			// black_pawn_1
			// 
			this->black_pawn_1->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_1.BackgroundImage")));
			this->black_pawn_1->Location = System::Drawing::Point(35, 105);
			this->black_pawn_1->Name = L"black_pawn_1";
			this->black_pawn_1->Size = System::Drawing::Size(70, 70);
			this->black_pawn_1->TabIndex = 13;
			this->black_pawn_1->TabStop = false;
			// 
			// black_pawn_2
			// 
			this->black_pawn_2->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_2.BackgroundImage")));
			this->black_pawn_2->Location = System::Drawing::Point(105, 105);
			this->black_pawn_2->Name = L"black_pawn_2";
			this->black_pawn_2->Size = System::Drawing::Size(70, 70);
			this->black_pawn_2->TabIndex = 14;
			this->black_pawn_2->TabStop = false;
			// 
			// black_pawn_3
			// 
			this->black_pawn_3->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_3.BackgroundImage")));
			this->black_pawn_3->Location = System::Drawing::Point(175, 105);
			this->black_pawn_3->Name = L"black_pawn_3";
			this->black_pawn_3->Size = System::Drawing::Size(70, 70);
			this->black_pawn_3->TabIndex = 15;
			this->black_pawn_3->TabStop = false;
			// 
			// black_pawn_4
			// 
			this->black_pawn_4->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_4.BackgroundImage")));
			this->black_pawn_4->Location = System::Drawing::Point(245, 105);
			this->black_pawn_4->Name = L"black_pawn_4";
			this->black_pawn_4->Size = System::Drawing::Size(70, 70);
			this->black_pawn_4->TabIndex = 16;
			this->black_pawn_4->TabStop = false;
			// 
			// black_pawn_5
			// 
			this->black_pawn_5->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_5.BackgroundImage")));
			this->black_pawn_5->Location = System::Drawing::Point(315, 105);
			this->black_pawn_5->Name = L"black_pawn_5";
			this->black_pawn_5->Size = System::Drawing::Size(70, 70);
			this->black_pawn_5->TabIndex = 17;
			this->black_pawn_5->TabStop = false;
			// 
			// black_pawn_6
			// 
			this->black_pawn_6->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_6.BackgroundImage")));
			this->black_pawn_6->Location = System::Drawing::Point(385, 105);
			this->black_pawn_6->Name = L"black_pawn_6";
			this->black_pawn_6->Size = System::Drawing::Size(70, 70);
			this->black_pawn_6->TabIndex = 18;
			this->black_pawn_6->TabStop = false;
			// 
			// black_pawn_7
			// 
			this->black_pawn_7->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_7.BackgroundImage")));
			this->black_pawn_7->Location = System::Drawing::Point(455, 105);
			this->black_pawn_7->Name = L"black_pawn_7";
			this->black_pawn_7->Size = System::Drawing::Size(70, 70);
			this->black_pawn_7->TabIndex = 19;
			this->black_pawn_7->TabStop = false;
			// 
			// black_pawn_8
			// 
			this->black_pawn_8->BackColor = System::Drawing::Color::Transparent;
			this->black_pawn_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawn_8.BackgroundImage")));
			this->black_pawn_8->Location = System::Drawing::Point(525, 105);
			this->black_pawn_8->Name = L"black_pawn_8";
			this->black_pawn_8->Size = System::Drawing::Size(70, 70);
			this->black_pawn_8->TabIndex = 20;
			this->black_pawn_8->TabStop = false;
			// 
			// white_pawn_1
			// 
			this->white_pawn_1->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_1.BackgroundImage")));
			this->white_pawn_1->Location = System::Drawing::Point(35, 455);
			this->white_pawn_1->Name = L"white_pawn_1";
			this->white_pawn_1->Size = System::Drawing::Size(70, 70);
			this->white_pawn_1->TabIndex = 21;
			this->white_pawn_1->TabStop = false;
			// 
			// white_pawn_2
			// 
			this->white_pawn_2->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_2.BackgroundImage")));
			this->white_pawn_2->Location = System::Drawing::Point(105, 455);
			this->white_pawn_2->Name = L"white_pawn_2";
			this->white_pawn_2->Size = System::Drawing::Size(70, 70);
			this->white_pawn_2->TabIndex = 22;
			this->white_pawn_2->TabStop = false;
			// 
			// white_pawn_3
			// 
			this->white_pawn_3->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_3.BackgroundImage")));
			this->white_pawn_3->Location = System::Drawing::Point(175, 455);
			this->white_pawn_3->Name = L"white_pawn_3";
			this->white_pawn_3->Size = System::Drawing::Size(70, 70);
			this->white_pawn_3->TabIndex = 23;
			this->white_pawn_3->TabStop = false;
			// 
			// white_pawn_4
			// 
			this->white_pawn_4->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_4.BackgroundImage")));
			this->white_pawn_4->Location = System::Drawing::Point(245, 455);
			this->white_pawn_4->Name = L"white_pawn_4";
			this->white_pawn_4->Size = System::Drawing::Size(70, 70);
			this->white_pawn_4->TabIndex = 24;
			this->white_pawn_4->TabStop = false;
			// 
			// white_pawn_5
			// 
			this->white_pawn_5->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_5.BackgroundImage")));
			this->white_pawn_5->Location = System::Drawing::Point(315, 455);
			this->white_pawn_5->Name = L"white_pawn_5";
			this->white_pawn_5->Size = System::Drawing::Size(70, 70);
			this->white_pawn_5->TabIndex = 25;
			this->white_pawn_5->TabStop = false;
			// 
			// white_pawn_6
			// 
			this->white_pawn_6->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_6.BackgroundImage")));
			this->white_pawn_6->Location = System::Drawing::Point(385, 455);
			this->white_pawn_6->Name = L"white_pawn_6";
			this->white_pawn_6->Size = System::Drawing::Size(70, 70);
			this->white_pawn_6->TabIndex = 26;
			this->white_pawn_6->TabStop = false;
			// 
			// white_pawn_7
			// 
			this->white_pawn_7->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_7.BackgroundImage")));
			this->white_pawn_7->Location = System::Drawing::Point(455, 455);
			this->white_pawn_7->Name = L"white_pawn_7";
			this->white_pawn_7->Size = System::Drawing::Size(70, 70);
			this->white_pawn_7->TabIndex = 27;
			this->white_pawn_7->TabStop = false;
			// 
			// white_pawn_8
			// 
			this->white_pawn_8->BackColor = System::Drawing::Color::Transparent;
			this->white_pawn_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawn_8.BackgroundImage")));
			this->white_pawn_8->Location = System::Drawing::Point(525, 455);
			this->white_pawn_8->Name = L"white_pawn_8";
			this->white_pawn_8->Size = System::Drawing::Size(70, 70);
			this->white_pawn_8->TabIndex = 28;
			this->white_pawn_8->TabStop = false;
			// 
			// white_rook_l
			// 
			this->white_rook_l->BackColor = System::Drawing::Color::Transparent;
			this->white_rook_l->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_rook_l.BackgroundImage")));
			this->white_rook_l->Location = System::Drawing::Point(35, 525);
			this->white_rook_l->Name = L"white_rook_l";
			this->white_rook_l->Size = System::Drawing::Size(70, 70);
			this->white_rook_l->TabIndex = 29;
			this->white_rook_l->TabStop = false;
			// 
			// white_knight_l
			// 
			this->white_knight_l->BackColor = System::Drawing::Color::Transparent;
			this->white_knight_l->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_knight_l.BackgroundImage")));
			this->white_knight_l->Location = System::Drawing::Point(105, 525);
			this->white_knight_l->Name = L"white_knight_l";
			this->white_knight_l->Size = System::Drawing::Size(70, 70);
			this->white_knight_l->TabIndex = 30;
			this->white_knight_l->TabStop = false;
			// 
			// white_bishop_l
			// 
			this->white_bishop_l->BackColor = System::Drawing::Color::Transparent;
			this->white_bishop_l->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_bishop_l.BackgroundImage")));
			this->white_bishop_l->Location = System::Drawing::Point(175, 525);
			this->white_bishop_l->Name = L"white_bishop_l";
			this->white_bishop_l->Size = System::Drawing::Size(70, 70);
			this->white_bishop_l->TabIndex = 31;
			this->white_bishop_l->TabStop = false;
			// 
			// white_queen
			// 
			this->white_queen->BackColor = System::Drawing::Color::Transparent;
			this->white_queen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_queen.BackgroundImage")));
			this->white_queen->Location = System::Drawing::Point(245, 525);
			this->white_queen->Name = L"white_queen";
			this->white_queen->Size = System::Drawing::Size(70, 70);
			this->white_queen->TabIndex = 32;
			this->white_queen->TabStop = false;
			// 
			// white_bishop_r
			// 
			this->white_bishop_r->BackColor = System::Drawing::Color::Transparent;
			this->white_bishop_r->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_bishop_r.BackgroundImage")));
			this->white_bishop_r->Location = System::Drawing::Point(385, 525);
			this->white_bishop_r->Name = L"white_bishop_r";
			this->white_bishop_r->Size = System::Drawing::Size(70, 70);
			this->white_bishop_r->TabIndex = 33;
			this->white_bishop_r->TabStop = false;
			// 
			// white_king
			// 
			this->white_king->BackColor = System::Drawing::Color::Transparent;
			this->white_king->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_king.BackgroundImage")));
			this->white_king->Location = System::Drawing::Point(315, 525);
			this->white_king->Name = L"white_king";
			this->white_king->Size = System::Drawing::Size(70, 70);
			this->white_king->TabIndex = 33;
			this->white_king->TabStop = false;
			// 
			// white_knight_r
			// 
			this->white_knight_r->BackColor = System::Drawing::Color::Transparent;
			this->white_knight_r->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_knight_r.BackgroundImage")));
			this->white_knight_r->Location = System::Drawing::Point(455, 525);
			this->white_knight_r->Name = L"white_knight_r";
			this->white_knight_r->Size = System::Drawing::Size(70, 70);
			this->white_knight_r->TabIndex = 34;
			this->white_knight_r->TabStop = false;
			// 
			// white_rook_r
			// 
			this->white_rook_r->BackColor = System::Drawing::Color::Transparent;
			this->white_rook_r->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_rook_r.BackgroundImage")));
			this->white_rook_r->Location = System::Drawing::Point(525, 525);
			this->white_rook_r->Name = L"white_rook_r";
			this->white_rook_r->Size = System::Drawing::Size(70, 70);
			this->white_rook_r->TabIndex = 35;
			this->white_rook_r->TabStop = false;
			// 
			// Game1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(830, 630);
			this->Controls->Add(this->white_rook_r);
			this->Controls->Add(this->white_knight_r);
			this->Controls->Add(this->white_king);
			this->Controls->Add(this->white_bishop_r);
			this->Controls->Add(this->white_queen);
			this->Controls->Add(this->white_bishop_l);
			this->Controls->Add(this->white_knight_l);
			this->Controls->Add(this->white_rook_l);
			this->Controls->Add(this->white_pawn_8);
			this->Controls->Add(this->white_pawn_7);
			this->Controls->Add(this->white_pawn_6);
			this->Controls->Add(this->white_pawn_5);
			this->Controls->Add(this->white_pawn_4);
			this->Controls->Add(this->white_pawn_3);
			this->Controls->Add(this->white_pawn_2);
			this->Controls->Add(this->white_pawn_1);
			this->Controls->Add(this->black_pawn_8);
			this->Controls->Add(this->black_pawn_7);
			this->Controls->Add(this->black_pawn_6);
			this->Controls->Add(this->black_pawn_5);
			this->Controls->Add(this->black_pawn_4);
			this->Controls->Add(this->black_pawn_3);
			this->Controls->Add(this->black_pawn_2);
			this->Controls->Add(this->black_pawn_1);
			this->Controls->Add(this->black_rook_r);
			this->Controls->Add(this->black_king);
			this->Controls->Add(this->black_queen);
			this->Controls->Add(this->black_knight_r);
			this->Controls->Add(this->black_rook_l);
			this->Controls->Add(this->black_horse_l);
			this->Controls->Add(this->black_bishop_r);
			this->Controls->Add(this->black_bishop_l);
			this->Name = L"Game1";
			this->Text = L"Game1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishop_l))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishop_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_horse_l))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rook_l))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_knight_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_queen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_king))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rook_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawn_8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawn_8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rook_l))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knight_l))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishop_l))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_queen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishop_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_king))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knight_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rook_r))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox13_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
