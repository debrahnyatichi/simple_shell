#include <stdio.h>
/**
 * draw_triangle-function that draws a right angled triangle.
 * @h: height of the triangle
 * @w: width of the triangle
 */

void draw_triangle(int h, int w)
{
	int i, k;

	if (h <= 0 || w <= 0)
	{
	printf("Error: h and w must be positive.\n");
return;
	}
	for (i = 1; i <= h; i++)
	{
		for (k = 1; k <= i && k <= w; k++)
		{
			printf("*");
		}
		printf("\n");
}
}
