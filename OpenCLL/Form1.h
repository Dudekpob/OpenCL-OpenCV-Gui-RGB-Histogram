#pragma once
#include  <iostream>
#include  <opencv2/highgui.hpp>
#include  <opencv2/imgcodecs.hpp>
#include  <opencv2/imgproc.hpp>
#include  <CL/cl.hpp>
#include  "opencl.hpp"
//#include  "kernel.hpp"
#include <codecvt>
#include <locale>
#include "ocl_macros.h"
#include "bmp_image.h"
#include <random>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#define USE_HOST_MEMORY
#define THREAD_BLOCK_SIZE 64





namespace CppCLRWinformsProjekt {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	/// 
	/// 
	/// 
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ChoseFilePath;
	private: System::Windows::Forms::PictureBox^ LoadedBitmap;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;








	private: System::Windows::Forms::Button^ LowPassFilter;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;




	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;





	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ChoseFilePath = (gcnew System::Windows::Forms::Button());
			this->LoadedBitmap = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->LowPassFilter = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadedBitmap))->BeginInit();
			this->SuspendLayout();
			// 
			// ChoseFilePath
			// 
			this->ChoseFilePath->Location = System::Drawing::Point(217, 529);
			this->ChoseFilePath->Name = L"ChoseFilePath";
			this->ChoseFilePath->Size = System::Drawing::Size(164, 48);
			this->ChoseFilePath->TabIndex = 0;
			this->ChoseFilePath->Text = L"Choose BMP  File Path";
			this->ChoseFilePath->UseVisualStyleBackColor = true;
			this->ChoseFilePath->UseWaitCursor = true;
			this->ChoseFilePath->Click += gcnew System::EventHandler(this, &Form1::ChoseFilePath_Click);
			// 
			// LoadedBitmap
			// 
			this->LoadedBitmap->Location = System::Drawing::Point(12, 12);
			this->LoadedBitmap->Name = L"LoadedBitmap";
			this->LoadedBitmap->Size = System::Drawing::Size(860, 501);
			this->LoadedBitmap->TabIndex = 1;
			this->LoadedBitmap->TabStop = false;
			this->LoadedBitmap->UseWaitCursor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// LowPassFilter
			// 
			this->LowPassFilter->Location = System::Drawing::Point(903, 437);
			this->LowPassFilter->Name = L"LowPassFilter";
			this->LowPassFilter->Size = System::Drawing::Size(197, 48);
			this->LowPassFilter->TabIndex = 10;
			this->LowPassFilter->Text = L"Gauss Low Pass Filter";
			this->LowPassFilter->UseVisualStyleBackColor = true;
			this->LowPassFilter->UseWaitCursor = true;
			this->LowPassFilter->Click += gcnew System::EventHandler(this, &Form1::LowPassFilter_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(387, 529);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 48);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Save Bitmap";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->UseWaitCursor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(941, 488);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(129, 25);
			this->label13->TabIndex = 17;
			this->label13->Text = L"Filter Mask";
			this->label13->UseWaitCursor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(968, 516);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(37, 23);
			this->button2->TabIndex = 18;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->UseWaitCursor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1011, 516);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(37, 23);
			this->button3->TabIndex = 19;
			this->button3->Text = L"-";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->UseWaitCursor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1112, 644);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->LowPassFilter);
			this->Controls->Add(this->LoadedBitmap);
			this->Controls->Add(this->ChoseFilePath);
			this->Name = L"Form1";
			this->Text = L"OpenCL";
			this->UseWaitCursor = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadedBitmap))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void MarshalString(System::String^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void MarshalString(System::String^ s, std::wstring & os) {
			using namespace Runtime::InteropServices;
			const wchar_t* chars =
				(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}


		int imagew = 1;
		int *ArrR;
		int *ArrB;
		int  *ArrG;

	private: System::Void ChoseFilePath_Click(System::Object^ sender, System::EventArgs^ e) {
		//	


	



			
		openFileDialog1->ShowDialog();																			   //Otwieranie   i zapisywanie pliku 
		System::String^ filepath_S = openFileDialog1->FileName;													   //Otwieranie   i zapisywanie pliku 
		LoadedBitmap->Image = LoadedBitmap->Image->FromFile(openFileDialog1->FileName);							   //Otwieranie   i zapisywanie pliku 
		std::string filepath = "";																				   //Otwieranie   i zapisywanie pliku 
		MarshalString(filepath_S, filepath);																	   //Otwieranie   i zapisywanie pliku 
		cv::Mat src = cv::imread(samples::findFile(filepath), IMREAD_COLOR);									   //Otwieranie   i zapisywanie pliku 
		if (src.empty())																						   //Otwieranie   i zapisywanie pliku 
		{																										   //Otwieranie   i zapisywanie pliku 
																												   //Otwieranie   i zapisywanie pliku 
		}



const char* histogram_kernel =
"#define BIN_SIZE 256                                                                  \n"
"#pragma OPENCL EXTENSION cl_khr_byte_addressable_store : enable                       \n"
"__kernel                                                                              \n"
"void histogram_kernel(__global const uint* data,                                      \n"
"                  __local uchar* sharedArray,                                         \n"
"                  __global uint* binResultR,                                          \n"
"                  __global uint* binResultG,                                          \n"
"                  __global uint* binResultB)                                          \n"
"{                                                                                     \n"
"    size_t localId = get_local_id(0);                                                 \n"
"    size_t globalId = get_global_id(0);                                               \n"
"    size_t groupId = get_group_id(0);                                                 \n"
"    size_t groupSize = get_local_size(0);                                             \n"
"     __local uchar* sharedArrayR = sharedArray;                                       \n"
"     __local uchar* sharedArrayG = sharedArray + groupSize * BIN_SIZE;                \n"
"     __local uchar* sharedArrayB = sharedArray + 2 * groupSize * BIN_SIZE;            \n"
"                                                                                      \n"
"    /* initialize shared array to zero */                                             \n"
"    for(int i = 0; i < BIN_SIZE; ++i)                                                 \n"
"    {                                                                                 \n"
"        sharedArrayR[localId * BIN_SIZE + i] = 0;                                     \n"
"        sharedArrayG[localId * BIN_SIZE + i] = 0;                                     \n"
"        sharedArrayB[localId * BIN_SIZE + i] = 0;                                     \n"
"    }                                                                                 \n"
"                                                                                      \n"
"    barrier(CLK_LOCAL_MEM_FENCE);                                                     \n"
"                                                                                      \n"
"    /* calculate thread-histograms */                                                 \n"
"    for(int i = 0; i < BIN_SIZE; ++i)                                                 \n"
"    {                                                                                 \n"
"        uint value = data[globalId * BIN_SIZE + i];                                   \n"
"        uint valueR = value & 0xFF;                                                   \n"
"        uint valueG = (value & 0xFF00) >> 8;                                          \n"
"        uint valueB = (value & 0xFF0000) >> 16;                                       \n"
"        sharedArrayR[localId * BIN_SIZE + valueR]++;                                  \n"
"        sharedArrayG[localId * BIN_SIZE + valueG]++;                                  \n"
"        sharedArrayB[localId * BIN_SIZE + valueB]++;                                  \n"
"    }                                                                                 \n"
"                                                                                      \n"
"    barrier(CLK_LOCAL_MEM_FENCE);                                                     \n"
"                                                                                      \n"
"    /* merge all thread-histograms into block-histogram */                            \n"
"    for(int i = 0; i < BIN_SIZE / groupSize; ++i)                                     \n"
"    {                                                                                 \n"
"        uint binCountR = 0;                                                           \n"
"        uint binCountG = 0;                                                           \n"
"        uint binCountB = 0;                                                           \n"
"        for(int j = 0; j < groupSize; ++j)                                            \n"
"        {                                                                             \n"
"            binCountR += sharedArrayR[j * BIN_SIZE + i * groupSize + localId];        \n"
"            binCountG += sharedArrayG[j * BIN_SIZE + i * groupSize + localId];        \n"
"            binCountB += sharedArrayB[j * BIN_SIZE + i * groupSize + localId];        \n"
"        }                                                                             \n"
"                                                                                      \n"
"        binResultR[groupId * BIN_SIZE + i * groupSize + localId] = binCountR;         \n"
"        binResultG[groupId * BIN_SIZE + i * groupSize + localId] = binCountG;         \n"
"        binResultB[groupId * BIN_SIZE + i * groupSize + localId] = binCountB;         \n"
"    }                                                                                 \n"
"}                                                                                     \n"
"                                                                                      \n";

		cl_int status = 0;
		cl_int binSize = 256;
		cl_int groupSize = 16;
		cl_int subHistgCnt;
		cl_device_type dType = CL_DEVICE_TYPE_GPU;
		cl_platform_id platform = NULL;
		cl_device_id   device;
		cl_context     context;
		cl_command_queue commandQueue;
		cl_mem         imageBuffer;
		cl_mem     intermediateHistR, intermediateHistG, intermediateHistB; /*Intermediate Image Histogram buffer*/
		cl_uint* midDeviceBinR, * midDeviceBinG, * midDeviceBinB;
		cl_uint* deviceBinR, * deviceBinG, * deviceBinB;
		//Read a BMP Image
	    Imagee *image;
		std::string filename = filepath;
		ReadBMPImage(filename, &image);

		subHistgCnt = (image->width * image->height) / (binSize * groupSize);
		midDeviceBinR = (cl_uint*)malloc(binSize * subHistgCnt * sizeof(cl_uint));
		midDeviceBinG = (cl_uint*)malloc(binSize * subHistgCnt * sizeof(cl_uint));
		midDeviceBinB = (cl_uint*)malloc(binSize * subHistgCnt * sizeof(cl_uint));
		deviceBinR = (cl_uint*)malloc(binSize * sizeof(cl_uint));
		deviceBinG = (cl_uint*)malloc(binSize * sizeof(cl_uint));
		deviceBinB = (cl_uint*)malloc(binSize * sizeof(cl_uint));

		status = clGetPlatformIDs(1, &platform, NULL);
		LOG_OCL_ERROR(status, "clGetPlatformIDs Failed.");

		//Get the first available device 
		status = clGetDeviceIDs(platform, dType, 1, &device, NULL);
		LOG_OCL_ERROR(status, "clGetDeviceIDs Failed.");

		//Create an execution context for the selected platform and device. 
		cl_context_properties cps[3] =
		{
			CL_CONTEXT_PLATFORM,
			(cl_context_properties)platform,
			0
		};
		context = clCreateContextFromType(
			cps,
			dType,
			NULL,
			NULL,
			&status);
		LOG_OCL_ERROR(status, "clCreateContextFromType Failed.");

		// Create command queue
		commandQueue = clCreateCommandQueue(context,
			device,
			0,
			&status);
		LOG_OCL_ERROR(status, "clCreateCommandQueue Failed.");
#if !defined(USE_HOST_MEMORY)
		//Create OpenCL device input buffer
		imageBuffer = clCreateBuffer(
			context,
			CL_MEM_READ_ONLY,
			sizeof(cl_uint) * image->width * image->height,
			NULL,
			&status);
		LOG_OCL_ERROR(status, "clCreateBuffer Failed while creating the image buffer.");

		//Set input data 
		cl_event writeEvt;
		status = clEnqueueWriteBuffer(commandQueue,
			imageBuffer,
			CL_FALSE,
			0,
			image->width * image->height * sizeof(cl_uint),
			image->pixels,
			0,
			NULL,
			&writeEvt);
		LOG_OCL_ERROR(status, "clEnqueueWriteBuffer Failed while writing the image data.");
#else
		//Create OpenCL device input buffer
		imageBuffer = clCreateBuffer(
			context,
			CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
			sizeof(cl_uint) * image->width * image->height,
			image->pixels,
			&status);
		LOG_OCL_ERROR(status, "clCreateBuffer Failed while creating the image buffer.");
#endif
		status = clFinish(commandQueue);
		LOG_OCL_ERROR(status, "clFinish Failed while writing the image data.");

		//Create OpenCL device output buffer
		intermediateHistR = clCreateBuffer(
			context,
			CL_MEM_WRITE_ONLY,
			sizeof(cl_uint) * binSize * subHistgCnt,
			NULL,
			&status);
		LOG_OCL_ERROR(status, "clCreateBuffer Failed.");

		intermediateHistG = clCreateBuffer(
			context,
			CL_MEM_WRITE_ONLY,
			sizeof(cl_uint) * binSize * subHistgCnt,
			NULL,
			&status);
		LOG_OCL_ERROR(status, "clCreateBuffer Failed.");

		intermediateHistB = clCreateBuffer(
			context,
			CL_MEM_WRITE_ONLY,
			sizeof(cl_uint) * binSize * subHistgCnt,
			NULL,
			&status);
		LOG_OCL_ERROR(status, "clCreateBuffer Failed.");

		// Create a program from the kernel source
		cl_program program = clCreateProgramWithSource(context, 1,
			(const char**)&histogram_kernel, NULL, &status);
		LOG_OCL_ERROR(status, "clCreateProgramWithSource Failed.");

		// Build the program
		status = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
		if (status != CL_SUCCESS)
			LOG_OCL_COMPILER_ERROR(program, device);

		// Create the OpenCL kernel
		cl_kernel kernel = clCreateKernel(program, "histogram_kernel", &status);
		LOG_OCL_ERROR(status, "clCreateKernel Failed.");
		// Set the arguments of the kernel
		status = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&imageBuffer);
		status |= clSetKernelArg(kernel, 1, 3 * groupSize * binSize * sizeof(cl_uchar), NULL);
		status |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&intermediateHistR);
		status |= clSetKernelArg(kernel, 3, sizeof(cl_mem), (void*)&intermediateHistG);
		status |= clSetKernelArg(kernel, 4, sizeof(cl_mem), (void*)&intermediateHistB);
		LOG_OCL_ERROR(status, "clSetKernelArg Failed.");
		// Execute the OpenCL kernel on the list
		cl_event ndrEvt;
		size_t globalThreads = (image->width * image->height) / (binSize * groupSize) * groupSize;
		size_t localThreads = groupSize;
		status = clEnqueueNDRangeKernel(
			commandQueue,
			kernel,
			1,
			NULL,
			&globalThreads,
			&localThreads,
			0,
			NULL,
			&ndrEvt);
		LOG_OCL_ERROR(status, "clEnqueueNDRangeKernel Failed.");

		status = clFinish(commandQueue);
		LOG_OCL_ERROR(status, "clFinish Failed.");

		//Read the histogram back into the host memory.
		memset(deviceBinR, 0, binSize * sizeof(cl_uint));
		memset(deviceBinG, 0, binSize * sizeof(cl_uint));
		memset(deviceBinB, 0, binSize * sizeof(cl_uint));
		cl_event readEvt[3];
		status = clEnqueueReadBuffer(
			commandQueue,
			intermediateHistR,
			CL_FALSE,
			0,
			subHistgCnt * binSize * sizeof(cl_uint),
			midDeviceBinR,
			0,
			NULL,
			&readEvt[0]);
		LOG_OCL_ERROR(status, "clEnqueueReadBuffer of intermediateHistR Failed.");

		status = clEnqueueReadBuffer(
			commandQueue,
			intermediateHistG,
			CL_FALSE,
			0,
			subHistgCnt * binSize * sizeof(cl_uint),
			midDeviceBinG,
			0,
			NULL,
			&readEvt[1]);
		LOG_OCL_ERROR(status, "clEnqueueReadBuffer of intermediateHistG Failed.");

		status = clEnqueueReadBuffer(
			commandQueue,
			intermediateHistB,
			CL_FALSE,
			0,
			subHistgCnt * binSize * sizeof(cl_uint),
			midDeviceBinB,
			0,
			NULL,
			&readEvt[2]);
		LOG_OCL_ERROR(status, "clEnqueueReadBuffer of intermediateHistB Failed.");

		status = clWaitForEvents(3, readEvt);
		//status = clFinish(commandQueue);
		LOG_OCL_ERROR(status, "clWaitForEvents for readEvt.");

		// Calculate final histogram bin 


		for (int i = 0; i < subHistgCnt; ++i)
		{
			
			for (int j = 0; j < binSize; ++j)
			{
	
				deviceBinR[j] += midDeviceBinR[i * binSize + j];
				deviceBinG[j] += midDeviceBinG[i * binSize + j];
				deviceBinB[j] += midDeviceBinB[i * binSize + j];
			}
		}

		// Validate the histogram operation. 
		// The idea behind this is that once a histogram is computed the sum of all the bins should be equal to the number of pixels.
		int totalPixelsR = 0;
		int totalPixelsG = 0;
		int totalPixelsB = 0;
		int totalR[256];
		int totalG[256];
		int totalB[256];
		for (int j = 0; j < binSize; ++j)
		{
			totalR[j] = deviceBinR[j];
			totalG[j] = deviceBinG[j];
			totalB[j] = deviceBinB[j];

			totalPixelsR += deviceBinR[j];
			totalPixelsG += deviceBinG[j];
			totalPixelsB += deviceBinB[j];
		}

	   ReleaseBMPImage(&image);

	   ArrB = totalB;
	   ArrR = totalR;
	   ArrG = totalG;
	   imagew = image->width;

		std::vector<Mat> bgr_planes;
		split(src, bgr_planes);
		int histSize = 256;
		float range[] = { 0, 256 }; //the upper boundary is exclusive
		const float* histRange[] = { range };
		bool uniform = true, accumulate = false;
		Mat b_hist, g_hist, r_hist;
		Mat Rmat = cv::Mat(256, 1, CV_32SC1, totalR);
		Mat Gmat = cv::Mat(256, 1, CV_32SC1, totalG);
		Mat Bmat = cv::Mat(256, 1, CV_32SC1, totalB);
		calcHist(&bgr_planes[0], 1, 0, Mat(), Rmat, 1, &histSize, histRange, uniform, accumulate);
		calcHist(&bgr_planes[1], 1, 0, Mat(), Gmat, 1, &histSize, histRange, uniform, accumulate);
		calcHist(&bgr_planes[2], 1, 0, Mat(), Bmat, 1, &histSize, histRange, uniform, accumulate);
		int hist_w = 512, hist_h = 400;
		int bin_w = cvRound((double)hist_w / histSize);
		Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
		normalize(Bmat, Bmat, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(Gmat, Gmat, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(Rmat, Rmat, 0, histImage.rows, NORM_MINMAX, -1, Mat());

		float* histRange1[] = { range };


		   for( int i = 1; i < histSize; i++ )
    {
        line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(Bmat.at<float>(i-1)) ),
			cv::Point( bin_w*(i), hist_h - cvRound(Bmat.at<float>(i)) ),
              Scalar( 255, 0, 0), 2, 8, 0  );
        line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(Gmat.at<float>(i-1)) ),
			cv::Point( bin_w*(i), hist_h - cvRound(Gmat.at<float>(i)) ),
              Scalar( 0, 255, 0), 2, 8, 0  );
        line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(Rmat.at<float>(i-1)) ),
			cv::Point( bin_w*(i), hist_h - cvRound(Rmat.at<float>(i)) ),
              Scalar( 0, 0, 255), 2, 8, 0  );
    }

		   cv::Mat3b const image1 = src;
		   cv::Mat1b image1_gray;
		   cv::cvtColor(image1, image1_gray, cv::COLOR_BGR2GRAY);
		  
		   show_histogram("Luminance", image1_gray);

		   imshow("RGB", histImage);
		   waitKey();

		   free(midDeviceBinR);
		   free(midDeviceBinG);
		   free(midDeviceBinB);
		   free(deviceBinR);
		   free(deviceBinG);
		   free(deviceBinB);
		   
		   wait();


	}




	int textmask = 37;










