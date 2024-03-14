class Solution {
public:
    string convert(string s, int numRows) {
        // Check if numRows is not greater than or equal to the length of string s or if numRows is 1
        if (numRows >= s.size() || numRows == 1)
            return s;

        // Create an array of strings to store characters in each row
        string str[numRows], ans;

        // Initialize variables: a for the current row, b for direction (up or down)
        int a = 0;
        bool b = false;

        // Iterate through each character in string s
        for (int i = 0; i < s.size(); i++) {
            // Add the current character to the corresponding row
            str[a] += s[i];

            // Update direction based on current row
            if (a == 0)
                b = false;
            if (a == numRows - 1)
                b = true;

            // Update the current row based on the direction
            if (b == true)
                a--;
            else 
                a++;
        }

        // Concatenate characters from each row to form the final result
        for (int i = 0; i < numRows; i++)
            ans += str[i];

        return ans;
    }
};
