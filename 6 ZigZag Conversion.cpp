/*6 ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) 
    {
          if(nRows <= 1 || s.empty()==true) 
          {
              return s;
          }
          const int len = (int)s.length(); 
          string *str = new string[nRows];  //nRows string
          int row = 0; 
          int step = 1; //1 stand for up to down
          for(int i=0; i<len; ++i)
          {
              str[row].push_back(s[i]);   
              if(row == 0)
              {
                  step = 1;
              }
              else if(row == nRows-1)
              {
                  step = -1; // -1 stand for down to up
              }
              row += step;   
          }
          s.clear(); 
          for(int j=0; j<nRows; ++j)
          {
              s.append(str[j]);
          }
          delete[] str;
          return s;
    }
};