#if 0
#include "opencv2/opencv.hpp"
#include <iostream>

int main()
{
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	cv::Mat img;
	img = cv::imread("lenna.bmp");  // bmp 파일을 불러와서 img 변수에 저장한다.

	if (img.empty()) {			    // bmp 파일이 존재하지 않거나 손상되었을 경우 Mat::empty()는 true를 반환한다.
		std::cerr << "Image load failed!" << std::endl; // true 반환으로 if문 안으로 진입할 경우 해당 문자열 출력 후
		return -1;				    // 프로그램을 종료한다.
	}

	cv::namedWindow("image");	    // 영상을 나타낼 새로운 창을 생성하고 창의 이름("image")를 부여한다.
	cv::imshow("image", img);	    // 영상 출력

	cv::waitKey();				    // 사용자의 키보드 입력을 기다리는 함수
	return 0;
}
#endif


#if 0
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img;
	img = imread("lenna.bmp");  // bmp 파일을 불러와서 img 변수에 저장한다.

	if (img.empty()) {			    // bmp 파일이 존재하지 않거나 손상되었을 경우 Mat::empty()는 true를 반환한다.
		cerr << "Image load failed!" << endl; // true 반환으로 if문 안으로 진입할 경우 해당 문자열 출력 후
		return -1;				    // 프로그램을 종료한다.
	}

	namedWindow("image");	    // 영상을 나타낼 새로운 창을 생성하고 창의 이름("image")를 부여한다.
	imshow("image", img);	    // 영상 출력
	waitKey();				    // 사용자의 키보드 입력을 기다리는 함수
	return 0;
}
#endif

#if 0
#include <iostream>>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;
static void createAlphaMat(Mat &mat) {
	CV_Assert(mat.channels() == 4);
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++)
		{
			Vec4b& bgra = mat.at<Vec4b>(i, j);
			bgra[0] = UCHAR_MAX; // UCHAR_MAX는 255값을 의미한다.
			bgra[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols)* UCHAR_MAX); // Green
			bgra[2] = saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.cols)* UCHAR_MAX); // Red
			bgra[3] = saturate_cast<uchar>(0.5 * (bgra[1] + bgra[2])); //Alpha(투명도)
		}
	}
}
int main() {
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);
	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	bool result = false;
	try {
		result = imwrite("alpha.png", mat, compression_params);
	}
	catch (const cv::Exception& ex)
	{
		fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
	}
	if (result)
		printf("Save PNG file with a alpha data.\n");
	else
		printf("ERROR: Can't save PNG file.\n");
	return result ? 0 : 1;
}
#endif

#if 1
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cout << " Hello OpenCV " << CV_VERSION << endl;
	Mat img;
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load falid!" << endl;
		return -1;
	}

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	waitKey();
	moveWindow("image", 500, 500);
	waitKey();
	resizeWindow("image", 600, 300);
	waitKey();
	return 0;
	//
}
#endif

