#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum State {BORDER, VALUE};

void getColumns(std::vector<std::string> &columns, int &col_num) {
    State state = BORDER;
    char ch;
    std::string buffer;

    std::cin.get(ch);
    if (ch != '|') {
        return;
    }

    while (true) {
        switch (state) {
            case BORDER:
                if (std::cin.peek() == '\n') {
                    return;
                }
                state = VALUE;
                break;

            case VALUE:
                while (std::cin.get(ch)) {
                    if (ch != '|') {
                        buffer += ch;
                    }
                    else {
                        col_num++;
                        columns.push_back(buffer);
                        buffer.clear();
                        state = BORDER;
                        break;
                    }
                }
        }
    }
}

void getValue(std::vector<std::string> &columns) {
    State state = BORDER;
    char ch;
    std::string buffer;

    std::cin.get(ch);
    if (ch != '|') {
        printf("RET\n");
        return;
    }

    while (true) {
        switch (state) {
            case BORDER:
                if (std::cin.peek() == '\n') {
                    return;
                }
                state = VALUE;
                break;

            case VALUE:
                while (std::cin.get(ch)) {
                    if (ch != '|') {
                        buffer += ch;
                    }
                    else {
                        columns.push_back(buffer);
                        buffer.clear();
                        state = BORDER;
                        break;
                    }
                }
        }
    }
}

void printTextTable(const std::vector<std::vector<std::string>> table, int col_num) {
    std::vector<std::size_t> max_length(col_num, 0);
    for (int r = 0; r < table.size(); r++) {
        for (int c = 0; c < col_num; c++) {
            max_length[c] = std::max(max_length[c], table[r][c].size());
        }
    }

    std::string split_row = "+";
    for (const auto& length : max_length) {
        split_row += std::string(length + 2, '-') + "+";
    }

    for (const auto& cols : table) {
        std::cout << split_row << std::endl;
        for (int c = 0; c < col_num; c++) {
            std::string v = cols[c];
            size_t num_space = max_length[c] - v.size() + 2;
            while (c + 1 < col_num && cols[c + 1].size() == 0) {
                c++;
                num_space += max_length[c] + 3;
            }
            std::cout << '|' << std::string(num_space / 2, ' ') + v + std::string(num_space % 2 == 0 ? num_space / 2 : num_space / 2 + 1 , ' ');
        }
        std::cout << '|' << std::endl;
    }
    std::cout << split_row << std::endl;
}

int main() {
    std::vector<std::vector<std::string>> table;
    table.push_back(std::vector<std::string>());
    int col_num = 0;

    getColumns(table[0], col_num);
    
    int row_num = 0;
    while (std::cin.peek() == '\n') {
        std::cin.get();
        if (std::cin.peek() != '|') {
            break;
        }
        row_num++;
        table.push_back(std::vector<std::string>());
        getValue(table[row_num]);
    }

    printTextTable(table, col_num);

    return 0;
}
