#pragma once
#include <stdint.h>
#include <string>
#include "opencv2/videoio.hpp"

class Recorder
{
private:
	cv::VideoCapture m_Capture;
	cv::VideoWriter m_Writer;
	cv::UMat m_Frame;
	cv::Size m_Size;
	char m_TimestampBuffer[20];
	uint64_t m_FrameIndex;
	uint64_t m_BeginTime;
	uint64_t m_LastTime;

public:
	Recorder(const uint8_t& camIndex = 0, const std::string& filename = "out.avi", const cv::Size& captureSize = { 640, 480 }, const double& fps = 30.0);
	~Recorder();

	bool grab();
	bool retrieve();
	void write();
	uint64_t frameIndex();
};