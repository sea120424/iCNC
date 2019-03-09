#pragma once

#include < string.h >
#include "cnc\inc\cnc.h"


char serialCmd[2];

extern int cncInit(void);
//*******************************

CNC_DATA       cncData;	             //memory ; all data for CNC system.      
CNC_DATA       *cncDataPtr = &cncData;


//*******************************
int   counter = 0;

namespace iCNC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports; 

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  nrt_timer;
	private: System::Windows::Forms::Button^  button_MEM;

	private: System::Windows::Forms::Button^  button_JOG;

	private: System::Windows::Forms::Button^  button_closeCOM;

	private: System::Windows::Forms::Button^  button_initCOM;

	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::RichTextBox^  richTextBox_filePath;

	private: System::Windows::Forms::Button^  button_openFile;
	private: System::Windows::Forms::RichTextBox^  richTextBox_ncFile;
	private: System::Windows::Forms::Button^  button_CW;
	private: System::Windows::Forms::Button^  button_backward;

	private: System::Windows::Forms::Button^  button_CCW;
	private: System::Windows::Forms::Button^  button_forward;









	private: System::Windows::Forms::Button^  button_stop;

	private: System::Windows::Forms::Button^  button_start;
	private: System::Windows::Forms::Label^  label_thetaData;


	private: System::Windows::Forms::Label^  label_yData;

	private: System::Windows::Forms::Label^  label_xData;

	private: System::Windows::Forms::Label^  label_y;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label_theta;

	private: System::Windows::Forms::Label^  label_x;




	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog_openNC;
	private: System::Windows::Forms::Button^  button_sendSerial;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Timer^  rt_timer;


	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->nrt_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->button_MEM = (gcnew System::Windows::Forms::Button());
			this->button_JOG = (gcnew System::Windows::Forms::Button());
			this->button_closeCOM = (gcnew System::Windows::Forms::Button());
			this->button_initCOM = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->richTextBox_filePath = (gcnew System::Windows::Forms::RichTextBox());
			this->button_openFile = (gcnew System::Windows::Forms::Button());
			this->richTextBox_ncFile = (gcnew System::Windows::Forms::RichTextBox());
			this->button_CW = (gcnew System::Windows::Forms::Button());
			this->button_backward = (gcnew System::Windows::Forms::Button());
			this->button_CCW = (gcnew System::Windows::Forms::Button());
			this->button_forward = (gcnew System::Windows::Forms::Button());
			this->button_stop = (gcnew System::Windows::Forms::Button());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->label_thetaData = (gcnew System::Windows::Forms::Label());
			this->label_yData = (gcnew System::Windows::Forms::Label());
			this->label_xData = (gcnew System::Windows::Forms::Label());
			this->label_y = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_theta = (gcnew System::Windows::Forms::Label());
			this->label_x = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->openFileDialog_openNC = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button_sendSerial = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->rt_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// nrt_timer
			// 
			this->nrt_timer->Enabled = true;
			this->nrt_timer->Tick += gcnew System::EventHandler(this, &Form1::nrt_timer_Tick);
			// 
			// button_MEM
			// 
			this->button_MEM->Location = System::Drawing::Point(287, 416);
			this->button_MEM->Name = L"button_MEM";
			this->button_MEM->Size = System::Drawing::Size(254, 55);
			this->button_MEM->TabIndex = 37;
			this->button_MEM->Text = L"MEM";
			this->button_MEM->UseVisualStyleBackColor = true;
			this->button_MEM->Click += gcnew System::EventHandler(this, &Form1::button_MEM_Click);
			// 
			// button_JOG
			// 
			this->button_JOG->Location = System::Drawing::Point(28, 416);
			this->button_JOG->Name = L"button_JOG";
			this->button_JOG->Size = System::Drawing::Size(240, 55);
			this->button_JOG->TabIndex = 36;
			this->button_JOG->Text = L"JOG";
			this->button_JOG->UseVisualStyleBackColor = true;
			this->button_JOG->Click += gcnew System::EventHandler(this, &Form1::button_JOG_Click);
			// 
			// button_closeCOM
			// 
			this->button_closeCOM->Location = System::Drawing::Point(462, 317);
			this->button_closeCOM->Name = L"button_closeCOM";
			this->button_closeCOM->Size = System::Drawing::Size(79, 23);
			this->button_closeCOM->TabIndex = 35;
			this->button_closeCOM->Text = L"close COM";
			this->button_closeCOM->UseVisualStyleBackColor = true;
			this->button_closeCOM->Click += gcnew System::EventHandler(this, &Form1::button_closeCOM_Click);
			// 
			// button_initCOM
			// 
			this->button_initCOM->Location = System::Drawing::Point(462, 284);
			this->button_initCOM->Name = L"button_initCOM";
			this->button_initCOM->Size = System::Drawing::Size(79, 23);
			this->button_initCOM->TabIndex = 34;
			this->button_initCOM->Text = L"init COM";
			this->button_initCOM->UseVisualStyleBackColor = true;
			this->button_initCOM->Click += gcnew System::EventHandler(this, &Form1::button_initCOM_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"9600", L"115200"});
			this->comboBox2->Location = System::Drawing::Point(333, 317);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 20);
			this->comboBox2->TabIndex = 33;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(333, 284);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 20);
			this->comboBox1->TabIndex = 32;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(285, 320);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(45, 12);
			this->label8->TabIndex = 31;
			this->label8->Text = L"baudrate";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(296, 287);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 12);
			this->label7->TabIndex = 30;
			this->label7->Text = L"COM";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(287, 243);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(254, 23);
			this->progressBar1->TabIndex = 29;
			// 
			// richTextBox_filePath
			// 
			this->richTextBox_filePath->Location = System::Drawing::Point(378, 201);
			this->richTextBox_filePath->Name = L"richTextBox_filePath";
			this->richTextBox_filePath->Size = System::Drawing::Size(163, 22);
			this->richTextBox_filePath->TabIndex = 28;
			this->richTextBox_filePath->Text = L"";
			// 
			// button_openFile
			// 
			this->button_openFile->Location = System::Drawing::Point(287, 201);
			this->button_openFile->Name = L"button_openFile";
			this->button_openFile->Size = System::Drawing::Size(75, 23);
			this->button_openFile->TabIndex = 27;
			this->button_openFile->Text = L"load";
			this->button_openFile->UseVisualStyleBackColor = true;
			this->button_openFile->Click += gcnew System::EventHandler(this, &Form1::button_openFile_Click);
			this->button_openFile->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_openFile_MouseDown);
			this->button_openFile->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_openFile_MouseUp);
			// 
			// richTextBox_ncFile
			// 
			this->richTextBox_ncFile->Location = System::Drawing::Point(287, 37);
			this->richTextBox_ncFile->Name = L"richTextBox_ncFile";
			this->richTextBox_ncFile->Size = System::Drawing::Size(254, 158);
			this->richTextBox_ncFile->TabIndex = 26;
			this->richTextBox_ncFile->Text = L"";
			// 
			// button_CW
			// 
			this->button_CW->Location = System::Drawing::Point(180, 317);
			this->button_CW->Name = L"button_CW";
			this->button_CW->Size = System::Drawing::Size(75, 45);
			this->button_CW->TabIndex = 25;
			this->button_CW->Text = L"CW";
			this->button_CW->UseVisualStyleBackColor = true;
			this->button_CW->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_CW_MouseDown);
			this->button_CW->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_CW_MouseUp);
			// 
			// button_backward
			// 
			this->button_backward->Location = System::Drawing::Point(103, 360);
			this->button_backward->Name = L"button_backward";
			this->button_backward->Size = System::Drawing::Size(75, 50);
			this->button_backward->TabIndex = 24;
			this->button_backward->Text = L"backward";
			this->button_backward->UseVisualStyleBackColor = true;
			this->button_backward->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_backward_MouseDown);
			this->button_backward->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_backward_MouseUp);
			// 
			// button_CCW
			// 
			this->button_CCW->Location = System::Drawing::Point(28, 317);
			this->button_CCW->Name = L"button_CCW";
			this->button_CCW->Size = System::Drawing::Size(75, 45);
			this->button_CCW->TabIndex = 23;
			this->button_CCW->Text = L"CCW";
			this->button_CCW->UseVisualStyleBackColor = true;
			this->button_CCW->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_CCW_MouseDown);
			this->button_CCW->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_CCW_MouseUp);
			// 
			// button_forward
			// 
			this->button_forward->Location = System::Drawing::Point(103, 274);
			this->button_forward->Name = L"button_forward";
			this->button_forward->Size = System::Drawing::Size(75, 42);
			this->button_forward->TabIndex = 22;
			this->button_forward->Text = L"forward";
			this->button_forward->UseVisualStyleBackColor = true;
			this->button_forward->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_forward_MouseDown);
			this->button_forward->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_forward_MouseUp);
			// 
			// button_stop
			// 
			this->button_stop->Location = System::Drawing::Point(153, 201);
			this->button_stop->Name = L"button_stop";
			this->button_stop->Size = System::Drawing::Size(115, 54);
			this->button_stop->TabIndex = 21;
			this->button_stop->Text = L"STOP";
			this->button_stop->UseVisualStyleBackColor = true;
			this->button_stop->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_stop_MouseDown);
			this->button_stop->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_stop_MouseUp);
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(28, 201);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(105, 54);
			this->button_start->TabIndex = 20;
			this->button_start->Text = L"START";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Form1::button_start_Click);
			this->button_start->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_start_MouseDown);
			this->button_start->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button_start_MouseUp);
			// 
			// label_thetaData
			// 
			this->label_thetaData->AutoSize = true;
			this->label_thetaData->BackColor = System::Drawing::Color::Black;
			this->label_thetaData->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_thetaData->ForeColor = System::Drawing::Color::White;
			this->label_thetaData->Location = System::Drawing::Point(70, 108);
			this->label_thetaData->Name = L"label_thetaData";
			this->label_thetaData->Size = System::Drawing::Size(123, 30);
			this->label_thetaData->TabIndex = 5;
			this->label_thetaData->Text = L"0                ";
			// 
			// label_yData
			// 
			this->label_yData->AutoSize = true;
			this->label_yData->BackColor = System::Drawing::Color::Black;
			this->label_yData->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_yData->ForeColor = System::Drawing::Color::White;
			this->label_yData->Location = System::Drawing::Point(70, 67);
			this->label_yData->Name = L"label_yData";
			this->label_yData->Size = System::Drawing::Size(123, 30);
			this->label_yData->TabIndex = 4;
			this->label_yData->Text = L"0                ";
			// 
			// label_xData
			// 
			this->label_xData->AutoSize = true;
			this->label_xData->BackColor = System::Drawing::Color::Black;
			this->label_xData->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_xData->ForeColor = System::Drawing::Color::White;
			this->label_xData->Location = System::Drawing::Point(70, 22);
			this->label_xData->Name = L"label_xData";
			this->label_xData->Size = System::Drawing::Size(123, 30);
			this->label_xData->TabIndex = 3;
			this->label_xData->Text = L"0                ";
			// 
			// label_y
			// 
			this->label_y->AutoSize = true;
			this->label_y->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_y->Location = System::Drawing::Point(7, 67);
			this->label_y->Name = L"label_y";
			this->label_y->Size = System::Drawing::Size(27, 30);
			this->label_y->TabIndex = 2;
			this->label_y->Text = L"Y";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_thetaData);
			this->groupBox1->Controls->Add(this->label_yData);
			this->groupBox1->Controls->Add(this->label_xData);
			this->groupBox1->Controls->Add(this->label_y);
			this->groupBox1->Controls->Add(this->label_theta);
			this->groupBox1->Controls->Add(this->label_x);
			this->groupBox1->Location = System::Drawing::Point(28, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(240, 170);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// label_theta
			// 
			this->label_theta->AutoSize = true;
			this->label_theta->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_theta->Location = System::Drawing::Point(7, 108);
			this->label_theta->Name = L"label_theta";
			this->label_theta->Size = System::Drawing::Size(26, 30);
			this->label_theta->TabIndex = 1;
			this->label_theta->Text = L"T";
			// 
			// label_x
			// 
			this->label_x->AutoSize = true;
			this->label_x->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_x->Location = System::Drawing::Point(7, 22);
			this->label_x->Name = L"label_x";
			this->label_x->Size = System::Drawing::Size(28, 30);
			this->label_x->TabIndex = 0;
			this->label_x->Text = L"X";
			// 
			// openFileDialog_openNC
			// 
			this->openFileDialog_openNC->FileName = L"openFileDialog1";
			// 
			// button_sendSerial
			// 
			this->button_sendSerial->Location = System::Drawing::Point(462, 379);
			this->button_sendSerial->Name = L"button_sendSerial";
			this->button_sendSerial->Size = System::Drawing::Size(75, 23);
			this->button_sendSerial->TabIndex = 38;
			this->button_sendSerial->Text = L"send";
			this->button_sendSerial->UseVisualStyleBackColor = true;
			this->button_sendSerial->Click += gcnew System::EventHandler(this, &Form1::button_sendSerial_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(294, 351);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 12);
			this->label9->TabIndex = 39;
			this->label9->Text = L"read";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(294, 383);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(28, 12);
			this->label10->TabIndex = 40;
			this->label10->Text = L"write";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(333, 348);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 22);
			this->textBox1->TabIndex = 41;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(333, 380);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 22);
			this->textBox2->TabIndex = 42;
			// 
			// rt_timer
			// 
			this->rt_timer->Tick += gcnew System::EventHandler(this, &Form1::rt_timer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(600, 500);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button_sendSerial);
			this->Controls->Add(this->button_MEM);
			this->Controls->Add(this->button_JOG);
			this->Controls->Add(this->button_closeCOM);
			this->Controls->Add(this->button_initCOM);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->richTextBox_filePath);
			this->Controls->Add(this->button_openFile);
			this->Controls->Add(this->richTextBox_ncFile);
			this->Controls->Add(this->button_CW);
			this->Controls->Add(this->button_backward);
			this->Controls->Add(this->button_CCW);
			this->Controls->Add(this->button_forward);
			this->Controls->Add(this->button_stop);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void nrt_timer_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {  // timer for non-real-time call
                 nrtMain();


				 cncDataPtr->linkData.linkToMmiData.counter++;
				 if(cncDataPtr->linkData.linkToMmiData.counter > 1000)
				 {
					cncDataPtr->linkData.linkToMmiData.counter = 0;
				 }

				 this->label_xData->Text = cncDataPtr-> mmiData.CarCoordinate[0].ToString("0.00");
				 this->label_yData->Text = cncDataPtr-> mmiData.CarCoordinate[1].ToString("0.00");
				 this->label_thetaData->Text = cncDataPtr-> mmiData.CarCoordinate[2].ToString("0.00");

				 //miss label counter
				 //this->label_counter->Text = cncDataPtr->linkData.linkToMmiData.counter.ToString("0.00");
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {  // init for CNC and FORM
				 cncInit();
				// Getting port names for car control
				array<Object^>^ objectArray = SerialPort::GetPortNames();
				// add string array to combobox
				this->comboBox1->Items->AddRange( objectArray ); 
				cncDataPtr->mmiData.opMode = MEM_MODE;
			 }
	private: System::Void button_openFile_Click(System::Object^  sender, System::EventArgs^  e) 
			 
			{			
				//load NC FILE
				openFileDialog_openNC->InitialDirectory = " ";
				openFileDialog_openNC->Filter = "文字檔(*.txt)|*.txt|所有檔案(*.*)|*.*";
				openFileDialog_openNC->FilterIndex = 1;
				openFileDialog_openNC->DefaultExt = "*.txt";
				openFileDialog_openNC->FileName = "";
				openFileDialog_openNC->RestoreDirectory = true;
			if(openFileDialog_openNC->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				richTextBox_filePath->Text = openFileDialog_openNC->FileName;
				richTextBox_ncFile->LoadFile(openFileDialog_openNC->FileName , RichTextBoxStreamType::PlainText);

				strcpy(cncDataPtr->mmiData.ncFileName , (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(openFileDialog_openNC->FileName));
				cncDataPtr->mmiData.ncFileValid = true;
			}
			else
			{
				MessageBox::Show("please choose a right model" ," ERROR! ", MessageBoxButtons::OK , MessageBoxIcon::Warning);
			}
		
			}
private: System::Void button_initCOM_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //init COM
			 this->textBox1->Text = String::Empty;
			 if(this->comboBox1->Text == String::Empty || this->comboBox2->Text == String::Empty)
			 {
				 this->textBox1->Text = "Please Select Port Settings";
			 }
			 else 
			 {
				 try
				 {
					 // make sure port isn't open	
					 if(!this->serialPort1->IsOpen)
					 {
						 this->serialPort1->PortName = this->comboBox1->Text;

						 this->serialPort1->BaudRate = Int32::Parse(this->comboBox2->Text);

						 this->textBox2->Text = "Enter Message Here";

						 //open serial port 
						 this->serialPort1->Open();
						 this->progressBar1->Value = 100;
					 }
					 else
						 this->textBox1->Text = "Port isn't opened";
				 }
				 catch(UnauthorizedAccessException^)
				 {
					 this->textBox1->Text = "UnauthorizedAccess";
				 }
			 }
		 }
private: System::Void button_closeCOM_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //close serialPort
			 this->serialPort1->Close();
			 // update progress bar
			 this->progressBar1->Value = 0;
			 // Enable the init button
			 this->button_initCOM->Enabled = true;
			 //close COM
		 }
