#include <iostream>
using namespace std;

struct UnivereseCoordinate{
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};
void addcoordinate(UnivereseCoordinate* UniverseData[], int snakecount, int i, int j, bool issnake){
    UniverseData[i][j].is_snake = issnake;
    UniverseData[i][j].s_number = snakecount;
    UniverseData[i][j].x_position = i;
    UniverseData[i][j].y_position = j;
}
void displaygrid(UnivereseCoordinate* UniverseData[], int rows, int cols){
     cout << "GRID MAP"<<endl;
     cout<<"\n(. indicates no snakes)\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (UniverseData[i][j].is_snake) {
                cout << "S" << UniverseData[i][j].s_number << "\t";
            } else {
                cout << ".\t";
            }
        }
        cout << endl;
    }
    cout << "================\n";
}

void expandGrid(UnivereseCoordinate*** UniverseData, int& rows, int& cols) {
    int newRows = rows * 2;
    int newCols = cols * 2;

    UnivereseCoordinate** newData = new UnivereseCoordinate*[newRows];
    for (int i = 0; i < newRows; i++) {
        newData[i] = new UnivereseCoordinate[newCols];
        for (int j = 0; j < newCols; j++) {
            newData[i][j].is_snake = false;
            newData[i][j].s_number = 0;
            newData[i][j].x_position = i;
            newData[i][j].y_position = j;
        }
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newData[i][j] = (*UniverseData)[i][j];
        }
    }


    for (int i = 0; i < rows; i++) {
        delete[] (*UniverseData)[i];
    }
    delete[] *UniverseData;

    *UniverseData = newData;
    rows = newRows;
    cols = newCols;
}

int main() {
    int rows = 2, cols = 2;
    int snakecount = 0;

    UnivereseCoordinate** UniverseData = new UnivereseCoordinate*[rows];
    for (int i = 0; i < rows; i++) {
        UniverseData[i] = new UnivereseCoordinate[cols];
        for (int j = 0; j < cols; j++) {
            UniverseData[i][j].is_snake = false;
            UniverseData[i][j].s_number = 0;
            UniverseData[i][j].x_position = i;
            UniverseData[i][j].y_position = j;
        }
    }

    int i = 0, j = 0;
    char choice;

    while (true) {
        cout << "-----------------\n";
        cout << "Do you want to add a coordinate? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') break;

        cout << "Adding details for coordinate (" << i << ", " << j << ")\n";
        cout << "Is a snake present on this coordinate (y/n)? ";
        char ans;
        cin >> ans;

        bool issnake = false;
        if (ans == 'y' || ans == 'Y') {
            snakecount++;
            issnake = true;
        }

        addcoordinate(UniverseData, snakecount, i, j, issnake);

        j++;
        if (j >= cols) {
            j = 0;
            i++;
        }


        if (i >= rows) {
            cout << "Grid full - Expanding.\n";
            expandGrid(&UniverseData, rows, cols);
        }
    }

    cout << "\nStopped taking data....Showing Final Grid\n";
    displaygrid(UniverseData, rows, cols);


    for (int i = 0; i < rows; i++) {
        delete[] UniverseData[i];
    }
    delete[] UniverseData;

    return 0;
}