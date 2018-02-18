#include <time.h>
#include "Recorder.h"
#include "opencv2/imgproc.hpp"

Recorder::Recorder(const uint8_t& camIndex, const std::string& filename, const cv::Size& captureSize, const double& fps)
	: m_Capture(cv::VideoCapture(camIndex))
	, m_Writer(cv::VideoWriter(filename, cv::VideoWriter::fourcc('F', 'M', 'P', '4'), fps, captureSize))
	, m_Size(captureSize)
	, m_FrameIndex(0)
	, m_BeginTime(clock())
{
	m_Capture.set(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH, captureSize.width);
	m_Capture.set(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT, captureSize.height);
	m_Capture.set(cv::VideoCaptureProperties::CAP_PROP_FPS, fps);
}

Recorder::~Recorder()
{
}

bool Recorder::grab()
{
	//++m_FrameIndex;
	//m_LastTime = clock();
	//return m_Capture.grab();
	return true;
}

bool Recorder::retrieve()
{
	//bool success = m_Capture.retrieve(m_Frame);
	m_LastTime = clock();
	bool success = true;
	m_Capture >> m_Frame;
	if (!success) return false;
	cv::putText(m_Frame, std::to_string(m_LastTime), { 0, m_Size.height }, cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(255.0, 255.0, 255.0, 255.0));

	return true;
}

void Recorder::write()
{
	m_Writer.write(m_Frame.getMat(0));
}

uint64_t Recorder::frameIndex()
{
	return m_FrameIndex;
}