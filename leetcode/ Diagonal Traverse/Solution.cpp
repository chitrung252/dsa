//        if (matrix.size() == 0)
//         {
//             return {};
//         }

//         int column = 0, row = 0, h = matrix.size(), w = matrix[0].size();
//         cout << "h: " << h << endl;
//          cout << "w: " << w << endl;
//         bool up = true;
//         vector<int> res;
//         res.reserve(h*w);

//         while (column < w && row < h)
//         {
//             cout << "row: " << row <<endl;
//             cout << "column: " << column <<endl;
//             res.push_back(matrix[row][column]);
//             int new_row = row + (up ? -1 : 1);
//             int new_column = column + (up ? 1 : -1);
//             cout << "new_row: " << new_row << endl;
//             cout << "new_column: " << new_column << endl;
//             if (new_column < 0 || new_row < 0 || new_row == h || new_column == w)
//             {
//                 cout << "Flip" << endl;
//                 cout << "up" << up << endl;
//                 if (up)
//                 {
//                     column += new_column < w ? 1 : 0;
//                     row += new_column < w ? 0 : 1;
//                 }
//                 else
//                 {
//                     column += new_row < h ? 0 : 1;
//                     row += new_row < h ? 1 : 0;
//                 }
//                 up = !up;
//             }
//             else
//             {
//                   cout << "No Flip" << endl;
//                 column = new_column;
//                 row = new_row;
//             }
//         }