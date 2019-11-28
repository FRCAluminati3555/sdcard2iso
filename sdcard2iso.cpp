/*
 * Copyright (c) 2019 Team 3555
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE					1048576

#include <stdio.h>
#include <string>

int main(int argc, char** args)
{
	// Buffer for reading
	char* buffer = new char[BUFFER_SIZE];
	if (buffer == NULL)
	{
		printf("Error: Out of memory\n");
		return -1;
	}

	// Check arguments
	if (argc < 3)
	{
		printf("Usage: sdcard2iso <device number> <iso file>\n");
		return -1;
	}

	// Open SD card
	std::string sdCardPath = std::string("\\\\.\\PHYSICALDRIVE");
	sdCardPath += args[1];

	FILE* sdCard = fopen(sdCardPath.c_str(), "rb");
	if (sdCard == NULL)
	{
		printf("Error: Unable to access SD card\n");
		return -1;
	}

	// Open iso file
	FILE* iso = fopen(args[2], "wb");
	if (iso == NULL)
	{
		printf("Error: Unable to access ISO file\n");
		return -1;
	}

	// Copy
	while (size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, sdCard))
	{
		fwrite(buffer, 1, bytesRead, iso);
	}

	// Close files
	fclose(sdCard);
	fclose(iso);

	// Release buffer
	delete[] buffer;
}