private: System::Void button_sendSerial_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 // add sender name
			 String^ name = this->serialPort1->PortName;
			 // grab text and store in send buffer
			 String^ message = this->textBox2->Text;
			 // write to serial
			 if(this->serialPort1->IsOpen)
			 {
				 this->serialPort1->Write(message);
			 }
			 else
			 {
				 this->textBox1->Text="Port Not Opened";
			 }
		 }
private: System::Void button_forward_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_forward->BackColor = Color::Red;
			 button_CW->BackColor = Color::Transparent;
			 button_CW->Enabled = false;
			 button_backward->BackColor = Color::Transparent;
			 button_backward->Enabled = false;
			 button_CCW->BackColor = Color::Transparent;
			 button_CCW->Enabled = false;
			 serialCmd[0] = 50;
			 serialCmd[1] = '!';

		 }
private: System::Void button_forward_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_forward->BackColor = Color::Transparent;
			 button_CW->Enabled = true;
			 button_backward->Enabled = true;
			 button_CCW->Enabled = true;
			 serialCmd[0] = 120;
			 serialCmd[1] = '!';

		 }
private: System::Void button_CCW_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 button_CCW->BackColor = Color::Red;
			 button_CW->BackColor = Color::Transparent;
			 button_CW->Enabled = false;
			 button_backward->BackColor = Color::Transparent;
			 button_backward->Enabled = false;
			 button_forward->BackColor = Color::Transparent;
			 button_forward->Enabled = false;
			 serialCmd[0] = 118;
			 serialCmd[1] = '!';
		 }
