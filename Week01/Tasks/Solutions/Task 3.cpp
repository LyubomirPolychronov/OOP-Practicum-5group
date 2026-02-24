#include <iostream>

namespace TrianglesNS {
	struct Triangle {
		int side;
		int height;
		double findArea() const {
			if (height == 0 || side == 0)
			{
				return 0;
			}
			return (height * side) / 2.0;
		}
	};
	void printArray(int n,const Triangle* arr) {
		for (int i = 0; i < n; i++)
		{
			std::cout << "Triangle number" << i + 1 << ": " << "area = " << arr[i].findArea() << " (with side: " << arr[i].side << " and height: " << arr[i].height << ")" << std::endl;
		}
	}
	void sortArr(int n, Triangle* arr) {
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i].findArea() < arr[j].findArea())
				{
					Triangle temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		printArray(n, arr);
	}
	void fillArrayOfTriangles(int n) {
		Triangle* array = new Triangle[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> array[i].side >> array[i].height;
		}
		sortArr(n, array);
		delete[] array;
	}
}

int main()
{
	using namespace TrianglesNS;
	int n;
	std::cin >> n;
	fillArrayOfTriangles(n);

}
