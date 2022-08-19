#pragma once

#ifndef MAINFORM_H
#define MAINFORM_H
#endif

#include <stdlib.h>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>

// inspectorgui namespace
namespace injectorgui {

	// namespaces
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// class definition
	public ref class mainform : public System::Windows::Forms::Form
	{
		// public methods
		public:
			// mainform initializer
			mainform(void)
			{
				// run initializer
				InitializeComponent();
			}

		// protected methods
		protected:
			// mainform components checker
			~mainform()
			{
				// check if components exist
				if (components)
					// delete if yes
					delete components;
			}

		// all components
		private: System::Windows::Forms::Label^ dllpathlabel;
		private: System::Windows::Forms::RichTextBox^ dllpathbox;
		private: System::Windows::Forms::Button^ browsebutton;
		private: System::Windows::Forms::Label^ proclabel;
		private: System::Windows::Forms::RichTextBox^ procbox;
		private: System::Windows::Forms::Button^ listprocbutton;
		private: System::Windows::Forms::Button^ aboutbutton;
		private: System::Windows::Forms::Button^ injectbutton;

		// components container
		private: System::ComponentModel::Container ^components;

	// winform design region
	#pragma region Windows Form Designer generated code

			// initialize components function
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainform::typeid));
				this->dllpathlabel = (gcnew System::Windows::Forms::Label());
				this->dllpathbox = (gcnew System::Windows::Forms::RichTextBox());
				this->browsebutton = (gcnew System::Windows::Forms::Button());
				this->proclabel = (gcnew System::Windows::Forms::Label());
				this->procbox = (gcnew System::Windows::Forms::RichTextBox());
				this->listprocbutton = (gcnew System::Windows::Forms::Button());
				this->aboutbutton = (gcnew System::Windows::Forms::Button());
				this->injectbutton = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// dllpathlabel
				// 
				this->dllpathlabel->AutoSize = true;
				this->dllpathlabel->Location = System::Drawing::Point(13, 13);
				this->dllpathlabel->Name = L"dllpathlabel";
				this->dllpathlabel->Size = System::Drawing::Size(83, 13);
				this->dllpathlabel->TabIndex = 0;
				this->dllpathlabel->Text = L"Path to DLL File";
				// 
				// dllpathbox
				// 
				this->dllpathbox->Location = System::Drawing::Point(16, 30);
				this->dllpathbox->Name = L"dllpathbox";
				this->dllpathbox->Size = System::Drawing::Size(289, 20);
				this->dllpathbox->TabIndex = 1;
				this->dllpathbox->Text = L"";
				this->dllpathbox->TextChanged += gcnew System::EventHandler(this, &mainform::textbox_TextChanged);
				// 
				// browsebutton
				// 
				this->browsebutton->Location = System::Drawing::Point(311, 30);
				this->browsebutton->Name = L"browsebutton";
				this->browsebutton->Size = System::Drawing::Size(86, 20);
				this->browsebutton->TabIndex = 2;
				this->browsebutton->Text = L"Browse";
				this->browsebutton->UseVisualStyleBackColor = true;
				this->browsebutton->Click += gcnew System::EventHandler(this, &mainform::browsebutton_Click);
				// 
				// proclabel
				// 
				this->proclabel->AutoSize = true;
				this->proclabel->Location = System::Drawing::Point(13, 70);
				this->proclabel->Name = L"proclabel";
				this->proclabel->Size = System::Drawing::Size(100, 13);
				this->proclabel->TabIndex = 3;
				this->proclabel->Text = L"Process Name or Id";
				// 
				// procbox
				// 
				this->procbox->Location = System::Drawing::Point(16, 86);
				this->procbox->Name = L"procbox";
				this->procbox->Size = System::Drawing::Size(289, 20);
				this->procbox->TabIndex = 4;
				this->procbox->Text = L"";
				this->procbox->TextChanged += gcnew System::EventHandler(this, &mainform::textbox_TextChanged);
				// 
				// listprocbutton
				// 
				this->listprocbutton->Location = System::Drawing::Point(311, 85);
				this->listprocbutton->Name = L"listprocbutton";
				this->listprocbutton->Size = System::Drawing::Size(86, 20);
				this->listprocbutton->TabIndex = 5;
				this->listprocbutton->Text = L"View All";
				this->listprocbutton->UseVisualStyleBackColor = true;
				this->listprocbutton->Click += gcnew System::EventHandler(this, &mainform::listprocbutton_Click);
				// 
				// aboutbutton
				// 
				this->aboutbutton->Location = System::Drawing::Point(429, 20);
				this->aboutbutton->Name = L"aboutbutton";
				this->aboutbutton->Size = System::Drawing::Size(202, 40);
				this->aboutbutton->TabIndex = 6;
				this->aboutbutton->Text = L"About";
				this->aboutbutton->UseVisualStyleBackColor = true;
				this->aboutbutton->Click += gcnew System::EventHandler(this, &mainform::aboutbutton_Click);
				// 
				// injectbutton
				// 
				this->injectbutton->Enabled = false;
				this->injectbutton->Location = System::Drawing::Point(429, 66);
				this->injectbutton->Name = L"injectbutton";
				this->injectbutton->Size = System::Drawing::Size(202, 40);
				this->injectbutton->TabIndex = 7;
				this->injectbutton->Text = L"Inject";
				this->injectbutton->UseVisualStyleBackColor = true;
				this->injectbutton->Click += gcnew System::EventHandler(this, &mainform::injectbutton_Click);
				// 
				// mainform
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(639, 118);
				this->Controls->Add(this->injectbutton);
				this->Controls->Add(this->aboutbutton);
				this->Controls->Add(this->listprocbutton);
				this->Controls->Add(this->procbox);
				this->Controls->Add(this->proclabel);
				this->Controls->Add(this->browsebutton);
				this->Controls->Add(this->dllpathbox);
				this->Controls->Add(this->dllpathlabel);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				this->Name = L"mainform";
				this->Text = L"DLL Injector (1.0.0)";
				this->ResumeLayout(false);
				this->PerformLayout();

			}

	// end that region
	#pragma endregion

	// functions region
	#pragma region Functions

		// textbox changed function
		private: System::Void textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			// check if empty
			if (this->procbox->Text != "" && this->dllpathbox->Text != "" && this->procbox->Text != " " && this->dllpathbox->Text != "")
				// enable inject button
				this->injectbutton->Enabled = true;
			// if yes
			else
				// disable inject button
				this->injectbutton->Enabled = false;
		}

		// browse button click function
		private: System::Void browsebutton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// create file browser
			OpenFileDialog dialog;
			dialog.InitialDirectory = "C:\\";
			dialog.Filter = "dll files (*.dll)|*.dll|All Files (*.*)|*.*";
			dialog.FilterIndex = 1;
			dialog.RestoreDirectory = true;

			// when file open button clicked
			if (dialog.ShowDialog() == System::Windows::Forms::DialogResult::OK)
				// set path
				this->dllpathbox->Text = dialog.FileName;
		}

		// list processes button click function
		private: System::Void listprocbutton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// create file & open
			system("powershell -Command tasklist >> tasks.txt");
			system("start notepad tasks.txt");

			// sleep
			Sleep(1000);

			// delete file
			system("powershell -Command rm tasks.txt");
		}

		// about button click function
		private: System::Void aboutbutton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// details
			String^ message = "This is a DLL injection program developed by Yochran.\nWould you like to visit the GitHub page?";
			String^ caption = "About this Program";
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			MessageBoxIcon icon = MessageBoxIcon::Information;

			// create dialog result
			System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(message, caption, buttons, icon);

			// check click
			if (result == System::Windows::Forms::DialogResult::Yes)
				system("start https://github.com/the-antibody/dll-injector");
		}

		// inject button click function
		private: System::Void injectbutton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// create marshal context converter
			msclr::interop::marshal_context context;

			// get dll path and process
			std::string dll_path = context.marshal_as<std::string>(this->dllpathbox->Text);
			std::string process = context.marshal_as<std::string>(this->procbox->Text);

			// create command
			std::string command = "inject " + dll_path + " " + process;

			// message box details
			String^ message = "Attempting to inject DLL...";
			String^ caption = "Injector";
			MessageBoxButtons buttons = MessageBoxButtons::OK;
			MessageBoxIcon icon = MessageBoxIcon::Information;

			// create message box
			System::Windows::Forms::MessageBox::Show(message, caption, buttons, icon);

			// run command
			system(command.c_str());
		}

	// end that region
	#pragma endregion

	};
}
