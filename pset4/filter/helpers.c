#include "helpers.h"
#include <stdio.h>
#include <math.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int new_color = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = new_color;
            image[i][j].rgbtGreen = new_color;
            image[i][j].rgbtRed = new_color;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE color_holder;
    color_holder.rgbtRed = 0;
    color_holder.rgbtGreen = 0;
    color_holder.rgbtBlue = 0;

    for (int h = 0; h < height; h++)
    {
        for (int i = 0, w = width / 2; i < w; i++)
        {
            color_holder = image[h][i];
            image[h][i] = image[h][width - i - 1];
            image[h][width - i - 1] = color_holder;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_holder[height][width];
    int red_sum = 0;
    int blue_sum = 0;
    int green_sum = 0;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_holder[i][j] = image[i][j];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int divcount = 0;

            for (int i = -1; i < 2; i++)
            {
                if (h == 0 && i == -1)
                {
                    continue;
                }
                else if (h == height - 1 && i == 1)
                {
                    continue;
                }

                for (int j = -1; j < 2; j++)
                {
                    if (w == 0 && j == -1)
                    {
                        continue;
                    }
                    else if (w == width - 1 && j == 1)
                    {
                        continue;
                    }

                    red_sum += image_holder[h + i][w + j].rgbtRed;
                    green_sum += image_holder[h + i][w + j].rgbtGreen;
                    blue_sum += image_holder[h + i][w + j].rgbtBlue;
                    divcount++;
                }
            }

            int new_red = (int)round(red_sum / (float)divcount);
            int new_blue = (int)round(blue_sum / (float)divcount);
            int new_green = (int)round(green_sum / (float)divcount);

            image[h][w].rgbtRed = new_red;
            image[h][w].rgbtGreen = new_green;
            image[h][w].rgbtBlue = new_blue;

            red_sum = 0;
            blue_sum = 0;
            green_sum = 0;
        }
    }


    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_holder[height][width];

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int gx_red_sum = 0;
    int gx_blue_sum = 0;
    int gx_green_sum = 0;

    int gy_red_sum = 0;
    int gy_blue_sum = 0;
    int gy_green_sum = 0;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_holder[i][j] = image[i][j];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            for (int i = -1; i < 2; i++)
            {
                if (h == 0 && i == -1)
                {
                    continue;
                }
                else if (h == height - 1 && i == 1)
                {
                    continue;
                }

                for (int j = -1; j < 2; j++)
                {
                    if (w == 0 && j == -1)
                    {
                        continue;
                    }
                    else if (w == width - 1 && j == 1)
                    {
                        continue;
                    }

                    gx_red_sum += image_holder[h + i][w + j].rgbtRed * gx[i + 1][j + 1];
                    gx_green_sum += image_holder[h + i][w + j].rgbtGreen * gx[i + 1][j + 1];
                    gx_blue_sum += image_holder[h + i][w + j].rgbtBlue * gx[i + 1][j + 1];

                    gy_red_sum += image_holder[h + i][w + j].rgbtRed * gy[i + 1][j + 1];
                    gy_green_sum += image_holder[h + i][w + j].rgbtGreen * gy[i + 1][j + 1];
                    gy_blue_sum += image_holder[h + i][w + j].rgbtBlue * gy[i + 1][j + 1];


                }
            }

            int new_red = round(sqrt((float)gx_red_sum * gx_red_sum + (float)gy_red_sum * gy_red_sum));

            int new_blue = round(sqrt((float)gx_blue_sum * gx_blue_sum + (float)gy_blue_sum * gy_blue_sum));

            int new_green = round(sqrt((float)gx_green_sum * gx_green_sum + (float)gy_green_sum * gy_green_sum));

            if (new_red > 255)
            {
                new_red = 255;
            }
            if (new_blue > 255)
            {
                new_blue = 255;
            }
            if (new_green > 255)
            {
                new_green = 255;
            }

            image[h][w].rgbtRed = new_red;
            image[h][w].rgbtGreen = new_green;
            image[h][w].rgbtBlue = new_blue;


            gx_red_sum = 0;
            gx_blue_sum = 0;
            gx_green_sum = 0;

            gy_red_sum = 0;
            gy_blue_sum = 0;
            gy_green_sum = 0;

        }
    }


    return;
}
