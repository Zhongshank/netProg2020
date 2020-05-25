//fhcm_bx2sum0.cpp
//Gao-Wei Chang, 180505.
namespace fhcm_bx2sum0 {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class MyForm0 : public Form {
public:
  MyForm0() {
    InitializeComponent();
  };
  TextBox ^textBox1, ^textBox2;
  Button ^button1, ^button2, ^button3;
  Label^ label1;

  void InitializeComponent() {
    this->Width=250; this->Height=200;
	textBox1=gcnew TextBox;
	this->Controls->Add(textBox1);
	textBox1->Location = Point(15, 17);
    textBox1->Width=102; textBox1->Height=30;

	textBox2=gcnew TextBox;
	this->Controls->Add(textBox2);
	textBox2->Location = Point(15, 52);
	textBox2->Multiline = true;
    textBox2->Width=102; textBox2->Height=82;

	label1=gcnew Label;
	this->Controls->Add(label1);
	label1->Text ="(sum 123 456)";
	label1->Location = Point(122, 22);
    label1->Width=130; label1->Height=30;

	button1=gcnew Button;
	this->Controls->Add(button1);
	button1->Text = "Cmd ex.";
	button1->Location = Point(135, 51);
	button1->Click += gcnew EventHandler(this, &MyForm0::button1_Click);

	button2=gcnew Button;
	this->Controls->Add(button2);
	button2->Text = "Enter";
	button2->Location = Point(135, 82);
	button2->Click += gcnew EventHandler(this, &MyForm0::button2_Click);

	button3=gcnew Button;
	this->Controls->Add(button3);
	button3->Text = "Clear";
	button3->Location = Point(135, 113);
	button3->Click += gcnew EventHandler(this, &MyForm0::button3_Click);
  };

  void button1_Click(Object^ s, EventArgs^ e) {
	  textBox1->Text ="sum 123 456";
  }

  void button3_Click(Object^ s, EventArgs^ e) {
	  textBox1->Text =""; textBox2->Text ="";
	  szTotal="";
  }

  #define CMFZ_NO 3
  String^ szTotal;
  void button2_Click(Object^ s, EventArgs^ e) {
	String^ szInput = textBox1->Text;
	szTotal= szTotal+szInput+"\r\n";
	textBox2->Text = szTotal;
	array<String^>^ szArr = szInput->Split();
	if (szArr[0]!="sum") {
	  MessageBox::Show("opcode mismatch."); return; };
	int len=szArr->Length;
	if (len!=CMFZ_NO) { 
	  MessageBox::Show("cmd format error."); return; };
	int opd[CMFZ_NO-1];
	try { 
	  for (int i=0; i<(len-1); i++) opd[i] = Convert::ToInt32(szArr[i+1]); }
	catch (FormatException^ e) {
	  MessageBox::Show(e->Message); return;
	};
	double sum = opd[CMFZ_NO-3]+opd[CMFZ_NO-2];
	szTotal= szTotal+sum.ToString()+"\r\n";
	textBox2->Text = szTotal;
  };
}; }

using namespace fhcm_bx2sum0;
void main() {
  Application::Run(gcnew MyForm0);
}

  //Console::Write("起始整數cnt(至cnt+99)：");
  //int cnt = Convert::ToInt32(Console::ReadLine());

