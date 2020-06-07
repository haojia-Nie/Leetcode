/* Ideas:
   1. get the lenght of the array and arrange to the print_array, 
   play with the index
   2. Find the pattern in the zig zag layout and arrange the index
   */

#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string convert(string s, int numRows) {
			int pattern = numRows + (numRows - 2);
			int len = s.length();
			string r = "";
			for (int i = 0; i < numRows; i ++) {
				for (int j = 0; j + i < len; j += pattern) {
					r += s.substr(j + i, 1);
					int add = j + pattern - i;
					if (i != 0 && i != (numRows - 1)
							&& (add < len)) 
						r += s.substr(add, 1);
				}
			}
			return r;
		}	
};


int main() {

	Solution b;
	string t1 = "testcase";
	string t1_zz2 = b.convert(t1, 2);
	string t1_zz3 = b.convert(t1, 3);
	cout << "string: " << t1 << "  row: " << 2 << " " << t1_zz2 << endl;
	cout << "string: " << t1 << "  row: " << 2 << " " << t1_zz3 << endl;

	/* output:
		string: testcase  row: 2 tscsetae
		string: testcase  row: 2 tcetaess
	*/
}