void show_histogram(std::string const& name, cv::Mat1b const& image)
		   {
			   // Set histogram bins count
			   int bins = 256;
			   int histSize[] = { bins };
			   // Set ranges for histogram bins
			   float lranges[] = { 0, 256 };
			   const float* ranges[] = { lranges };
			   // create matrix for histogram
			   cv::Mat hist;
			   int channels[] = { 0 };

			   // create matrix for histogram visualization
			   int const hist_height = 256;
			   cv::Mat3b hist_image = cv::Mat3b::zeros(hist_height, bins);

			   cv::calcHist(&image, 1, channels, cv::Mat(), hist, 1, histSize, ranges, true, false);

			   double max_val = 0;
			   minMaxLoc(hist, 0, &max_val);

			   // visualize each bin
			   for (int b = 0; b < bins; b++) {
				   float const binVal = hist.at<float>(b);
				   int   const height = cvRound(binVal * hist_height / max_val);
				   cv::line
				   (hist_image
					   , cv::Point(b, hist_height - height), cv::Point(b, hist_height)
					   , cv::Scalar::all(255)
				   );
			   }
			   cv::imshow(name, hist_image);
		   }
		
											

 
private: System::Void LowPassFilter_Click(System::Object^ sender, System::EventArgs^ e) 
{																								  //LowPassFilter
	System::String^ filepath_S = openFileDialog1->FileName;										  //LowPassFilter
	LoadedBitmap->Image = LoadedBitmap->Image->FromFile(openFileDialog1->FileName);				  //LowPassFilter
	std::string filepath = "";																	  //LowPassFilter
	MarshalString(filepath_S, filepath);															
																								  //LowPassFilter																							  //LowPassFilter
	string windowName = "LowPassFilter";														  //LowPassFilter
	string windowSavePath = "";																	  //LowPassFilter
																						  //LowPassFilter
																								  //LowPassFilter
	Mat image = imread(filepath);																   //LowPassfilter
	Mat rgba_image = Mat::zeros(cv::Size(600, 400), CV_8UC4);									   //LowPassfilter
	cvtColor(image, rgba_image, COLOR_BGR2RGBA);
	GaussianBlur(image, rgba_image, cv::Size(textmask, textmask), 0, 0);
	imshow(windowName, rgba_image);
	imwrite("lowpass.jpg", rgba_image);
	waitKey(0);
	LoadedBitmap->Image = LoadedBitmap->Image->FromFile("lowpass.jpg");
	//imshow(windowName, image);
	//waitKey(0);
	


}





private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)		  //Zapisywanie bitmapy do pliku za pomocą file dialog
{																						  //Zapisywanie bitmapy do pliku za pomocą file dialog
	saveFileDialog1->Filter = "Images|*.png;*.bmp;*.jpg";								  //Zapisywanie bitmapy do pliku za pomocą file dialog
	saveFileDialog1->ShowDialog();														  //Zapisywanie bitmapy do pliku za pomocą file dialog
	System::Drawing::Imaging::ImageFormat^ format;										  //Zapisywanie bitmapy do pliku za pomocą file dialog
	LoadedBitmap->Image->Save(saveFileDialog1->FileName, format->Bmp);					  //Zapisywanie bitmapy do pliku za pomocą file dialog
}																						  //Zapisywanie bitmapy do pliku za pomocą file dialog
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {				//Dodawanie odejmowanie maski filtra
	textmask = textmask + 4;																	//Dodawanie odejmowanie maski filtra
}																								//Dodawanie odejmowanie maski filtra
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {				//Dodawanie odejmowanie maski filtra
	textmask = textmask - 4;																	//Dodawanie odejmowanie maski filtra
}																								//Dodawanie odejmowanie maski filtra
};
}
