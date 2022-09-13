#include <CImg.h>
#include <iostream>
using namespace cimg_library;
using namespace std;

typedef CImg <unsigned char> Image;
typedef CImgList <unsigned char> ImageList;

int main(int argc, char *argv[])
{
  int width, height, list_size;
  Image image(argv[1]);
  ImageList list;
  image.display();
  width = image.width();
  height = image.height();
  cout << "Image width x height = " << width << " x " << height << endl;
  list.insert(image);
  list.insert(image);
  list_size = list.size();
  cout << "List size = " << list_size << endl;
  return 0;
}
