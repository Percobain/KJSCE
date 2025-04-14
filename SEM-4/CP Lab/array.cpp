#include <bits/stdc++.h>
using namespace std;

class DataMatrix {
    // method 1 = read data
    // method 2 = display data
    public:
    vector<vector<int>> readData() {
        vector<vector<int>> matrix;
        int row, col;
        cout << "Enter number of rows: ";
        cin >> row;
        cout << "Enter number of columns: ";
        cin >> col;

        for (int i = 0; i < row; ++i) {
            vector<int> temp;
            for (int j = 0; j < col; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            matrix.push_back(temp);
        }
        return matrix;
    }

    public:
    void displayData(vector<vector<int>> matrix) {
        if(matrix.empty()) return;

        int maxWidth = 0;
        for(const auto& row : matrix) {
            for(int num : row) {
                maxWidth = max(maxWidth, (int)to_string(num).length());
            }
        }
        
        cout << "\n";
        for(int i = 0; i < matrix.size(); i++) {
            cout << "| ";
            for(int j = 0; j < matrix[i].size(); j++) {
                cout << setw(maxWidth) << matrix[i][j] << " ";
            }
            cout << "|\n";
        }
        cout << "\n";
    }
};

class OperationMatrix {
    // method 1 = add two matrix
    // method 2 = subtract two matrix
    // method 3 = multiply two matrix

    public:
    vector<vector<int>> addMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
        // add two matrix
        vector<vector<int>> result;
        for (int i = 0; i < matrix1.size(); ++i) {
            vector<int> temp;
            for (int j = 0; j < matrix1[i].size(); ++j) {
                temp.push_back(matrix1[i][j] + matrix2[i][j]);
            }
            result.push_back(temp);
            }
        
        return result;
    }

    public:
    vector<vector<int>> subtractMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
        // subtract two matrix
        vector<vector<int>> result;
        for (int i = 0; i < matrix1.size(); ++i) {
            vector<int> temp;
            for (int j = 0; j < matrix1[i].size(); ++j) {
                temp.push_back(matrix1[i][j] - matrix2[i][j]);
            }
            result.push_back(temp);
        }

        return result;
    }

    public:
    vector<vector<int>> multiplyMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
        int row1 = matrix1.size();
        int col1 = matrix1[0].size();
        int col2 = matrix2[0].size();
        vector<vector<int>> result(row1, vector<int>(col2, 0));
        for (int i = 0; i < row1; ++i) {
            for (int j = 0; j < col2; ++j) {
                for (int k = 0; k < col1; ++k) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    DataMatrix data = DataMatrix();
    OperationMatrix operation = OperationMatrix();

    cout << "\nEnter elements for first matrix:" << endl;
    vector<vector<int>> matrix1 = data.readData();
    cout << "\nEnter elements for second matrix:" << endl;
    vector<vector<int>> matrix2 = data.readData();

    cout << "\nFirst Matrix:" << endl;
    data.displayData(matrix1);
    cout << "\nSecond Matrix:" << endl;
    data.displayData(matrix2);

    cout << "\nResult of Matrix Addition:" << endl;
    vector<vector<int>> result = operation.addMatrix(matrix1, matrix2);
    data.displayData(result);

    cout << "\nResult of Matrix Subtraction:" << endl;
    result = operation.subtractMatrix(matrix1, matrix2);
    data.displayData(result);

    cout << "\nResult of Matrix Multiplication:" << endl;
    result = operation.multiplyMatrix(matrix1, matrix2);
    data.displayData(result);

    return 0;
}
