class Solution {
public:
    const map<int, string, std::greater<>> div2letter = {{1,"I"}, {4,"IV"}, {9,"IX"}, {500,"D"}, {100, "C"}, {50, "L"}, {10, "X"}, {5, "V"},{900, "CM"}, {400, "CD"}, {90, "XC"}, {40, "XL"}, {1000, "M"}};
    string intToRoman(int num) { 
        string reschar;
        for (const auto& d : div2letter)
        {
            const auto divisor = d.first;
            while(num / divisor > 0)
            {
                const auto roman = div2letter.at(divisor);
                reschar.append(roman);
                num -= divisor;
            }
        }
        
        return reschar;
        
    }
};