private: System::Void button_CCW_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_CCW->BackColor = Color::Transparent;
			 button_CW->Enabled = true;
			 button_backward->Enabled = true;
			 button_forward->Enabled = true;
			 serialCmd[0] = 120;
			 serialCmd[1] = '!';

		 }
private: System::Void button_CW_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_CW->BackColor = Color::Red;
			 button_CCW->BackColor = Color::Transparent;
			 button_CCW->Enabled = false;
			 button_backward->BackColor = Color::Transparent;
			 button_backward->Enabled = false;
			 button_forward->BackColor = Color::Transparent;
			 button_forward->Enabled = false;
			 serialCmd[0] = 119;
			 serialCmd[1] = '!';
		 }
private: System::Void button_CW_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_CW->BackColor = Color::Transparent;
			 button_CCW->Enabled = true;
			 button_backward->Enabled = true;
			 button_forward->Enabled = true;
			 serialCmd[0] = 120;
			 serialCmd[1] = '!';
		 }
private: System::Void button_backward_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_backward->BackColor = Color::Red;
			 button_CCW->BackColor = Color::Transparent;
			 button_CCW->Enabled = false;
			 button_CW->BackColor = Color::Transparent;
			 button_CW->Enabled = false;
			 button_forward->BackColor = Color::Transparent;
			 button_forward->Enabled = false;
			 serialCmd[0] = 71;
			 serialCmd[1] = '!';
		 }
private: System::Void button_backward_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_backward->BackColor = Color::Transparent;
			 button_CCW->Enabled = true;
			 button_CW->Enabled = true;
			 button_forward->Enabled = true;
			 serialCmd[0] = 120;
			 serialCmd[1] = '!';

		 }
		 //*********************************************************************************//
		 //button_openFile
		 //*********************************************************************************//
private: System::Void button_openFile_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_openFile->BackColor = Color::Red;
			 button_backward->Enabled = false;
			 button_CCW->Enabled = false;
			 button_CW->Enabled = false;
			 button_forward->Enabled = false;
			 button_stop->Enabled = false;
			 button_start->Enabled = false;
			 button_JOG->Enabled = false;
			 button_MEM->Enabled = false;
			 button_initCOM->Enabled = false;
			 button_closeCOM->Enabled = false;
			 button_sendSerial->Enabled = false;
		 }
private: System::Void button_openFile_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_openFile->BackColor = Color::Transparent;
			 button_backward->Enabled = true;
			 button_CCW->Enabled = true;
			 button_CW->Enabled = true;
			 button_forward->Enabled = true;
			 button_stop->Enabled = true;
			 button_start->Enabled = true;
			 button_JOG->Enabled = true;
			 button_MEM->Enabled = true;
			 button_initCOM->Enabled = true;
			 button_closeCOM->Enabled = true;
			 button_sendSerial->Enabled = true;
		 }
		 //*********************************************************************************//
		 //
		 //*********************************************************************************//
