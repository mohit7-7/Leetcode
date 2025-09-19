class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows, vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int row= stoi(cell.substr(1))-1;
        int col= cell[0]-'A';
        sheet[row][col]= value;
    }
    
    void resetCell(string cell) {
        int row= stoi(cell.substr(1))-1;
        int col= cell[0]-'A';
        sheet[row][col]= 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        auto getTokenValue = [&](string token) {
            if (isdigit(token[0])) {
                return stoi(token);
            } else {
                int row = stoi(token.substr(1)) - 1;
                int col = token[0] - 'A';
                return sheet[row][col];
            }
        };
        return getTokenValue(left) + getTokenValue(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */