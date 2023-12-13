#include "monty.h"

int main(void)
{
	size_t bytesRead;
	char buffer[100];

	FILE *file = fopen("000.m", "rb");

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	bytesRead = fread(buffer, 1, 10, file);

	if (bytesRead > 0)
	{
		printf("Read %d bytes from the file.\n", bytesRead);
	}
	else
	{
		perror("Error reading from file");
	}

	fclose(file);

	return (0);
}