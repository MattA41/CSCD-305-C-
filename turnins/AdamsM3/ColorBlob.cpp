#include "ColorBlob.h"

#include <chrono>

ColorBlob::ColorBlob()
{
	//creates 2d array of colors with default color
	width = 2;
	height = 2;
	data = new Color * [height];

	for (int j = 0; j < height; j++)
	{
		data[j] = new Color[width];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			data[i][j] = Color();
		}
	}
}

ColorBlob::ColorBlob(int w, int h, const Color& c)
{
	width = w;
	height = h;
	data = new Color * [height];

	for (int j = 0; j < height; j++)
	{
		data[j] = new Color[width];
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{	
			data[i][j] = c ;
		}
	}
}
ColorBlob::ColorBlob(const ColorBlob& cBlob)
{
	width = cBlob.width;
	height = cBlob.height;
	data = new Color * [height];

	for (int j = 0; j < height; j++)
	{
		data[j] = new Color[width];
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			data[i][j] = cBlob.data[i][j];
		}
	}
}

ColorBlob& ColorBlob::operator=(const ColorBlob& cBlob)
{
	if (this != &cBlob)
	{
		width = cBlob.width;
		height = cBlob.height;
		data = new Color * [height];

		for (int j = 0; j < height; j++)
		{
			data[j] = new Color[width];
		}
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				data[i][j] = cBlob.data[i][j];
			}
		}
	}
	return *this;
}

ColorBlob::ColorBlob(ColorBlob&& cBlob)
{
	width = cBlob.width;
	height = cBlob.height;
	data = new Color * [height];

	for (int j = 0; j < height; j++)
	{
		data[j] = new Color[width];
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			data[i][j] = cBlob.data[i][j];
		}
	}
}
ColorBlob& ColorBlob::operator=(ColorBlob&& cBlob)
{
	if (this != &cBlob)
	{
		width = cBlob.width;
		height = cBlob.height;
		data = new Color * [height];

		for (int j = 0; j < height; j++)
		{
			data[j] = new Color[width];
		}
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				data[i][j] = cBlob.data[i][j];
			}
		}
	}
	return *this;
}
ColorBlob :: ~ColorBlob()
{
	for (int i = 0; i < width; i++)
	{
		delete[] data[i];
		data[i] = nullptr;
	}
	delete[] data;
	data = nullptr;
}

bool operator==(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo)
{
	if (cBlobOne.width != cBlobTwo.width || cBlobOne.height != cBlobTwo.height)
	{
		return false;
	}
	else
	{
		return true;
	}
}
ColorBlob::ColorBlob(int w, int h, Color** c)
{
	width = w;
	height = h;
	data = new Color * [height];

	for (int j = 0; j < height; j++)
	{
		data[j] = new Color[width];
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			data[i][j] = c[i][j];
		}
	}

}

ColorBlob operator+(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo)
{
	int newWidth, newHeight;

	if (cBlobOne.width >= cBlobTwo.width)
	{
		newWidth = cBlobOne.width;
	}
	else
	{
		newWidth = cBlobTwo.width;
	}
	if (cBlobOne.height >= cBlobTwo.height)
	{
		newHeight = cBlobOne.height;
	}
	else
	{
		newHeight = cBlobTwo.height;
	}
	/*data = new Color * [height];

	for (int j = 0; j < height; j++)
	{
		data[j] = new Color[width];
	}*/

	Color** newData = new Color * [newHeight];
	for (int j = 0; j < newHeight; j++)
	{
		newData[j] = new Color[newWidth];
	}

	for (int i = 0; i < newWidth; i++)
	{
		for (int j = 0; j < newHeight; j++)
		{
			newData[i][j] = cBlobOne.data[i][j] + cBlobTwo.data[i][j];
		}
	}
	return ColorBlob(newWidth, newHeight, newData);

}

ColorBlob operator-(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo)
{
	int newWidth, newHeight;

	if (cBlobOne.width >= cBlobTwo.width)
	{
		newWidth = cBlobOne.width;
	}
	else
	{
		newWidth = cBlobTwo.width;
	}
	if (cBlobOne.height >= cBlobTwo.height)
	{
		newHeight = cBlobOne.height;
	}
	else
	{
		newHeight = cBlobTwo.height;
	}

	Color** newData = new Color * [newHeight];
	for (int j = 0; j < newHeight; j++)
	{
		newData[j] = new Color[newWidth];
	}

	for (int i = 0; i < newWidth; i++)
	{
		for (int j = 0; j < newHeight; j++)
		{
			newData[i][j] = cBlobOne.data[i][j] - cBlobTwo.data[i][j];
		}
	}
	return ColorBlob(newWidth, newHeight, newData);
}

ColorBlob operator*(const ColorBlob& cBlobOne, const Color& c)
{
	Color** newData = new Color * [cBlobOne.height];
	for (int j = 0; j < cBlobOne.height; j++)
	{
		newData[j] = new Color[cBlobOne.width];
	}

	for (int i = 0; i < cBlobOne.width; i++)
	{
		for (int j = 0; j < cBlobOne.height; j++)
		{
			newData[i][j] = cBlobOne.data[i][j] * c;
		}
	}
	return ColorBlob(cBlobOne.width, cBlobOne.height, newData);
}

bool operator! (const ColorBlob& cBlob)
{
	int colorNum = cBlob.width * cBlob.height;
	for (int i = 0; i < cBlob.width; i++)
	{
		for (int j = 0; j < cBlob.height; j++)
		{
			if (!cBlob.data[i][j])
			{
				colorNum--;
			}
		}
	}
	if (colorNum == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& out, const ColorBlob& cBlob)
{
	for (int i = 0; i < cBlob.width; i++)
	{
		for (int j = 0; j < cBlob.height; j++)
		{
			out << cBlob.data[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, ColorBlob& cBlob)
{
	for (int i = 0; i < cBlob.width; i++)
	{
		for (int j = 0; j < cBlob.height; j++)
		{
			cout << "Enter the RGB values for the color at position " << i << " " << j << endl;
			in >> cBlob.data[i][j];
		}
	}
	return in;
}