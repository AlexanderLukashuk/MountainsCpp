#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    int size;
    cin >> size;
    int mountains[size][size];
    int peaks_count = sqrt(size);
    int peaks_x[peaks_count];
    int peaks_y[peaks_count];
    bool check_x, check_y;

    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;
    // cout << rand() % size << endl;


    srand(time(NULL));
    for (int i = 0; i < peaks_count; i++)
    {
        // peaks_x[i] = rand() % size - ((size - (size / 4)) / 2);
        peaks_x[i] = rand() % size;
        // peaks_y[i] = rand() % size - ((size - (size / 4)) / 2);
        peaks_y[i] = rand() % size;
    }
    cout << peaks_count << endl;

    for (int i = 0; i < peaks_count; i++)
    {
        cout << "Peaks x: " <<  peaks_x[i] << " Peaks y: " << peaks_y[i] << endl;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mountains[i][j] = 0;
        }
    }

    for (int i = 0; i < peaks_count; i++)
    {
        mountains[*(peaks_x + i)][*(peaks_y + i)] = 1;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mountains[i][j] == 1)
            {
                // for (int k = i; k < size; k++)
                // {
                //     // if (k == size)
                //     // {
                //     //     break;
                //     // }
                //     mountains[k][k] = 1;
                //     // cout << "hui" << " ";
                // }

                for (int k = i, l = j; k < size, l < size; k++, l++)
                {
                    mountains[k][l] = 1;
                }

                for (int k = i, l = j; k >= 0, l < size; k--, l++)
                {
                    mountains[k][l] = 1;
                }

                // for (int k = i; k >= 0; k--)
                // {
                //     mountains[k][k] = 1;
                // }
                // cout << "pizda" << endl;
                // cout << endl;
            }
            
        }
    }



    for (int i = 0; i < size; i++)
    {
        // for (int k = 0; k < peaks_count; k++)
        // {
        //     if (i == peaks_x[k])
        //     {
        //         check_x = true;
        //         break;
        //     }
        // }
        for (int j = 0; j < size; j++)
        {
            // for (int l = 0; l < peaks_count; l++)
            // {
            //     if (j == peaks_y[l])
            //     {
            //         check_y = true;
            //         break;
            //     }
            // }
            // for (int k = 0; k < peaks_count; k++)
            // {
            //     for (int l = 0; l < peaks_count; l++)
            //     {
            //         if (i == peaks_x[k] && j == peaks_y[l])
            //         {
            //             // mountains[i][j] = 1;
            //             check = true;
            //             // cout << "хуй" << endl;
            //         }
            //         else
            //         {
            //             check = false;
            //             // mountains[i][j] = 0;
            //             // cout << "пизда" << endl;
            //         }
            //     }
            // }
            // cout << "exit" << endl;
            // if (check_x && check_y)
            // {
            //     mountains[i][j] = 1;
            // }
            // else
            // {
            //     mountains[i][j] = 0;
            // }
            
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mountains[i][j];
        }
        cout << endl;
    }
}