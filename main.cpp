#if 0
#include "opencv2/opencv.hpp"
#include <iostream>

int main()
{
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	cv::Mat img;
	img = cv::imread("lenna.bmp");  // bmp ������ �ҷ��ͼ� img ������ �����Ѵ�.

	if (img.empty()) {			    // bmp ������ �������� �ʰų� �ջ�Ǿ��� ��� Mat::empty()�� true�� ��ȯ�Ѵ�.
		std::cerr << "Image load failed!" << std::endl; // true ��ȯ���� if�� ������ ������ ��� �ش� ���ڿ� ��� ��
		return -1;				    // ���α׷��� �����Ѵ�.
	}

	cv::namedWindow("image");	    // ������ ��Ÿ�� ���ο� â�� �����ϰ� â�� �̸�("image")�� �ο��Ѵ�.
	cv::imshow("image", img);	    // ���� ���

	cv::waitKey();				    // ������� Ű���� �Է��� ��ٸ��� �Լ�
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
	img = imread("lenna.bmp");  // bmp ������ �ҷ��ͼ� img ������ �����Ѵ�.

	if (img.empty()) {			    // bmp ������ �������� �ʰų� �ջ�Ǿ��� ��� Mat::empty()�� true�� ��ȯ�Ѵ�.
		cerr << "Image load failed!" << endl; // true ��ȯ���� if�� ������ ������ ��� �ش� ���ڿ� ��� ��
		return -1;				    // ���α׷��� �����Ѵ�.
	}

	namedWindow("image");	    // ������ ��Ÿ�� ���ο� â�� �����ϰ� â�� �̸�("image")�� �ο��Ѵ�.
	imshow("image", img);	    // ���� ���
	waitKey();				    // ������� Ű���� �Է��� ��ٸ��� �Լ�
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
			bgra[0] = UCHAR_MAX; // UCHAR_MAX�� 255���� �ǹ��Ѵ�.
			bgra[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols)* UCHAR_MAX); // Green
			bgra[2] = saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.cols)* UCHAR_MAX); // Red
			bgra[3] = saturate_cast<uchar>(0.5 * (bgra[1] + bgra[2])); //Alpha(����)
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
}
#endif

