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
    int lakeVolume = 0;
    int lakeVolumeArray[100];
    int lakeVolumeArrayIndex = 0;

    for (int i = 0; i < 100; i++)
    {
        lakeVolumeArray[i] = 0;
    }

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

    int x_index = 0;
    int y_index = 0;
    bool x_check_index;
    bool y_check_index;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < peaks_count; k++)
            {
                if (i == peaks_x[k])
                {
                    x_check_index = true;
                    break;
                }
            }

            for (int k = 0; k < peaks_count; k++)
            {
                if (j == peaks_y[k])
                {
                    y_check_index = true;
                    break;
                }
            }

            if (mountains[i][j] == 1 && x_check_index && y_check_index)
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

                //for (int k = i, l = j; k < size, l < size; k++, l++)
                for (int k = i, l = j;; k++, l++)
                {
                    if (k == size || l == size)
                    {
                        break;
                    }
                    mountains[k][l] = 1;
                }

                // for (int k = i, l = j; k < size, l >= 0; k++, l--)
                for (int k = i, l = j;; k++, l--)
                {
                    if (k == size || l == 0)
                    {
                        break;
                    }
                    mountains[k][l] = 1;
                }

                x_index++;
                y_index++;
                cout << "x = " << x_index << " y = " << x_index << endl;

                // for (int k = i; k >= 0; k--)
                // {
                //     mountains[k][k] = 1;
                // }
                // cout << "pizda" << endl;
                // cout << endl;
            }

            x_check_index = false;
            y_check_index = false;
            
        }
    }

    cout << "Ebal tvoi rot" << endl;

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (mountains[i][j] == 1)
            {
                for (int k = i; k < size; k++)
                {
                    mountains[k][j] = 1;
                }
            }
        }
    }

    cout << "Ebal tvoi rot" << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mountains[i][j];
        }
        cout << endl;
    }

    srand(time(NULL));
    int mine = rand() % size;
    // mine += 5;
    // int mine = rand() % size;
    cout << "Mine start = " << mine << endl;
    int mineLength = 0;
    int dwarfMines[100];
    int dwarfsMinesIndex = 0;
    int mineStart_x[50];
    int mineEnd_x[50];
    int mineStart_y[50];
    int mineEnd_y[50];
    int mineStartIndex = 0;
    int mineEndIndex = 0;
    int mine_j;

    for (int i = 0; i < 50; i++)
    {
        dwarfMines[i] = -1;
        mineStart_x[i] = -1;
        mineEnd_x[i] = -1;
        mineStart_y[i] = -1;
        mineEnd_y[i] = -1;
    }

    cout << "99 problems" << endl;

    for (int j = 0; j < size; j++)
    {
        if (mountains[mine][j] == 1)
        {
            mine_j = j;
            break;
        }
    }

    cout << "Mine j = " << mine_j << endl;

    while (mountains[mine][mine_j] != 0)
    {
        mineStart_x[mineStartIndex] = mine_j;
        mineStart_y[mineStartIndex] = mine;
        mineStartIndex++;

        for (int k = mine_j;; k++)
        {
            if (mountains[mine][k] == 0 || k == size)
            {
                mineEnd_x[mineEndIndex] = k;
                mineEnd_y[mineEndIndex] = mine;
                mineEndIndex++;
                break;
            }
            mountains[mine][k] = 0;
            mineLength++;
        }

        dwarfMines[dwarfsMinesIndex] = mineLength;
        dwarfsMinesIndex++;
        mineLength = 0;
    }

    cout << "Blya" << endl;

    cout << "Ebal tvoi rot" << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mountains[i][j];
        }
        cout << endl;
    }

    cout << "huita" << endl;

    int maxLakeVolume = lakeVolumeArray[0];
    lakeVolumeArrayIndex = 0;


    int icicle_i[50];
    int icicle_j[50];
    int icicleIndex = 0;

    for (int i = 0; i < 50; i++)
    {
        icicle_i[i] = -1;
        icicle_j[i] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mountains[i][j + 1] == 1 || mountains[i][j - 1] == 1 || mountains[i - 1][j] == 1)
            {
                continue;
            }

            if (mountains[i][j] == 1)
            {
                icicle_i[icicleIndex] = i;
                icicle_j[icicleIndex] = j;
                icicleIndex++;
            }
        }
    }

    cout << "Pidaras" << endl;

    int icicleLength = 0;
    int icicleLengthArray[50];
    icicleIndex = 0;

    for (int i = 0; i < 50; i++)
    {
        icicleLengthArray[i] = -1;
    }

    while (icicle_i[icicleIndex] != -1)
    {
        for (int j = icicle_j[icicleIndex];; j++)
        {
            if (j + 1 == size)
            {
                break;
            }
            mountains[icicle_i[icicleIndex]][j] = 2;
            icicleLength++;
        }
        icicleLengthArray[icicleIndex] = icicleLength;
        icicleLength = 0;
        icicleIndex++;
    }

    cout << "EPTA" << endl;

    int maxIcicleLength = icicleLengthArray[0];
    icicleIndex = 0;
    while (icicleLengthArray[icicleIndex] != -1)
    {
        if (icicleLengthArray[icicleIndex] > maxIcicleLength)
        {
            maxIcicleLength = icicleLengthArray[icicleIndex];
        }
        icicleIndex++;
    }

    cout << "HUITA" << endl;

    cout << "The biggest icicle: " << maxIcicleLength << endl;

    // while (lakeVolumeArray[lakeVolumeArrayIndex] != 0)
    // {
    //     if (lakeVolumeArray[lakeVolumeArrayIndex] > maxLakeVolume)
    //     {
    //         maxLakeVolume = lakeVolumeArray[lakeVolumeArrayIndex];
    //     }
    //     lakeVolumeArrayIndex++;
    // }

    cout << "pizdec" << endl;


    // mineStartIndex = 0;
    // mineEndIndex = 0;
    dwarfsMinesIndex = 0;
    int maxMineLength = dwarfMines[0];
    int maxMineLengthIndex;
    // while (dwarfMines[dwarfsMinesIndex] != -1)
    // {
    //     if (dwarfMines[dwarfsMinesIndex > maxMineLength])
    //     {
    //         maxMineLength = dwarfMines[dwarfsMinesIndex];
    //         maxMineLengthIndex = dwarfsMinesIndex;
    //     }
    //     dwarfsMinesIndex++;
    //     // mineStartIndex++;
    //     // mineEndIndex++;
    // }

    // cout << "pizdec 2" << endl;

    // cout << "Max mine legth = " << dwarfMines[maxMineLengthIndex] << " coordinates:" << endl;
    // cout << "Start: x = " << mineStart_x[maxMineLengthIndex] << " y = " << mineStart_y[maxMineLengthIndex] << endl;
    // cout << "End: x = " << mineEnd_x[maxMineLengthIndex] << " y = " << mineEnd_y[maxMineLengthIndex] << endl;

    cout << "Nu chto za huina" << endl;

    cout << "Max lake volume = " << maxLakeVolume << endl;
}