private: System::Void button_start_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_start->BackColor = Color::Red;
			 button_stop->BackColor = Color::Transparent;
			 button_stop->Enabled = false;
		 }
private: System::Void button_start_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_start->BackColor = Color::Transparent;
			 button_stop->Enabled = true;
		 }
private: System::Void button_stop_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_stop->BackColor = Color::Red;
			 button_start->BackColor = Color::Transparent;
			 button_start->Enabled = false;
		 }
private: System::Void button_stop_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 button_stop->BackColor = Color::Transparent;
			 button_start->Enabled = true;
		 }
private: System::Void button_start_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 cncDataPtr-> mmiData.START = true;
		 }
private: System::Void button_MEM_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  cncDataPtr-> mmiData.opMode = MEM_MODE;

			  button_MEM-> BackColor = Color ::Red;
			  button_JOG-> BackColor = Color ::Blue;
		 }
private: System::Void button_JOG_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  cncDataPtr-> mmiData.opMode = JOG_MODE;

			  button_MEM-> BackColor = Color ::Blue;
			  button_JOG-> BackColor = Color ::Red;
		 }
private: System::Void rt_timer_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 rtMain();


			 if(cncDataPtr->linkData.intpToLinkData.serialCmdVaild == true)
			 {
				 //add sender name
				 String^name = this->serialPort1->PortName;
				 //grab text and store in send buffer
				 String^message = gcnew String(cncDataPtr->linkData.intpToLinkData.serialCmd , 0, 2);


				 if(this->serialPort1->IsOpen)
				 {
					this->serialPort1-> Write(message);
					this->textBox1->Text=message;
				 }
				 else
				 {
					this->textBox1->Text= "Port Not Opened ";
				 }
			 }
			
			 
		 }
};
}

