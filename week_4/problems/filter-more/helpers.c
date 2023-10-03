#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum = (float) (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen);
            int avg = (int) round(sum/3);
            if (avg >= 255)
            {
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtBlue = 255;
                image[i][j].rgbtGreen = 255;
            }
            else if (avg <= 0)
            {
                image[i][j].rgbtRed = 0;
                image[i][j].rgbtBlue = 0;
                image[i][j].rgbtGreen = 0;
            }
            else
            {
                image[i][j].rgbtRed = avg;
                image[i][j].rgbtBlue = avg;
                image[i][j].rgbtGreen = avg;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
            if (width%2 == 0)
            {
                for (int j = 0; j < width / 2; j++)
                {
                    RGBTRIPLE tmp[height][width];
                    tmp[i][j] = image[i][j];
                    image[i][j] = image[i][width - (j + 1)];
                    image[i][width - (j + 1)] = tmp[i][j];
                }
            }
            else
            {
                for (int j = 0; j < (width - 1) / 2; j++)
                {
                    RGBTRIPLE tmp[height][width];
                    tmp[i][j] = image[i][j];
                    image[i][j] = image[i][width - (j + 1)];
                    image[i][width - (j + 1)] = tmp[i][j];
                }
            }

            //RGBTRIPLE left = image[i][j];
            //RGBTRIPLE right = image[i][width - j -1];

            //image[i][j] = right;
            //image[i][width - j - 1] = left;
            /*
            image[i][j].rgbtRed = right.rgbtRed;
            image[i][j].rgbtBlue = right.rgbtBlue;
            image[i][j].rgbtGreen = right.rgbtGreen;

            image[i][width - j -1].rgbtRed = left.rgbtRed;
            image[i][width - j -1].rgbtBlue = left.rgbtBlue;
            image[i][width - j -1].rgbtGreen = left.rgbtGreen;
            */

        
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE current;
            current.rgbtBlue = 0;
            current.rgbtGreen = 0;
            current.rgbtRed = 0;
            float sum_blocks = 0;
            for (int x = i-1; x < i+2; x++)
            {
                for (int y = j-1; y < j+2; y++)
                {
                    if (x>=0 && y>=0 && x<height && y<width)
                    {
                        current.rgbtRed += image[x][y].rgbtRed;
                        current.rgbtBlue += image[x][y].rgbtBlue;
                        current.rgbtGreen += image[x][y].rgbtGreen;
                        sum_blocks++;
                    }
                }
            }
            current.rgbtRed = round(current.rgbtRed/sum_blocks);
            current.rgbtBlue = round(current.rgbtBlue/sum_blocks);
            current.rgbtGreen = round(current.rgbtGreen/sum_blocks);

            //making sure all are between 0 and 255
            
            if (current.rgbtRed > 255)
            {
                current.rgbtRed = 255;
            }
            else if (current.rgbtRed < 0)
            {
                current.rgbtRed = 0;
            }

            if (current.rgbtBlue > 255)
            {
                current.rgbtBlue = 255;
            }
            else if (current.rgbtBlue < 0)
            {
                current.rgbtBlue = 0;
            }

            if (current.rgbtGreen > 255)
            {
                current.rgbtGreen = 255;
            }
            else if (current.rgbtGreen < 0)
            {
                current.rgbtGreen = 0;
            }
            
            tmp[i][j].rgbtRed = current.rgbtRed;
            tmp[i][j].rgbtBlue = current.rgbtBlue;
            tmp[i][j].rgbtGreen = current.rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }

    }
    return;
    */
   
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumb = 0;
            float sumg = 0;
            float sumr = 0;
            float pixels = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1 || j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    sumb += image[i + r][j + c].rgbtBlue;
                    sumg += image[i + r][j + c].rgbtGreen;
                    sumr += image[i + r][j + c].rgbtRed;
                    pixels++;
                }
            }

            temp[i][j].rgbtBlue = round(sumb / pixels);
            temp[i][j].rgbtGreen = round(sumg / pixels);
            temp[i][j].rgbtRed = round(sumr / pixels);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }

    }

    return;

}

// Detect edges
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int Green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int Red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if (Red > 255)
            {
                Red = 255;
            }
            else if (Red < 0)
            {
                Red = 0;
            }

            if (Blue > 255)
            {
                Blue = 255;
            }
            else if (Blue < 0)
            {
                Blue = 0;
            }

            if (Green > 255)
            {
                Green = 255;
            }
            else if (Green < 0)
            {
                Green = 0;
            }
            image[i][j].rgbtBlue = Blue;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtRed = Red;
        }
    }
    return;
}
